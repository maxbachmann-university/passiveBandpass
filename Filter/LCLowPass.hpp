#ifndef LCLOWPASS_HPP
#define LCLOWPASS_HPP

#include "PassFilter.hpp"

class LCLowPass: public PassFilter 
{
public:
  double Frequency() const override;

  LCLowPass(double firstComponent, double secondComponent);

};
#endif //LCLOWPASS_HPP

