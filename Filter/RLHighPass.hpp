#include "HighPass.hpp"

#ifndef RLHIGHPASS_HPP
#define RLHIGHPASS_HPP

class RLHighPass: public HighPass {
public:
  double Frequency() const override {
      return m_secondComponent->returnValue() / ( 2 * PI * m_firstComponent->returnValue() );
  }

  RLHighPass(double firstComponent, double secondComponent) : HighPass() {
      m_firstComponent = std::make_unique<Resistor>(firstComponent);
      m_secondComponent = std::make_unique<Inductor>(secondComponent);
  }
};
#endif //RLHIGHPASS_HPP