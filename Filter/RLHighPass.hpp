#ifndef RLHIGHPASS_HPP
#define RLHIGHPASS_HPP

#include "HighPass.hpp"

class RLHighPass: public HighPass 
{
public:
  double Frequency() const override 
  {
      return m_firstComponent->returnValue() 
        / ( 2 * PI * m_secondComponent->returnValue() );
  }

  RLHighPass(double firstComponent, double secondComponent) : HighPass() 
  {
      m_firstComponent = std::make_unique<Resistor>(firstComponent);
      m_secondComponent = std::make_unique<Inductor>(secondComponent);
  }
};
#endif //RLHIGHPASS_HPP