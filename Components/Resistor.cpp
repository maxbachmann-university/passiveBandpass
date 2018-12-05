#include "Resistor.hpp"

Resistor::Resistor(double value)
{
    setValue(value);
}

std::unique_ptr<Resistor> operator+ (
    std::shared_ptr<Resistor> const Component1,
    std::shared_ptr<Resistor> const Component2)
{
    return std::make_unique<Resistor>( 
        Component1->getValue() 
        + Component2->getValue() );
}

std::unique_ptr<Resistor> operator- (
    std::shared_ptr<Resistor> const Component1,
    std::shared_ptr<Resistor> const Component2)
{
    return std::make_unique<Resistor>( 
        Component1->getValue()
        - Component2->getValue() );
}

double operator/ (
    std::shared_ptr<Resistor> const Component1,
    std::shared_ptr<Resistor> const Component2)
{
    return Component1->getValue() / Component2->getValue();
}