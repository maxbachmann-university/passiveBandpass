#ifndef RCLOWPASS_HPP
#define RCLOWPASS_HPP

#include "LowPass.hpp"

class RCLowPass: public LowPass {
public:
  double Frequency() const override {
      return 1 / ( 2 * PI * m_firstComponent->returnValue() * m_secondComponent->returnValue() );
  }

  RCLowPass(double firstComponent, double secondComponent) : LowPass() {
      m_firstComponent = std::make_unique<Resistor>(firstComponent);
      m_secondComponent = std::make_unique<Capacitor>(secondComponent);
  }

};
#endif //RCLOWPASS_HPP