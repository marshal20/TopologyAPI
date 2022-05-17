#include <top/component.h>
#include <gtest/gtest.h>


TEST(TopologyAPI, Component)
{
	EXPECT_EQ(Component("type1", "id1").get_type(), "type1");
	EXPECT_EQ(Component("type1", "id1").get_id(), "id1");
	EXPECT_EQ(Component("type2", "id2").get_type(), "type2");
	EXPECT_EQ(Component("type2", "id2").get_id(), "id2");
}

