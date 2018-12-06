#ifndef LCLOWPASS_HPP
#define LCLOWPASS_HPP

#include "LowPass.hpp"

/**
 * @brief       Class for a LowPass.
 * @details     This LowPass consists of a Inductor and a Capacitor.
 * @author      Maximilian Bachmann <bachmann.maxim-tfe17@it.dhbw-ravensburg.de>
 * @author      Felix Bandle <bandle.felix-tfe17@it.dhbw-ravensburg.de>
 * @author      Florian Vetter <vetter.florian-tfe17@it.dhbw-ravensburg.de>
 */
class LCLowPass: public LowPass 
{
public:
  double Frequency() const override;    //!< Frequenz of the Filter.

  LCLowPass(double firstComponent, double secondComponent);

};
#endif //LCLOWPASS_HPP

