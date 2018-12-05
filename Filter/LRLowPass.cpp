#include "LRLowPass.hpp"

LRLowPass::LRLowPass(double firstComponent, double secondComponent) 
    : LowPass()
{
    m_firstComponent = std::make_unique<Inductor>(firstComponent);
    m_secondComponent = std::make_unique<Resistor>(secondComponent);
}

double LRLowPass::Frequency() const 
{
    return m_secondComponent->returnValue() 
        / ( 2 * PI * m_firstComponent->returnValue() );
}

  