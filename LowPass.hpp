#include "Filter.hpp"

#ifndef LOWPASS_HPP
#define LOWPASS_HPP

class LowPass: public Filter {
private:

protected:
  std::unique_ptr<Component> m_firstComponent;
  std::unique_ptr<Component> m_secondComponent;
    
public:
  virtual double Frequency() const = 0;
};
#endif //LOWPASS_HPP