#ifndef CLHIGHPASS_HPP
#define CLHIGHPASS_HPP

#include "HighPass.hpp"

class CLHighPass: public HighPass 
{
public:
  double Frequency() const override;

  CLHighPass(double firstComponent, double secondComponent);
};
#endif //RLHIGHPASS_HPP