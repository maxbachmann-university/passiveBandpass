#include "HighPass.hpp"

#ifndef CLHIGHPASS_HPP
#define CLHIGHPASS_HPP

class CLHighPass: public HighPass {
public:
  double Frequency() const override {
      return m_secondComponent->returnValue() / ( 2 * PI * m_firstComponent->returnValue() );
  }

  CLHighPass(double firstComponent, double secondComponent) : HighPass() {
      m_firstComponent = std::make_unique<Capacitor>(firstComponent);
      m_secondComponent = std::make_unique<Inductor>(secondComponent);
  }
};
#endif //RLHIGHPASS_HPP