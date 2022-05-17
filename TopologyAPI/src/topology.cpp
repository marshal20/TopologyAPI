#include "top/topology.h"
#include <stdexcept>


Topology::Topology(const std::string & id, const std::vector<std::shared_ptr<Component>>& components)
{
	m_id = id;
	m_components = components;
}

Topology::~Topology()
{

}


void Topology::set_id(const std::string& id)
{
	m_id = id;
}

void Topology::add_component(std::shared_ptr<Component> component)
{
	m_components.push_back(component);
}

void Topology::remove_component(const std::string& component_id)
{
	for (size_t i = 0; i < m_components.size(); i++)
	{
		if (m_components[i]->get_id() == component_id)
		{
			// remove the component then return
			m_components.erase(m_components.begin() + i);
			return;
		}
	}

	throw std::runtime_error("Couldn't find \"" + component_id + "\" component in \"" + m_id + "\" topology");
}


std::string Topology::get_id() const
{
	return m_id;
}

std::vector<std::shared_ptr<Component>> Topology::get_components()
{
	return m_components;
}

std::vector<std::shared_ptr<Component>> Topology::get_components_with_netlist(const std::string & net_name)
{
	std::vector<std::shared_ptr<Component>> found_components;

	for (const std::shared_ptr<Component>& component : m_components)
	{
		for (auto netlist_pair : component->get_netlist())
		{
			if (netlist_pair.second == net_name)
			{
				found_components.push_back(component);
			}
		}
	}

	return found_components;
}

std::shared_ptr<Component> Topology::get_component_with_id(const std::string& id)
{
	for (std::shared_ptr<Component>& component : m_components)
	{
		if (component->get_id() == id)
		{
			return component;
		}
	}

	throw std::runtime_error("Couldn't find \"" + id + "\" component in \"" + m_id + "\" topology");
}

