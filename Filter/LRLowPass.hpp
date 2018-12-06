#ifndef LRLOWPASS_HPP
#define LRLOWPASS_HPP

#include "PassFilter.hpp"

class LRLowPass: public PassFilter 
{
public:
  double Frequency() const override;

  LRLowPass(double firstComponent, double secondComponent);

};
#endif //LRLOWPASS_HPP

