#include "combinedPassFilter.hpp"
#include "PassFilter.hpp"

combinedPassFilter::combinedPassFilter(
    std::vector<std::shared_ptr<PassFilter> > passFilters)
    : Filter(FilterType::combinedPassFilter), m_PassFilters(passFilters){}

std::vector<double> combinedPassFilter::Frequencies() const{
    std::vector<double> retValues;
    retValues.reserve(m_PassFilters.size());
    for (std::shared_ptr<PassFilter> passFilter : m_PassFilters){
        retValues.push_back(passFilter->Frequency());
    }
    return retValues;
}