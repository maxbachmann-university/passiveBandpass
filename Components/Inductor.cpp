#include "Inductor.hpp"

Inductor::Inductor(double value) : Component(value) {}

/*std::unique_ptr<Inductor> operator+ (
    std::shared_ptr<Inductor> const Component1,
    std::shared_ptr<Inductor> const Component2)
{
    return std::make_unique<Inductor>( 
        Component1->returnValue() 
        + Component2->returnValue() );
}

std::unique_ptr<Inductor> operator- (
    std::shared_ptr<Inductor> const Component1,
    std::shared_ptr<Inductor> const Component2)
{
    return std::make_unique<Inductor>( 
        Component1->returnValue() 
        - Component2->returnValue() );
}

double operator/ (
    std::shared_ptr<Inductor> const Component1,
    std::shared_ptr<Inductor> const Component2)
{
    return Component1->returnValue() / Component2->returnValue();
}*/