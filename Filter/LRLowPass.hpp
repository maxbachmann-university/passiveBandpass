#ifndef LRLOWPASS_HPP
#define LRLOWPASS_HPP

#include "LowPass.hpp"

/**
 * @brief       Class for a LowPass.
 * @details     This HighPass consists of a Inductor and a Resistor.
 * @author      Maximilian Bachmann <bachmann.maxim-tfe17@it.dhbw-ravensburg.de>
 * @author      Felix Bandle <bandle.felix-tfe17@it.dhbw-ravensburg.de>
 * @author      Florian Vetter <vetter.florian-tfe17@it.dhbw-ravensburg.de>
 */
class LRLowPass: public LowPass 
{
public:
  double Frequency() const override;    //!< Frequenz of the Filter.

  LRLowPass(double firstComponent, double secondComponent);

};
#endif //LRLOWPASS_HPP

