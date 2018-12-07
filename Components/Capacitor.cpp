/** @file */
#include "Capacitor.hpp"

/**
 * Constructor for Capacitor with a start value.
 * <p>
 * Creates a Capacitor with a specific value.
 * </p>
 *
 * @param   value      The start value.
 */
Capacitor::Capacitor(double value)
{
    setValue(value);
}

std::unique_ptr<Capacitor> operator&& (
    std::shared_ptr<Capacitor> const Component1,
    std::shared_ptr<Capacitor> const Component2)
{
    return std::make_unique<Capacitor>( 
        1 / (1/Component1->getValue() + 1/Component2->getValue()) );
}

std::unique_ptr<Capacitor> operator|| (
    std::shared_ptr<Capacitor> const Component1,
    std::shared_ptr<Capacitor> const Component2)
{
    return std::make_unique<Capacitor>( 
        Component1->getValue() 
        + Component2->getValue() );
}

bool operator== (
    std::shared_ptr<Capacitor> const Component1,
    std::shared_ptr<Capacitor> const Component2)
{
    return Component1->getValue() == Component2->getValue();
}

bool operator!= (
    std::shared_ptr<Capacitor> const Component1,
    std::shared_ptr<Capacitor> const Component2)
{
    return Component1->getValue() != Component2->getValue();
}

Capacitor operator&& ( Capacitor const Component1, Capacitor const Component2)
{
    return Capacitor( 1 / (1/Component1.getValue() + 1/Component2.getValue()));
}

Capacitor operator|| ( Capacitor const Component1, Capacitor const Component2)
{
    return Capacitor( Component1.getValue() + Component2.getValue() );
}

bool operator== ( Capacitor const Component1, Capacitor const Component2)
{
    return Component1.getValue() == Component2.getValue();
}

bool operator!= ( Capacitor const Component1, Capacitor const Component2)
{
    return Component1.getValue() != Component2.getValue();
}

/**
 * Operator for dividing two Capacitors.
 * <p>
 * Returns the divided size of the first Capacitor by the second one.
 * </p>
 *
 * @param   Component1      First Capacitor with value.
 * @param   Component2      Second Capacitor with value.
 * 
 * @return  Value of the result.
 */
double operator/ (
    std::shared_ptr<Capacitor> const Component1,
    std::shared_ptr<Capacitor> const Component2)
{
    return Component1->getValue() / Component2->getValue();
}

double operator/ (
    Capacitor const Component1,
    Capacitor const Component2)
{
    return Component1.getValue() / Component2.getValue();
}

