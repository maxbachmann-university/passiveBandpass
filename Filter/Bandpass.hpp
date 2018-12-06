/** @file */
#ifndef BANDPASS_HPP
#define BANDPASS_HPP

#include "Filter.hpp"

class LowPass;
class HighPass;

class Bandpass : public Filter 
{
public:
  Bandpass(
    std::shared_ptr<LowPass> lowPass,
    std::shared_ptr<HighPass> highPass);

  double returnTopCap() const;

private:
    std::shared_ptr<LowPass> m_LowPass;
    std::shared_ptr<HighPass> m_HighPass;

};
#endif //BANDPASS_HPP

