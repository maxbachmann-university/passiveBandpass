/** @file */
#ifndef COMBINEDLOWPASS_HPP
#define COMBINEDLOWPASS_HPP

#include "Filter.hpp"
#include <vector>

class PassFilter;

/**
 * @brief       Class for a combined LowPass.
 * @details     This class can can host multiple PassFilters in a vector. It also
 *              provides some basic operators and a Funktion to return all frequencies.
 * @author      Maximilian Bachmann <bachmann.maxim-tfe17@it.dhbw-ravensburg.de>
 * @author      Felix Bandle <bandle.felix-tfe17@it.dhbw-ravensburg.de>
 * @author      Florian Vetter <vetter.florian-tfe17@it.dhbw-ravensburg.de>
 */
class combinedLowPass : public Filter 
{
public:
  std::vector<double> Frequencies() const;

  friend std::unique_ptr<combinedLowPass> operator+ (
    std::shared_ptr<combinedLowPass> const Filter1,
    std::shared_ptr<PassFilter> const Filter2);

  friend std::unique_ptr<combinedLowPass> operator+ (
    std::shared_ptr<PassFilter> const Filter1,
    std::shared_ptr<combinedLowPass> const Filter2);

  friend std::unique_ptr<combinedLowPass> operator+ (
    std::shared_ptr<combinedLowPass> const Filter1,
    std::shared_ptr<combinedLowPass> const Filter2);

private:
  combinedLowPass(std::vector<std::shared_ptr<PassFilter> > passFilters);

  std::vector<std::shared_ptr<PassFilter> > m_PassFilters;    //!< Vector to hold multiple PassFilters.

  friend std::unique_ptr<Filter> operator+ (
    std::shared_ptr<PassFilter> const Filter1,
    std::shared_ptr<PassFilter> const Filter2);
};
#endif //COMBINEDLOWPASS_HPP

