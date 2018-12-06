#ifndef HIGHPASS_HPP
#define HIGHPASS_HPP

#include "PassFilter.hpp"


class HighPass: public PassFilter 
{
public:
  virtual ~HighPass() = default;
  HighPass(HighPass&&) = default;
  HighPass& operator=(HighPass&&) = default;
  HighPass(const HighPass&) = default;
  HighPass& operator=(const HighPass&) = default;

  virtual double Frequency() const override = 0;

protected:
  HighPass() {}
    
};
#endif //HIGHPASS_HPP

