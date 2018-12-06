#include "RCLowPass.hpp"

RCLowPass::RCLowPass(double firstComponent, double secondComponent) 
    : PassFilter(FilterType::LowPass) 
{
    m_firstComponent = std::make_unique<Resistor>(firstComponent);
    m_secondComponent = std::make_unique<Capacitor>(secondComponent);
}

double RCLowPass::Frequency() const 
{
    return 1 / ( 2 * PI * m_firstComponent->getValue() 
        * m_secondComponent->getValue() );
}

