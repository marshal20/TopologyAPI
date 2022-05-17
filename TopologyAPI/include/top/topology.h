#pragma once
#include <string>
#include <vector>
#include <memory>
#include "component.h"


class Topology
{
public:
	Topology(const std::string& id, const std::vector<std::shared_ptr<Component>>& components = {});
	~Topology();

	void set_id(const std::string& id);
	void add_component(std::shared_ptr<Component> component);
	void remove_component(const std::string& component_id);

	std::string get_id() const;
	std::vector<std::shared_ptr<Component>> get_components();
	std::vector<std::shared_ptr<Component>> get_components_with_netlist(const std::string& net_name);
	std::shared_ptr<Component> get_component_with_id(const std::string& id);

private:
	std::string m_id;
	std::vector<std::shared_ptr<Component>> m_components;

};
