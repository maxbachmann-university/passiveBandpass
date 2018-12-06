#ifndef RCLOWPASS_HPP
#define RCLOWPASS_HPP

#include "PassFilter.hpp"

/**
 * @brief       Class for a LowPass.
 * @details     This LowPass consists of a Resistor and a Capacitor.
 * @author      Maximilian Bachmann <bachmann.maxim-tfe17@it.dhbw-ravensburg.de>
 * @author      Felix Bandle <bandle.felix-tfe17@it.dhbw-ravensburg.de>
 * @author      Florian Vetter <vetter.florian-tfe17@it.dhbw-ravensburg.de>
 */
class RCLowPass: public PassFilter 
{
public:
  double Frequency() const override;    //!< Frequenz of the Filter.

  RCLowPass(double firstComponent, double secondComponent);

};
#endif //RCLOWPASS_HPP

