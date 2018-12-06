/** @file */
#ifndef BANDPASS_HPP
#define BANDPASS_HPP

#include "Filter.hpp"
#include <math.h>

//#include "PassFilter.hpp"

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
  double returnTopCap() const;
  double returnBottomCap() const;
  double returnBandwidth() const;
  double returnResonanceFrequency() const;
  double returnPerformance() const;

private:
  Bandpass(
    std::shared_ptr<PassFilter> Filter1,
    std::shared_ptr<PassFilter> Filter2)
    : Filter(FilterType::Bandpass), m_LowPass(Filter1), m_HighPass(Filter2){}

  std::shared_ptr<PassFilter> m_LowPass;
  std::shared_ptr<PassFilter> m_HighPass;

  friend std::unique_ptr<Filter> operator+ (
    std::shared_ptr<PassFilter> const Filter1,
    std::shared_ptr<PassFilter> const Filter2);
  
  //friend class PassFilter;
};
#endif //BANDPASS_HPP

