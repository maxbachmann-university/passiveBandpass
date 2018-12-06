#include "RLHighPass.hpp"

RLHighPass::RLHighPass(double firstComponent, double secondComponent) 
    : HighPass() 
{
    m_firstComponent = std::make_unique<Resistor>(firstComponent);
    m_secondComponent = std::make_unique<Inductor>(secondComponent);
}

double RLHighPass::Frequency() const 
{
    return m_firstComponent->getValue() 
        / ( 2 * PI * m_secondComponent->getValue() );
}

