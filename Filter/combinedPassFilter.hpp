/** @file */
#ifndef COMBINEDPASSFILTER_HPP
#define COMBINEDPASSFILTER_HPP

#include "Filter.hpp"
#include <vector>

class PassFilter;

class combinedPassFilter : public Filter 
{
public:
  std::vector<double> Frequencies() const;

private:
  combinedPassFilter(std::vector<std::shared_ptr<PassFilter> > passFilters);

  std::vector<std::shared_ptr<PassFilter> > m_PassFilters;

  friend std::unique_ptr<Filter> operator+ (
    std::shared_ptr<PassFilter> const Filter1,
    std::shared_ptr<PassFilter> const Filter2);
};
#endif //COMBINEDPASSFILTER_HPP

