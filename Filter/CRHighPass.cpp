#include "CRHighPass.hpp"

CRHighPass::CRHighPass(
    double firstComponent,
    double secondComponent) 
    : HighPass() 
{
    m_firstComponent = std::make_unique<Capacitor>(firstComponent);
    m_secondComponent = std::make_unique<Resistor>(secondComponent);
}

double CRHighPass::Frequency() const
{
    return 1 / ( 2 * PI * m_firstComponent->returnValue() 
      * m_secondComponent->returnValue() );
}

  