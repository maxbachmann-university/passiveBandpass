#ifndef RLHIGHPASS_HPP
#define RLHIGHPASS_HPP

#include "PassFilter.hpp"

/**
 * @brief       Class for a HighPass.
 * @details     This HighPass consists of a Resistor and a Inductor.
 * @author      Maximilian Bachmann <bachmann.maxim-tfe17@it.dhbw-ravensburg.de>
 * @author      Felix Bandle <bandle.felix-tfe17@it.dhbw-ravensburg.de>
 * @author      Florian Vetter <vetter.florian-tfe17@it.dhbw-ravensburg.de>
 */
class RLHighPass: public PassFilter 
{
public:
  double Frequency() const override;    //!< Frequenz of the Filter.

  RLHighPass(double firstComponent, double secondComponent);
};
#endif //RLHIGHPASS_HPP

