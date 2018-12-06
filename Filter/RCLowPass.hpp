#ifndef RCLOWPASS_HPP
#define RCLOWPASS_HPP

#include "LowPass.hpp"

class RCLowPass: public LowPass 
{
public:
  double Frequency() const override;

  RCLowPass(double firstComponent, double secondComponent);

};
#endif //RCLOWPASS_HPP

