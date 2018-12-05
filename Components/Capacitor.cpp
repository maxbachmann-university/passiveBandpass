#include "Capacitor.hpp"

Capacitor::Capacitor(double value)
{
    setValue(value);
}

std::unique_ptr<Capacitor> operator+ (
    std::shared_ptr<Capacitor> const Component1,
    std::shared_ptr<Capacitor> const Component2)
{
    return std::make_unique<Capacitor>( 
        Component1->getValue()
        + Component2->getValue()  );
}

std::unique_ptr<Capacitor> operator- (
    std::shared_ptr<Capacitor> const Component1,
    std::shared_ptr<Capacitor> const Component2)
{
    return std::make_unique<Capacitor>( 
        Component1->getValue()  
        - Component2->getValue() );
}

double operator/ (
    std::shared_ptr<Capacitor> const Component1,
    std::shared_ptr<Capacitor> const Component2)
{
    return Component1->getValue() / Component2->getValue();
}