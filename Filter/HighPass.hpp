#ifndef HIGHPASS_HPP
#define HIGHPASS_HPP

#include "PassFilter.hpp"

/**
 * @brief       Class for a HighPass.
 * @details     This class provides some basic operators to its childs.
 * @author      Maximilian Bachmann <bachmann.maxim-tfe17@it.dhbw-ravensburg.de>
 * @author      Felix Bandle <bandle.felix-tfe17@it.dhbw-ravensburg.de>
 * @author      Florian Vetter <vetter.florian-tfe17@it.dhbw-ravensburg.de>
 */
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
  HighPass() = default;
    
};
#endif //HIGHPASS_HPP

