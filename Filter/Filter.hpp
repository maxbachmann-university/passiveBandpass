#ifndef FILTER_HPP
#define FILTER_HPP

#include "../Components/Resistor.hpp"
#include "../Components/Capacitor.hpp"
#include "../Components/Inductor.hpp"
#include <memory>
#include <math.h>
#define PI 3.14159265358979323846  /* pi */

/**
 * @brief       Enum class for the Caller IDs of all Filters.
 * @author      Maximilian Bachmann <bachmann.maxim-tfe17@it.dhbw-ravensburg.de>
 * @author      Felix Bandle <bandle.felix-tfe17@it.dhbw-ravensburg.de>
 * @author      Florian Vetter <vetter.florian-tfe17@it.dhbw-ravensburg.de>
 */
enum class FilterType
	: std::uint8_t {
		HighPass,
		LowPass,
    Bandpass,
    combinedHighPass,
    combinedLowPass
};

/**
 * @brief       Class for basic operators for all kind of Filters.
 * @details     This class provides some basic operators for all kind of filters.
 * @author      Maximilian Bachmann <bachmann.maxim-tfe17@it.dhbw-ravensburg.de>
 * @author      Felix Bandle <bandle.felix-tfe17@it.dhbw-ravensburg.de>
 * @author      Florian Vetter <vetter.florian-tfe17@it.dhbw-ravensburg.de>
 */
class Filter 
{
public:
  virtual ~Filter() = default;
  Filter(Filter&&) = default;
  Filter& operator=(Filter&&) = default;
  Filter(const Filter&) = default;
  Filter& operator=(const Filter&) = default;

  const FilterType m_type; //!< The identifier of the specific type (e.g. HighPass)
    
protected:
  Filter(const FilterType type):m_type(type){}


};
#endif //FILTER_HPP

