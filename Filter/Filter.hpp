#ifndef FILTER_HPP
#define FILTER_HPP

#include "../Components/Resistor.hpp"
#include "../Components/Capacitor.hpp"
#include "../Components/Inductor.hpp"
#include <memory>
#include <math.h>
#define PI 3.14159265358979323846  /* pi */

enum class FilterType ///< Caller IDs
	: std::uint8_t {
		HighPass,
		LowPass,
    Bandpass,
    combinedPassFilter
};

class Filter 
{
public:
  virtual ~Filter() = default;
  Filter(Filter&&) = default;
  Filter& operator=(Filter&&) = default;
  Filter(const Filter&) = default;
  Filter& operator=(const Filter&) = default;

  const FilterType m_type; ///< The identifier of the specific type (e.g. HighPass)
    
protected:
  Filter(const FilterType type):m_type(type){}


};
#endif //FILTER_HPP

