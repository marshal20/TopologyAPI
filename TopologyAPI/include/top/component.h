#pragma once
#include <string>

class Component
{
public:
	Component(const std::string& type, const std::string& id);
	virtual ~Component();

	std::string get_type() const;
	std::string get_id() const;

private:
	std::string m_type;
	std::string m_id;

};
