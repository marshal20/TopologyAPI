#include <top/component.h>
#include <stdexcept>


Component::Component(const std::string& type, const std::string& id)
{
	m_type = type;
	m_id = id;
}

Component::~Component()
{

}


void Component::set_id(const std::string& id)
{
	m_id = id;
}

void Component::add_net(const std::string& net_name, const std::string& net_id)
{
	m_netlist[net_name] = net_id;
}

void Component::set_net(const std::string& net_id, const std::string& net_value)
{
	auto found_pair = m_netlist.find(net_id);
	if (found_pair == m_netlist.end())
	{
		throw std::runtime_error("No net found with the id \"" + net_id + "\"");
	}

	found_pair->second = net_value;
}


std::string Component::get_type() const
{
	return m_type;
}

std::string Component::get_id() const
{
	return m_id;
}

std::string Component::get_net(const std::string& net_id) const
{
	auto found_pair = m_netlist.find(net_id);
	if (found_pair == m_netlist.end())
	{
		throw std::runtime_error("No net found with the id \"" + net_id + "\"");
	}

	return found_pair->second;
}

std::map<std::string, std::string> Component::get_netlist() const
{
	return m_netlist;
}

