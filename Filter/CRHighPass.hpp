#ifndef CRHIGHPASS_HPP
#define CRHIGHPASS_HPP

#include "HighPass.hpp"

class CRHighPass: public HighPass {
public:
  double Frequency() const override {
      return 1 / ( 2 * PI * m_firstComponent->returnValue() * m_secondComponent->returnValue() );
  }

  CRHighPass(double firstComponent, double secondComponent) : HighPass() {
      m_firstComponent = std::make_unique<Capacitor>(firstComponent);
      m_secondComponent = std::make_unique<Resistor>(secondComponent);
  }
};
#endif //CRHIGHPASS_HPP