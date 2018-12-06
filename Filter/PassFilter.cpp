#include "PassFilter.hpp"

#include "Bandpass.hpp"

PassFilter::PassFilter(const FilterType type)
  : Filter(type) {};

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
    const FilterType type1 = Filter1->m_type;
    const FilterType type2 = Filter2->m_type;
    std::unique_ptr<Filter> retFilter;

    if (type1 != type2)
    {
        if (type1 == FilterType::LowPass)
        {
            retFilter = std::make_unique<Bandpass>(Filter1, Filter2);
        }
        else{
            retFilter = std::make_unique<Bandpass>(Filter2, Filter1);
        }
    }
    else{
        if (type1 == FilterType::LowPass)
        {
            //Pointer to combined Filter two LowPass
        }
        else{
            //Pointer to combined Filter two HighPass
        }
    }
    return retFilter;
}

