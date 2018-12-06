#ifndef PASSFILTER_HPP
#define PASSFILTER_HPP

#include "Filter.hpp"

class Bandpass;
//class HighPass;
//class LowPass;

enum class FilterType ///< Caller IDs
	: std::uint8_t {
		HighPass,
		LowPass
};

class PassFilter: public Filter 
{
public:
  virtual ~PassFilter() = default;
  PassFilter(PassFilter&&) = default;
  PassFilter& operator=(PassFilter&&) = default;
  PassFilter(const PassFilter&) = default;
  PassFilter& operator=(const PassFilter&) = default;

  friend std::unique_ptr<Filter> operator+ (
    std::shared_ptr<PassFilter> const Filter1,
    std::shared_ptr<PassFilter> const Filter2);

  /*friend std::unique_ptr<Bandpass> operator+ ( 
    std::shared_ptr<HighPass> const highPass,
    std::shared_ptr<LowPass> const lowPass);*/

  virtual double Frequency() const = 0;

  const FilterType m_type; ///< The identifier of the specific type (e.g. HighPass)

protected:
  PassFilter(const FilterType type);
  std::unique_ptr<Component> m_firstComponent;
  std::unique_ptr<Component> m_secondComponent;
    
};
#endif //PASSFILTER_HPP

