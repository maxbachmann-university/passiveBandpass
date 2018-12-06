#ifndef LOWPASS_HPP
#define LOWPASS_HPP

#include "PassFilter.hpp"

class LowPass: public PassFilter 
{
public:
  virtual ~LowPass() = default;
  LowPass(LowPass&&) = default;
  LowPass& operator=(LowPass&&) = default;
  LowPass(const LowPass&) = default;
  LowPass& operator=(const LowPass&) = default;
  
  virtual double Frequency() const override = 0;

protected:
  LowPass() {}
    
};
#endif //LOWPASS_HPP

