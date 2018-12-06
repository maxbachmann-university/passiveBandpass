#ifndef RCLOWPASS_HPP
#define RCLOWPASS_HPP

#include "PassFilter.hpp"

class RCLowPass: public PassFilter 
{
public:
  double Frequency() const override;

  RCLowPass(double firstComponent, double secondComponent);

};
#endif //RCLOWPASS_HPP

