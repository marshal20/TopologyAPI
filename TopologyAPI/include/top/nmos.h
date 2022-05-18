#pragma once
#include "component.h"
#include "component_value.h"


class NMOS : public Component
{
public:
	NMOS(const std::string& id, const ComponentValue& m1, const std::string& drain, const std::string& gate, const std::string& source);
	virtual ~NMOS();

	void set_ml(const ComponentValue& ml);
	void set_drain_net(const std::string& net_value);
	void set_gate_net(const std::string& net_value);
	void set_source_net(const std::string& net_value);

	ComponentValue get_ml() const;
	std::string get_drain_net() const;
	std::string get_gate_net() const;
	std::string get_source_net() const;

private:
	ComponentValue m_ml;
};
