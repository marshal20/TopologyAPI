# TopologyAPI Documentations


` ` \
` `


## Overview
TopologyAPI is an library that provides an API to load topologies from a JSON,
 it is designed using a straight forward object oriented design (OOP).\
it consists of 3 main classes, Component, Topology and Topology manager, 
 we also have Resistor and NMOS classes which inherit from the Component base class 
 to add their custom values and to implement it's own behaviour , we will discuss each class separately later.


` ` \
` `


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


` ` \
` `


## Component Class
The main class which represent a component (device) in the **topology**,
 it contains the **ID**, **type** and netlists of the component.\
It's the base class from which every component inherits.
Inherited classes: **Resistor** and **NMOS**

` ` \
` `
```CPP
    Component(const std::string& type, const std::string& id);
```
Constructor: takes the type and the id of the component.

` ` \
` `

```CPP
	void set_id(const std::string& id);
```
Sets the ID of the component to (id).

` ` \
` `

```CPP
	void add_net(const std::string& net_id, const std::string& net_value);
```
Adds a new netlist node, or sets the value if it already exists.

` ` \
` `

```CPP
	void set_net(const std::string& net_id, const std::string& net_value);
```
Rets an already existing netlist node.

` ` \
` `

```CPP
	std::string get_type() const;
```
Returns the type of the component.

` ` \
` `

```CPP
	std::string get_id() const;
```
Returns the ID of the component.

` ` \
` `

```CPP
	std::string get_net(const std::string& net_id) const;
```
Returns the netlist node by ID.

` ` \
` `

```CPP
	std::map<std::string, std::string> get_netlist() const;
```
Returns all the netlists of the component.

` ` \
` `


## Topology Class
It's the class which represents a topology, it contains the components and has an ID.

` ` \
` `

```CPP
    Topology(const std::string& id, const std::vector<std::shared_ptr<Component>>& components = {});
```
Constructor: takes the is and the components for the topology.

` ` \
` `

```CPP
    void set_id(const std::string& id);
```
Sets the id of the topology to (id).

` ` \
` `

```CPP
	void add_component(std::shared_ptr<Component> component);
```
Adds a component to the topology.

` ` \
` `

```CPP
	void remove_component(const std::string& component_id);
```
Removes a component from the topology.

` ` \
` `

```CPP
	std::string get_id() const;
```
Returns the ID of the topology.

` ` \
` `

```CPP
	std::vector<std::shared_ptr<Component>> get_components();
```
Returns a list of all the components in the topology.

` ` \
` `

```CPP
	std::vector<std::shared_ptr<Component>> get_components_with_netlist(const std::string& net_name);
```
Returns a list of all the components which are connected to a netlist node in the topology.

` ` \
` `

```CPP
	std::shared_ptr<Component> get_component_with_id(const std::string& id);
```
Returns the component which has the id (id) in the topology.

` ` \
` `


## TopologyManager
The class which manages and contains all the topologies in the memory.

` ` \
` `

```CPP
    std::string load_topology_from_json(const std::string& file_name);
```
Loads a topology located at (file_name) into memory and returns it's id.

` ` \
` `

```CPP
    void save_topology_to_json(const std::string& file_name, const std::string& topology_id);
```
Saves a topology of id (topology_id) into a JSON file located at (file_name).

` ` \
` `

```CPP
	void delete_topology(const std::string& topology_id);
```
Deletes a topology of id (topology_id) from memory.

` ` \
` `

```CPP
	std::shared_ptr<Topology> get_toplogy(const std::string& topology_id);
```
Returns the topology of id (topology_id) which is stored in memory.

` ` \
` `

```CPP
	std::vector<std::shared_ptr<Topology>> get_toplogies();
```
Returns a list of all the topologies currently loaded in memory.


