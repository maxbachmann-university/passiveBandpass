#ifndef HIGHPASS_HPP
#define HIGHPASS_HPP

#include "Filter.hpp"
#include "LowPass.hpp"

class LowPass;
class Bandpass;

class HighPass: public Filter 
{
public:
  virtual ~HighPass() = default;
  HighPass(HighPass&&) = default;
  HighPass& operator=(HighPass&&) = default;
  HighPass(const HighPass&) = default;
  HighPass& operator=(const HighPass&) = default;

  friend std::unique_ptr<Bandpass> operator+ ( 
    std::shared_ptr<HighPass> const highPass,
    std::shared_ptr<LowPass> const lowPass)
  {
    return std::make_unique<Bandpass>(lowPass, highPass);
  }

  virtual double Frequency() const = 0;

protected:
  HighPass() {};
  std::unique_ptr<Component> m_firstComponent;
  std::unique_ptr<Component> m_secondComponent;
    
};
#endif //HIGHPASS_HPP