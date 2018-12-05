#include "CLHighPass.hpp"

CLHighPass::CLHighPass(
    double firstComponent,
    double secondComponent)
    : HighPass() 
{
    m_firstComponent = std::make_unique<Capacitor>(firstComponent);
    m_secondComponent = std::make_unique<Inductor>(secondComponent);
}

double CLHighPass::Frequency() const 
{
    return m_secondComponent->returnValue() 
      / (2 * PI * m_firstComponent->returnValue());
}

  