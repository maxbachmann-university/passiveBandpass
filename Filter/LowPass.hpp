#ifndef LOWPASS_HPP
#define LOWPASS_HPP

#include "Filter.hpp"

class Bandpass;
class HighPass;

class LowPass: public Filter 
{
public:
  virtual ~LowPass() = default;
  LowPass(LowPass&&) = default;
  LowPass& operator=(LowPass&&) = default;
  LowPass(const LowPass&) = default;
  LowPass& operator=(const LowPass&) = default;
  
  virtual double Frequency() const = 0;

  friend std::unique_ptr<Bandpass> operator+ (
    std::shared_ptr<LowPass> const lowPass,
    std::shared_ptr<HighPass> const highPass);

protected:
  LowPass() {};
  std::unique_ptr<Component> m_firstComponent;
  std::unique_ptr<Component> m_secondComponent;
    
};
#endif //LOWPASS_HPP