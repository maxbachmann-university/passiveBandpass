#ifndef BANDPASS_HPP
#define BANDPASS_HPP

#include "Filter.hpp"
#include "LowPass.hpp"
#include "HighPass.hpp"

class Bandpass : public Filter {
public:
  Bandpass(std::shared_ptr<LowPass> lowPass, std::shared_ptr<HighPass> highPass)
    : m_LowPass(lowPass), m_HighPass(highPass){}

  double returnTopCap(){ return m_LowPass->Frequency(); };

private:
  std::shared_ptr<LowPass> m_LowPass;
  std::shared_ptr<HighPass> m_HighPass;

};
#endif //BANDPASS_HPP