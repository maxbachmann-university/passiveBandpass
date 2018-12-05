#ifndef LCLOWPASS_HPP
#define LCLOWPASS_HPP

#include "LowPass.hpp"

class LCLowPass: public LowPass 
{
public:
  double Frequency() const override;

  LCLowPass(double firstComponent, double secondComponent);

};
#endif //LCLOWPASS_HPP