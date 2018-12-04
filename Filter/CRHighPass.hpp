#include "HighPass.hpp"

#ifndef CRHIGHPASS_HPP
#define CRHIGHPASS_HPP

class CRHighPass: public HighPass {
public:
  double Frequency() const override {
      return m_secondComponent->returnValue() / ( 2 * PI * m_firstComponent->returnValue() );
  }

  CRHighPass(double firstComponent, double secondComponent) : HighPass() {
      m_firstComponent = std::make_unique<Capacitor>(firstComponent);
      m_secondComponent = std::make_unique<Resistor>(secondComponent);
  }
};
#endif //CRHIGHPASS_HPP