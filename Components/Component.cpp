#include "Component.hpp"

double Component::getValue() const
{
    return m_value; 
}

void Component::setValue(double value) 
{
    m_value = value;
}