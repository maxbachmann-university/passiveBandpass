#ifndef LOWPASS_HPP
#define LOWPASS_HPP

#include "Filter.hpp"
#include "HighPass.hpp"

class Bandpass;

class LowPass: public Filter {
public:
  virtual ~LowPass() = default; // Virtual destructor needed, because the derived classes are only accessed via a pointer to this class
  LowPass(LowPass&&) = default; // Defining a destructor disables the default move constructor ...
  LowPass& operator=(LowPass&&) = default; // ... and the corresponding assignment operator
  LowPass(const LowPass&) = default; // Defining a move constructor disables the default copy constructor ...
  LowPass& operator=(const LowPass&) = default; // ... and the corresponding assignment operator

  friend std::unique_ptr<Bandpass> operator+ (std::shared_ptr<LowPass> const lowPass, std::shared_ptr<HighPass> const highPass) {
      return std::make_unique<Bandpass>(lowPass, highPass);
  }
  
  virtual double Frequency() const = 0;

protected:
  LowPass() {};
  std::unique_ptr<Component> m_firstComponent;
  std::unique_ptr<Component> m_secondComponent;
    
};
#endif //LOWPASS_HPP