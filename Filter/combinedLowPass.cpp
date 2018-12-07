#include "combinedLowPass.hpp"
#include "PassFilter.hpp"

/**
 * Constructor for a combined LowPass.
 *
 * @param   passFilters     Vector of multiple passFilters..
 */
combinedLowPass::combinedLowPass(
    std::vector<std::shared_ptr<PassFilter> > passFilters)
    : Filter(FilterType::combinedLowPass), m_PassFilters(passFilters){}

/**
 * Method for returning all Filter frequencies.
 *
 * @return Frequencies of all Filters in a vector.
 */
std::vector<double> combinedLowPass::Frequencies() const
{
    std::vector<double> retValues;
    retValues.reserve(m_PassFilters.size());
    for (std::shared_ptr<PassFilter> passFilter : m_PassFilters){
        retValues.push_back(passFilter->Frequency());
    }
    return retValues;
}

/**
 * Operator to combine two Filters.
 *
 * @param   Filter1     Combined Filter..
 * @param   Filter2     PassFilter.
 * 
 * @return New combined LowPass.
 */
std::unique_ptr<combinedLowPass> operator+ (
    std::shared_ptr<combinedLowPass> const Filter1,
    std::shared_ptr<PassFilter> const Filter2)
{
    auto a = Filter1->m_PassFilters;
    a.push_back(Filter2);
    return std::unique_ptr<combinedLowPass>(
        new combinedLowPass(a));
}

/**
 * Operator to combine two Filters.
 *
 * @param   Filter1     PassFilter.
 * @param   Filter2     Combined Filter.
 * 
 * @return New combined LowPass.
 */
std::unique_ptr<combinedLowPass> operator+ (
    std::shared_ptr<PassFilter> const Filter1,
    std::shared_ptr<combinedLowPass> const Filter2)
{
    return Filter2 + Filter1;
}

/**
 * Operator to combine two Filters.
 *
 * @param   Filter1     Combined Filter.
 * @param   Filter2     Combined Filter.
 * 
 * @return New combined LowPass.
 */
std::unique_ptr<combinedLowPass> operator+ (
    std::shared_ptr<combinedLowPass> const Filter1,
    std::shared_ptr<combinedLowPass> const Filter2)
{
    auto a = Filter1->m_PassFilters;
    const auto b = Filter2->m_PassFilters;
    
    a.insert(std::end(a), std::begin(b), std::end(b));
    return std::unique_ptr<combinedLowPass>(
        new combinedLowPass(a));
}