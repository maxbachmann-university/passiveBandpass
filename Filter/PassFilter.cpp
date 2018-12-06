#include "PassFilter.hpp"

#include "Bandpass.hpp"

PassFilter::PassFilter(const FilterType type)
  : m_type(type) {};

/**
 * Operator for combining a highPass and a lowPass Filter.
 * <p>
 * Creates and returns a Bandpass with a highPass and lowPass.
 * </p>
 *
 * @param   highPass      HighPass.
 * @param   lowPass       LowPass.
 * 
 * @return Bandpass.
 */
std::unique_ptr<Filter> operator+ ( 
    std::shared_ptr<PassFilter> const Filter1,
    std::shared_ptr<PassFilter> const Filter2)
{
    
    return std::make_unique<Bandpass>(Filter1, Filter2);
}

