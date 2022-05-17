#include <gtest/gtest.h>
#include <top/topology.h>
#include <top/component.h>
#include <top/resistor.h>
#include <top/nmos.h>


TEST(TopologyAPI, Topology)
{
	Topology top = Topology("top_id1");

	// add components
	top.add_component(std::shared_ptr<Resistor>(new Resistor("R1", { 50, 0, 150 }, "VO", "GND")));
	top.add_component(std::shared_ptr<NMOS>(new NMOS("U1", { 1.5, 1, 2 }, "VDD", "VIN", "VO")));
	top.add_component(std::shared_ptr<Resistor>(new Resistor("R2", { 1.5e6, 0, 1e9 }, "VIN", "GND")));

	EXPECT_EQ(top.get_id(), "top_id1");
	EXPECT_EQ(top.get_components().size(), 3);
	EXPECT_EQ(top.get_components_with_netlist("VDD").size(), 1);
	EXPECT_EQ(top.get_components_with_netlist("GND").size(), 2);
	EXPECT_EQ(top.get_components_with_netlist("VO").size(), 2);
	EXPECT_EQ(top.get_components_with_netlist("VIN").size(), 2);
	EXPECT_EQ(top.get_component_with_id("R2")->get_id(), "R2");
	EXPECT_NO_THROW(top.get_component_with_id("U1"));
	EXPECT_ANY_THROW(top.get_component_with_id("U2"));

}

