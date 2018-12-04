#ifndef LCLOWPASS_HPP
#define LCLOWPASS_HPP

#include "LowPass.hpp"

class LCLowPass: public LowPass {
public:
  virtual double Frequency() const override {
      return 1 / ( 2 * PI * sqrt(m_firstComponent->returnValue() * m_secondComponent->returnValue()));
  }
  LCLowPass(double firstComponent, double secondComponent) : LowPass() {
      m_firstComponent = std::make_unique<Inductor>(firstComponent);
      m_secondComponent = std::make_unique<Capacitor>(secondComponent);
  }

};
#endif //LCLOWPASS_HPP