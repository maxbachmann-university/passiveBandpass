#include "LCLowPass.hpp"

LCLowPass::LCLowPass(double firstComponent, double secondComponent)
    : LowPass() 
{
    m_firstComponent = std::make_unique<Inductor>(firstComponent);
    m_secondComponent = std::make_unique<Capacitor>(secondComponent);
}

double LCLowPass::Frequency() const
{
    return 1 / ( 2 * PI * sqrt(m_firstComponent->getValue()
      * m_secondComponent->getValue()));
}

