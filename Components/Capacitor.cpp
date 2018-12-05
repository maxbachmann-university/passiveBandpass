#include "Capacitor.hpp"

Capacitor::Capacitor(double value) : Component(value) {}

/*std::unique_ptr<Capacitor> operator+ (
    std::shared_ptr<Capacitor> const Component1,
    std::shared_ptr<Capacitor> const Component2)
{
    return std::make_unique<Capacitor>( 
        Component1->returnValue() 
        + Component2->returnValue() );
}

std::unique_ptr<Capacitor> operator- (
    std::shared_ptr<Capacitor> const Component1,
    std::shared_ptr<Capacitor> const Component2)
{
    return std::make_unique<Capacitor>( 
        Component1->returnValue() 
        - Component2->returnValue() );
}

double operator/ (
    std::shared_ptr<Capacitor> const Component1,
    std::shared_ptr<Capacitor> const Component2)
{
    return Component1->returnValue() / Component2->returnValue();
}*/