#ifndef PASSFILTER_HPP
#define PASSFILTER_HPP

#include "Filter.hpp"
//#include "Bandpass.hpp"
//#include "HighPass.hpp"
//#include "LowPass.hpp"

class PassFilter: public Filter 
{
public:

  /*friend std::unique_ptr<Bandpass> operator+ (
    std::shared_ptr<LowPass> const lowPass,
    std::shared_ptr<HighPass> const highPass)
  {
    return std::make_unique<Bandpass>(lowPass, highPass);
  }*/
/*
  friend std::unique_ptr<Bandpass> operator+ ( 
    std::shared_ptr<HighPass> const highPass,
    std::shared_ptr<LowPass> const lowPass)
  {
    return std::make_unique<Bandpass>(lowPass, highPass);
  }*/
  
 // virtual double Frequency() const = 0;

protected:
  //std::unique_ptr<Component> m_firstComponent;
  //std::unique_ptr<Component> m_secondComponent;
    
};
#endif //PASSFILTER_HPP