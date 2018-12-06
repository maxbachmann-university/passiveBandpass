#ifndef RLHIGHPASS_HPP
#define RLHIGHPASS_HPP

#include "PassFilter.hpp"

class RLHighPass: public PassFilter 
{
public:
  double Frequency() const override;

  RLHighPass(double firstComponent, double secondComponent);
};
#endif //RLHIGHPASS_HPP

