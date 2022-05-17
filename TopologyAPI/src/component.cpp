#include <top/component.h>

Component::Component(const std::string& type, const std::string& id)
{
	m_type = type;
	m_id = id;
}

Component::~Component()
{

}


std::string Component::get_type() const
{
	return m_type;
}

std::string Component::get_id() const
{
	return m_id;
}

