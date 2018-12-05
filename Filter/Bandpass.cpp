/** @file */
#include "Bandpass.hpp"
#include "LowPass.hpp"
#include "HighPass.hpp"

Bandpass::Bandpass(
    std::shared_ptr<LowPass> lowPass,
    std::shared_ptr<HighPass> highPass)
    : m_LowPass(lowPass), m_HighPass(highPass){}

double Bandpass::returnTopCap() const
{
    return m_LowPass->Frequency();
};