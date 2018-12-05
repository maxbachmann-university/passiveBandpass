#ifndef PASSFILTER_HPP
#define PASSFILTER_HPP

#include "Filter.hpp"

class Bandpass;
class HighPass;
class LowPass;

class PassFilter: public Filter 
{
public:

  friend std::unique_ptr<Bandpass> operator+ (
    std::shared_ptr<LowPass> const lowPass,
    std::shared_ptr<HighPass> const highPass);

  friend std::unique_ptr<Bandpass> operator+ ( 
    std::shared_ptr<HighPass> const highPass,
    std::shared_ptr<LowPass> const lowPass);

  virtual double Frequency() const = 0;

protected:
  std::unique_ptr<Component> m_firstComponent;
  std::unique_ptr<Component> m_secondComponent;
    
};
#endif //PASSFILTER_HPP