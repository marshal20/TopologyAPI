# TopologyAPI Documentations

## Overview
TopologyAPI is an library that provides an API to load topologies from a JSON,
 it is designed using a straight forward object oriented design (OOP).\
it consists of 3 main classes, Component, Topology and Topology manager, 
 we also have Resistor and NMOS classes which inherit from the Component base class 
 to add their custom values and to implement it's own behaviour , we will discuss each class separately later.

## General Use Case
Here is a basic example on how to use the library on an API level, it's very simple and straigt forward.
```CPP
TopologyManager topmgr;

// Load topologies to memory
topmgr.load_topology_from_json("topology_1.json");
topmgr.load_topology_from_json("topology_2.json");
topmgr.load_topology_from_json("topology_3.json");
topmgr.load_topology_from_json("topology_4.json");

// Save topology to json
topmgr.save_topology_to_json("topology_4_backup.json", "topology_4");

// Query topologies
for (std::shared_ptr<Toplogy> topology : topmgr.get_toplogies())
{
    /* DO SOMETHING WITH EACH TOPOLOGY */
}

// Delete topology
topmgr.delete_topology("topology_4");

// Query a topology by ID
std::shared_ptr<Toplogy> topology_2 = topmgr.get_toplogy("topology_4");

// Query devices
for (std::shared_ptr<Component> component : topology_2.get_components())
{
    /* DO SOMETHING WITH EACH COMPONENT */
}

// Query devices with netlist node
for (std::shared_ptr<Component> component : topology_2.get_components("VDD"))
{
    /* DO SOMETHING WITH EACH COMPONENT CONNECTED TO VDD */
}

```

