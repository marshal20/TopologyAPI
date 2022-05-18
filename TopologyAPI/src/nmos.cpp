#include <top/nmos.h>


NMOS::NMOS(const std::string & id, const ComponentValue & m1, const std::string & drain, const std::string & gate, const std::string & source)
	: Component("nmos", id)
{
	m_ml = m1;
	add_net("drain", drain);
	add_net("gate", gate);
	add_net("source", source);
}

NMOS::~NMOS()
{

}


void NMOS::set_ml(const ComponentValue & m1)
{
	m_ml = m1;
}

void NMOS::set_drain_net(const std::string & net_value)
{
	set_net("drain", net_value);
}

void NMOS::set_gate_net(const std::string & net_value)
{
	set_net("gate", net_value);
}

void NMOS::set_source_net(const std::string & net_value)
{
	set_net("source", net_value);
}


ComponentValue NMOS::get_ml() const
{
	return m_ml;
}

std::string NMOS::get_drain_net() const
{
	return get_net("drain");
}

std::string NMOS::get_gate_net() const
{
	return get_net("gate");
}

std::string NMOS::get_source_net() const
{
	return get_net("source");
}
