/** @file */
#ifndef BANDPASS_HPP
#define BANDPASS_HPP

#include "Filter.hpp"

class PassFilter;

/**
 * @brief       Class for a Bandpass.
 * @details     A Bandpass contains a lowPass and a highPass. It also can return some information
 *              about itself.
 * @author      Maximilian Bachmann <bachmann.maxim-tfe17@it.dhbw-ravensburg.de>
 * @author      Felix Bandle <bandle.felix-tfe17@it.dhbw-ravensburg.de>
 * @author      Florian Vetter <vetter.florian-tfe17@it.dhbw-ravensburg.de>
 */
class Bandpass : public Filter 
{
public:
  Bandpass(
    std::shared_ptr<PassFilter> Filter1,
    std::shared_ptr<PassFilter> Filter2);

  double returnTopCap() const;
  double returnBottomCap() const;

private:
    std::shared_ptr<PassFilter> m_LowPass;
    std::shared_ptr<PassFilter> m_HighPass;

};
#endif //BANDPASS_HPP

