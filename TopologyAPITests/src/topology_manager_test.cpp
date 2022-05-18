#include <top/topology_manager.h>
#include <gtest/gtest.h>


TEST(TopologyAPI, TopologyManager)
{
	TopologyManager topmgr;

	// load topologies into topmgr
	EXPECT_NO_THROW(topmgr.load_topology_from_json("../../../../TopologyAPITests/topologies/given_topology.json"));
	EXPECT_NO_THROW(topmgr.load_topology_from_json("../../../../TopologyAPITests/topologies/topology_1.json"));
	EXPECT_NO_THROW(topmgr.load_topology_from_json("../../../../TopologyAPITests/topologies/topology_2.json"));
	EXPECT_ANY_THROW(topmgr.load_topology_from_json("../../../../TopologyAPITests/topologies/non_existing_topology.json"));

	// check if topologies were loaded successfully
	EXPECT_EQ(topmgr.get_toplogies().size(), 3);
	EXPECT_EQ(topmgr.get_toplogy("given_topology")->get_id(), "given_topology");
	EXPECT_EQ(topmgr.get_toplogy("topology_1")->get_id(), "topology_1");
	EXPECT_EQ(topmgr.get_toplogy("topology_2")->get_id(), "topology_2");

	// check if given_topology were loaded successfully
	EXPECT_EQ(topmgr.get_toplogy("given_topology")->get_components().size(), 2);
	EXPECT_NO_THROW(topmgr.get_toplogy("given_topology")->get_component_with_id("res1"));
	EXPECT_NO_THROW(topmgr.get_toplogy("given_topology")->get_component_with_id("m1"));

	// delete the given_topology
	EXPECT_NO_THROW(topmgr.delete_topology("given_topology"));
	EXPECT_ANY_THROW(topmgr.delete_topology("non_existing_topology"));

	// save topology_1 and topology_2 topologies, delete it then load it again
	// save
	EXPECT_NO_THROW(topmgr.save_topology_to_json("./topology_1_saved.json", "topology_1"));
	EXPECT_NO_THROW(topmgr.save_topology_to_json("./topology_2_saved.json", "topology_2"));
	// delete
	EXPECT_NO_THROW(topmgr.delete_topology("topology_1"));
	EXPECT_NO_THROW(topmgr.delete_topology("topology_2"));
	EXPECT_EQ(topmgr.get_toplogies().size(), 0);
	// load again
	EXPECT_NO_THROW(topmgr.load_topology_from_json("./topology_1_saved.json"));
	EXPECT_NO_THROW(topmgr.load_topology_from_json("./topology_2_saved.json"));

	// check if the topologies were loaded
	EXPECT_EQ(topmgr.get_toplogies().size(), 2);

	// check if topology_1 were loaded successfully
	EXPECT_EQ(topmgr.get_toplogy("topology_1")->get_components().size(), 3);
	EXPECT_NO_THROW(topmgr.get_toplogy("topology_1")->get_component_with_id("R1"));
	EXPECT_NO_THROW(topmgr.get_toplogy("topology_1")->get_component_with_id("M1"));
	EXPECT_NO_THROW(topmgr.get_toplogy("topology_1")->get_component_with_id("R2"));

}

