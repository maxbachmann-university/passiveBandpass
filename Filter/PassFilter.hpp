#ifndef PASSFILTER_HPP
#define PASSFILTER_HPP

#include "Filter.hpp"

class Bandpass;
class HighPass;
class LowPass;

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

  friend std::unique_ptr<Bandpass> operator+ (
    std::shared_ptr<LowPass> const lowPass,
    std::shared_ptr<HighPass> const highPass);

  friend std::unique_ptr<Bandpass> operator+ ( 
    std::shared_ptr<HighPass> const highPass,
    std::shared_ptr<LowPass> const lowPass);

  virtual double Frequency() const = 0;

protected:
  PassFilter() = default;
  std::unique_ptr<Component> m_firstComponent;
  std::unique_ptr<Component> m_secondComponent;
    
};
#endif //PASSFILTER_HPP

