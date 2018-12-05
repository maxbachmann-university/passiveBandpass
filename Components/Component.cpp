/** @file */
#include "Component.hpp"

/**
 * Returns the value of Component.
 *
 * @return   The value of a Component.
 */
double Component::getValue() const
{
    return m_value; 
}

/**
 * Sets the value of Component.
 *
 * @param   value      The start value.
 */
void Component::setValue(double value) 
{
    m_value = value;
}