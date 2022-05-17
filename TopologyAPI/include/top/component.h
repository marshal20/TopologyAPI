#pragma once
#include <string>
#include <map>


class Component
{
public:
	Component(const std::string& type, const std::string& id);
	virtual ~Component();

	void set_id(const std::string& id);
	void add_net(const std::string& net_name, const std::string& net_value); // adds a new net, or sets the value if it already exists
	void set_net(const std::string& net_name, const std::string& net_value); // sets an already existing net

	std::string get_type() const;
	std::string get_id() const;
	std::string get_net(const std::string& net_name) const;
	std::map<std::string, std::string> get_netlist() const;

private:
	std::string m_type; // doesn't make sense to have a set_type function
	std::string m_id;
	std::map<std::string, std::string> m_netlist; // hashmap that holds netlist name value pair
};
