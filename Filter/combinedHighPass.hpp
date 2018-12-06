/** @file */
#ifndef COMBINEDHIGHPASS_HPP
#define COMBINEDHIGHPASS_HPP

#include "Filter.hpp"
#include <vector>

class PassFilter;

class combinedHighPass : public Filter 
{
public:
  std::vector<double> Frequencies() const;

  friend std::unique_ptr<combinedHighPass> operator+ (
    std::shared_ptr<combinedHighPass> const Filter1,
    std::shared_ptr<PassFilter> const Filter2);

  friend std::unique_ptr<combinedHighPass> operator+ (
    std::shared_ptr<PassFilter> const Filter1,
    std::shared_ptr<combinedHighPass> const Filter2);

  friend std::unique_ptr<combinedHighPass> operator+ (
    std::shared_ptr<combinedHighPass> const Filter1,
    std::shared_ptr<combinedHighPass> const Filter2);

private:
  combinedHighPass(std::vector<std::shared_ptr<PassFilter> > passFilters);

  std::vector<std::shared_ptr<PassFilter> > m_PassFilters;

  friend std::unique_ptr<Filter> operator+ (
    std::shared_ptr<PassFilter> const Filter1,
    std::shared_ptr<PassFilter> const Filter2);
};
#endif //COMBINEDHIGHPASS_HPP

