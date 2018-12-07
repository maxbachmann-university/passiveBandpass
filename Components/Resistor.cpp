/** @file */
#include "Resistor.hpp"

/**
 * Constructor for Resistor with a start value.
 * <p>
 * Creates a Resistor with a specific value.
 * </p>
 *
 * @param   value      The start value.
 */
Resistor::Resistor(double value)
{
    setValue(value);
}

std::unique_ptr<Resistor> operator&& (
    std::shared_ptr<Resistor> const Component1,
    std::shared_ptr<Resistor> const Component2)
{
    return std::make_unique<Resistor>( 
        Component1->getValue() 
        + Component2->getValue() );
}

std::unique_ptr<Resistor> operator|| (
    std::shared_ptr<Resistor> const Component1,
    std::shared_ptr<Resistor> const Component2)
{
    return std::make_unique<Resistor>( 
        1 / (1/Component1->getValue() + 1/Component2->getValue()) );
}

bool operator== (
    std::shared_ptr<Resistor> const Component1,
    std::shared_ptr<Resistor> const Component2)
{
    return Component1->getValue() == Component2->getValue();
}

bool operator!= (
    std::shared_ptr<Resistor> const Component1,
    std::shared_ptr<Resistor> const Component2)
{
    return Component1->getValue() != Component2->getValue();
}

Resistor operator&& ( Resistor const Component1, Resistor const Component2)
{
    return Resistor( Component1.getValue() + Component2.getValue() );
}

Resistor operator|| ( Resistor const Component1, Resistor const Component2)
{
    return Resistor( 1 / (1/Component1.getValue() + 1/Component2.getValue()));
}

bool operator== ( Resistor const Component1, Resistor const Component2)
{
    return Component1.getValue() == Component2.getValue();
}

bool operator!= ( Resistor const Component1, Resistor const Component2)
{
    return Component1.getValue() != Component2.getValue();
}

/**
 * Operator for dividing two Resistors.
 * <p>
 * Returns the divided size of the first Resistor by the second one.
 * </p>
 *
 * @param   Component1      First Resistor with value.
 * @param   Component2      Second Resistor with value.
 * 
 * @return  Value of the result.
 */
double operator/ (
    std::shared_ptr<Resistor> const Component1,
    std::shared_ptr<Resistor> const Component2)
{
    return Component1->getValue() / Component2->getValue();
}

double operator/ (
    Resistor const Component1,
    Resistor const Component2)
{
    return Component1.getValue() / Component2.getValue();
}

