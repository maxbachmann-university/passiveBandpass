#ifndef RLHIGHPASS_HPP
#define RLHIGHPASS_HPP

#include "HighPass.hpp"

class RLHighPass: public HighPass 
{
public:
  double Frequency() const override;

  RLHighPass(double firstComponent, double secondComponent);
};
#endif //RLHIGHPASS_HPP