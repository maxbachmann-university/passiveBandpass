/** @file */
#ifndef BANDPASS_HPP
#define BANDPASS_HPP

#include "Filter.hpp"

//class LowPass;
//class HighPass;
class PassFilter;

class Bandpass : public Filter 
{
public:
  Bandpass(
    std::shared_ptr<PassFilter> Filter1,
    std::shared_ptr<PassFilter> Filter2);

  double returnTopCap() const;

private:
    std::shared_ptr<PassFilter> m_LowPass;
    std::shared_ptr<PassFilter> m_HighPass;

};
#endif //BANDPASS_HPP

