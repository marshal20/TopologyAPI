#pragma once
#include "component.h"
#include "component_value.h"


class Resistor : public Component
{
public:
	Resistor(const std::string& id, const ComponentValue& resistance, const std::string& t1, const std::string& t2);
	virtual ~Resistor();

	void set_resistance(const ComponentValue& resistance);
	void set_t1_net(const std::string& net_value);
	void set_t2_net(const std::string& net_value);

	ComponentValue get_resistance() const;
	std::string get_t1_net() const;
	std::string get_t2_net() const;

private:
	ComponentValue m_resistance;
};
