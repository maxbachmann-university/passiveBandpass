#ifndef HIGHPASS_HPP
#define HIGHPASS_HPP

#include "Filter.hpp"
#include "LowPass.hpp"

class Bandpass;

class HighPass: public Filter {
public:
  virtual ~HighPass() = default; // Virtual destructor needed, because the derived classes are only accessed via a pointer to this class
  HighPass(HighPass&&) = default; // Defining a destructor disables the default move constructor ...
  HighPass& operator=(HighPass&&) = default; // ... and the corresponding assignment operator
  HighPass(const HighPass&) = default; // Defining a move constructor disables the default copy constructor ...
  HighPass& operator=(const HighPass&) = default; // ... and the corresponding assignment operator

  friend std::unique_ptr<Bandpass> operator+ (std::shared_ptr<HighPass> const highPass, std::shared_ptr<LowPass> const lowPass) {
      return std::make_unique<Bandpass>(lowPass, highPass);
  }

  virtual double Frequency() const = 0;

protected:
  HighPass() {};
  std::unique_ptr<Component> m_firstComponent;
  std::unique_ptr<Component> m_secondComponent;
    
};
#endif //HIGHPASS_HPP