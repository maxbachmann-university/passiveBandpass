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
    Bandpass
};

class Filter 
{
  private:

  const FilterType m_type; ///< The identifier of the specific type (e.g. HighPass)
    
  public:


};
#endif //FILTER_HPP

