#include <gtest/gtest.h>
#include <top/component.h>
#include <top/resistor.h>
#include <top/nmos.h>


TEST(TopologyAPI, Component)
{
	EXPECT_EQ(Component("type1", "id1").get_type(), "type1");
	EXPECT_EQ(Component("type1", "id1").get_id(), "id1");
	EXPECT_EQ(Component("type2", "id2").get_type(), "type2");
	EXPECT_EQ(Component("type2", "id2").get_id(), "id2");
	EXPECT_ANY_THROW(Component("type2", "id2").set_net("non_existing_net", "value"));
	EXPECT_ANY_THROW(Component("type2", "id2").get_net("non_existing_net"));
}

TEST(TopologyAPI, Resistor)
{
	Resistor res = Resistor("id1", { 50, 0, 1e3 }, "v0", "v1");

	EXPECT_EQ(res.get_type(), "res");
	EXPECT_EQ(res.get_id(), "id1");
	EXPECT_DOUBLE_EQ(res.get_resistance().default_value, 50);
	EXPECT_DOUBLE_EQ(res.get_resistance().minimum, 0);
	EXPECT_DOUBLE_EQ(res.get_resistance().maximum, 1e3);
	EXPECT_EQ(res.get_t1_net(), "v0");
	EXPECT_EQ(res.get_t2_net(), "v1");
}

TEST(TopologyAPI, NMOS)
{
	NMOS nmos = NMOS("id1", { 1.5, 1, 2 }, "v0", "v1", "v2");

	EXPECT_EQ(nmos.get_type(), "nmos");
	EXPECT_EQ(nmos.get_id(), "id1");
	EXPECT_DOUBLE_EQ(nmos.get_m1().default_value, 1.5);
	EXPECT_DOUBLE_EQ(nmos.get_m1().minimum, 1);
	EXPECT_DOUBLE_EQ(nmos.get_m1().maximum, 2);
	EXPECT_EQ(nmos.get_drain_net(), "v0");
	EXPECT_EQ(nmos.get_gate_net(), "v1");
	EXPECT_EQ(nmos.get_source_net(), "v2");
}

