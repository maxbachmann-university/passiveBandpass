#include "Resistor.hpp"

Resistor::Resistor(double value) : Component(value) {}

/*std::unique_ptr<Resistor> operator+ (
    std::shared_ptr<Resistor> const Component1,
    std::shared_ptr<Resistor> const Component2)
{
    return std::make_unique<Resistor>( 
        Component1->returnValue() 
        + Component2->returnValue() );
}

std::unique_ptr<Resistor> operator- (
    std::shared_ptr<Resistor> const Component1,
    std::shared_ptr<Resistor> const Component2)
{
    return std::make_unique<Resistor>( 
        Component1->returnValue() 
        - Component2->returnValue() );
}

double operator/ (
    std::shared_ptr<Resistor> const Component1,
    std::shared_ptr<Resistor> const Component2)
{
    return Component1->returnValue() / Component2->returnValue();
}*/