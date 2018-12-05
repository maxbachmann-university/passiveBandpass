#include "Inductor.hpp"

Inductor::Inductor(double value) 
{
    setValue(value);
}

std::unique_ptr<Inductor> operator+ (
    std::shared_ptr<Inductor> const Component1,
    std::shared_ptr<Inductor> const Component2)
{
    return std::make_unique<Inductor>( 
        Component1->getValue() 
        + Component2->getValue() );
}

std::unique_ptr<Inductor> operator- (
    std::shared_ptr<Inductor> const Component1,
    std::shared_ptr<Inductor> const Component2)
{
    return std::make_unique<Inductor>( 
        Component1->getValue() 
        - Component2->getValue() );
}

double operator/ (
    std::shared_ptr<Inductor> const Component1,
    std::shared_ptr<Inductor> const Component2)
{
    return Component1->getValue() / Component2->getValue();
}