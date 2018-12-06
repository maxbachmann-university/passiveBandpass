#ifndef CRHIGHPASS_HPP
#define CRHIGHPASS_HPP

#include "HighPass.hpp"

/**
 * @brief       Class for a HighPass.
 * @details     This HighPass consists of a Capacitor and a Resistor.
 * @author      Maximilian Bachmann <bachmann.maxim-tfe17@it.dhbw-ravensburg.de>
 * @author      Felix Bandle <bandle.felix-tfe17@it.dhbw-ravensburg.de>
 * @author      Florian Vetter <vetter.florian-tfe17@it.dhbw-ravensburg.de>
 */
class CRHighPass: public HighPass {
public:
  double Frequency() const override;    //!< Frequenz of the Filter.

  CRHighPass(double firstComponent, double secondComponent);
};
#endif //CRHIGHPASS_HPP

