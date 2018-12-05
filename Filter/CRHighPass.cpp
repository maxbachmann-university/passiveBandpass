#include "CRHighPass.hpp"

CRHighPass::CRHighPass(
    double firstComponent,
    double secondComponent) 
{
    m_firstComponent = std::make_unique<Capacitor>(firstComponent);
    m_secondComponent = std::make_unique<Resistor>(secondComponent);
}

double CRHighPass::Frequency() const
{
    return 1 / ( 2 * PI * m_firstComponent->getValue() 
      * m_secondComponent->getValue() );
}

  