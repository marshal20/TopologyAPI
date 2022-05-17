#include <top/resistor.h>


Resistor::Resistor(const std::string& id, const ComponentValue& resistance, const std::string& t1, const std::string& t2)
	: Component("res", id)
{
	m_resistance = resistance;
	add_net("t1", t1);
	add_net("t2", t2);
}

Resistor::~Resistor()
{

}


void Resistor::set_resistance(const ComponentValue& resistance)
{
	m_resistance = resistance;
}

void Resistor::set_t1_net(const std::string& net_value)
{
	set_net("t1", net_value);
}

void Resistor::set_t2_net(const std::string& net_value)
{
	set_net("t2", net_value);
}


ComponentValue Resistor::get_resistance() const
{
	return m_resistance;
}

std::string Resistor::get_t1_net() const
{
	return get_net("t1");
}

std::string Resistor::get_t2_net() const
{
	return get_net("t2");
}

