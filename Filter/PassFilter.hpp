#ifndef PASSFILTER_HPP
#define PASSFILTER_HPP

#include "Filter.hpp"

class Bandpass;

/**
 * @brief       Class for basic operators.
 * @details     This class provides some basic operators to both kind of filters.
 * @author      Maximilian Bachmann <bachmann.maxim-tfe17@it.dhbw-ravensburg.de>
 * @author      Felix Bandle <bandle.felix-tfe17@it.dhbw-ravensburg.de>
 * @author      Florian Vetter <vetter.florian-tfe17@it.dhbw-ravensburg.de>
 */
class PassFilter: public Filter 
{
public:
  virtual ~PassFilter() = default;
  PassFilter(PassFilter&&) = default;
  PassFilter& operator=(PassFilter&&) = default;
  PassFilter(const PassFilter&) = default;
  PassFilter& operator=(const PassFilter&) = default;

  friend std::unique_ptr<Filter> operator+ (
    std::shared_ptr<PassFilter> const Filter1,
    std::shared_ptr<PassFilter> const Filter2);

  virtual double Frequency() const = 0;

protected:
  PassFilter(const FilterType type);
  std::unique_ptr<Component> m_firstComponent;
  std::unique_ptr<Component> m_secondComponent;
    
};
#endif //PASSFILTER_HPP

