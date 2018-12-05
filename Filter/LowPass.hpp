#ifndef LOWPASS_HPP
#define LOWPASS_HPP

#include "Filter.hpp"
#include "HighPass.hpp"

class HighPass;
class Bandpass;

class LowPass: public Filter 
{
public:
  virtual ~LowPass() = default;
  LowPass(LowPass&&) = default;
  LowPass& operator=(LowPass&&) = default;
  LowPass(const LowPass&) = default;
  LowPass& operator=(const LowPass&) = default;

  friend std::unique_ptr<Bandpass> operator+ (
    std::shared_ptr<LowPass> const lowPass,
    std::shared_ptr<HighPass> const highPass)
  {
    return std::make_unique<Bandpass>(lowPass, highPass);
  }
  
  virtual double Frequency() const = 0;

protected:
  LowPass() {};
  std::unique_ptr<Component> m_firstComponent;
  std::unique_ptr<Component> m_secondComponent;
    
};
#endif //LOWPASS_HPP