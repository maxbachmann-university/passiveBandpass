#ifndef LRLOWPASS_HPP
#define LRLOWPASS_HPP

#include "LowPass.hpp"

class LRLowPass: public LowPass 
{
public:
  double Frequency() const override;

  LRLowPass(double firstComponent, double secondComponent);

};
#endif //LRLOWPASS_HPP

