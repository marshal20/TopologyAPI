#include <top/topology_manager.h>
#include <top/component_value.h>
#include <top/resistor.h>
#include <top/nmos.h>
#include <stdexcept>
#include <fstream>
#include <nlohmann/json.hpp>


// alias nlohmann::json to json
using json = nlohmann::json;

static json serialize_component_value(const ComponentValue& value);
static ComponentValue deserialize_component_value(const json& value_json);


TopologyManager::TopologyManager()
{

}

TopologyManager::~TopologyManager()
{

}


std::string TopologyManager::load_topology_from_json(const std::string& file_name)
{
	// create a new topology
	std::shared_ptr<Topology> topology = std::shared_ptr<Topology>(new Topology(""));

	// parse the json file
	std::ifstream in_file(file_name);
	if (!in_file)
	{
		throw std::runtime_error("Couldn't open \"" + file_name + "\" file");
	}
	json topology_json;
	in_file >> topology_json;
	in_file.close();

	// deserialize the topology from json
	// topology id
	topology->set_id(topology_json["id"]);
	// components
	for (auto component_json : topology_json["components"])
	{
		std::shared_ptr<Component> component;
		// deserialize component values, custom for each component 
		//  (we can abstract component values in a hash map containing the name-value pair of the value)
		if (component_json["type"] == "resistor")
		{
			std::shared_ptr<Resistor> res = std::shared_ptr<Resistor>(new Resistor("", {}, "", ""));
			res->set_resistance(deserialize_component_value(component_json["resistance"]));
			component = res;
		}
		else if (component_json["type"] == "nmos")
		{
			std::shared_ptr<NMOS> nmos = std::shared_ptr<NMOS>(new NMOS("", {}, "", "", ""));
			nmos->set_ml(deserialize_component_value(component_json["m(l)"]));
			component = nmos;
		}
		else
		{
			throw std::runtime_error("Can't serialize a component of type \"" + component->get_type() + "\"");
		}
		// component id
		component->set_id(component_json["id"]);
		// component netlist
		for (auto& netlist_json : component_json["netlist"].items())
		{
			component->set_net(netlist_json.key(), netlist_json.value());
		}
		// add component to new topology
		topology->add_component(component);
	}

	// add topology to topologies list
	m_topologies.push_back(topology);
	
	return topology->get_id();
}

void TopologyManager::save_topology_to_json(const std::string& file_name, const std::string& topology_id)
{
	// find topology
	std::shared_ptr<Topology> topology = get_toplogy(topology_id);

	// serialize the topology into a json object
	json topology_json;
	topology_json["id"] = topology->get_id();
	json componenets_json;
	for (std::shared_ptr<Component> component : topology->get_components())
	{
		json componenet_json;
		// serialize component
		componenet_json["type"] = component->get_type();
		componenet_json["id"] = component->get_id();
		// serialize component values, custom for each component 
		//  (we can abstract component values in a hash map containing the name-value pair of the value)
		if (component->get_type() == "resistor")
		{
			componenet_json["resistance"] = serialize_component_value(std::dynamic_pointer_cast<Resistor>(component)->get_resistance());
		}
		else if (component->get_type() == "nmos")
		{
			componenet_json["m(l)"] = serialize_component_value(std::dynamic_pointer_cast<NMOS>(component)->get_ml());
		}
		else
		{
			throw std::runtime_error("Can't serialize a component of type \"" + component->get_type() + "\"");
		}
		// serialize netlist
		json netlist_json;
		for (auto netlist : component->get_netlist())
		{
			netlist_json[netlist.first] = netlist.second;
		}
		componenet_json["netlist"] = netlist_json;
		// add component to components
		componenets_json.push_back(componenet_json);
	}
	topology_json["components"] = componenets_json;

	// save json to a file
	std::ofstream out_file(file_name, std::ios::trunc); // trunc deletes the contents of the file
	if (!out_file)
	{
		throw std::runtime_error("Couldn't open \"" + file_name + "\" file");
	}
	out_file << topology_json.dump(4);
	out_file.close();
}


void TopologyManager::delete_topology(const std::string& topology_id)
{
	for (size_t i = 0; i < m_topologies.size(); i++)
	{
		if (m_topologies[i]->get_id() == topology_id)
		{
			// remove the component then return
			m_topologies.erase(m_topologies.begin() + i);
			return;
		}
	}

	throw std::runtime_error("Couldn't find \"" + topology_id + "\" topology");
}

std::shared_ptr<Topology> TopologyManager::get_toplogy(const std::string& topology_id)
{
	for (std::shared_ptr<Topology>& topology : m_topologies)
	{
		if (topology->get_id() == topology_id)
		{
			return topology;
		}
	}

	throw std::runtime_error("Couldn't find \"" + topology_id + "\" topology");
}

std::vector<std::shared_ptr<Topology>> TopologyManager::get_toplogies()
{
	return m_topologies;
}


static json serialize_component_value(const ComponentValue& value)
{
	json value_json;
	
	value_json["default"] = value.default_value;
	value_json["min"] = value.minimum;
	value_json["max"] = value.maximum;

	return value_json;
}

static ComponentValue deserialize_component_value(const json& value_json)
{
	return ComponentValue{ value_json["default"], value_json["min"], value_json["max"] };
}

