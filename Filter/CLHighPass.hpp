#ifndef CLHIGHPASS_HPP
#define CLHIGHPASS_HPP

#include "HighPass.hpp"

/**
 * @brief       Class for a HighPass.
 * @details     This HighPass consists of a Capacitor and a Inductor.
 * @author      Maximilian Bachmann <bachmann.maxim-tfe17@it.dhbw-ravensburg.de>
 * @author      Felix Bandle <bandle.felix-tfe17@it.dhbw-ravensburg.de>
 * @author      Florian Vetter <vetter.florian-tfe17@it.dhbw-ravensburg.de>
 */
class CLHighPass: public HighPass 
{
public:
  double Frequency() const override;    //!< Frequenz of the Filter.

  CLHighPass(double firstComponent, double secondComponent);
  //CLHighPass(std::shared_ptr<Component> m_firstComponent, std::shared_ptr<Component> m_secondComponent;);
};
#endif //RLHIGHPASS_HPP

