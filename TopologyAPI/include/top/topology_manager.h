#pragma once
#include <vector>
#include <string>
#include <memory>
#include "topology.h"


class TopologyManager
{
public:
	TopologyManager();
	~TopologyManager();

	std::string load_topology_from_json(const std::string& file_name); // loads topology and returns it's id
	void save_topology_to_json(const std::string& file_name, const std::string& topology_id);

	void delete_topology(const std::string& topology_id);
	std::shared_ptr<Topology> get_toplogy(const std::string& topology_id);
	std::vector<std::shared_ptr<Topology>> get_toplogies();

private:
	std::vector<std::shared_ptr<Topology>> m_topologies;

};

