/** @file */
#include "Bandpass.hpp"
#include "LowPass.hpp"
#include "HighPass.hpp"

Bandpass::Bandpass(
    std::shared_ptr<PassFilter> Filter1,
    std::shared_ptr<PassFilter> Filter2)
    : m_LowPass(Filter1), m_HighPass(Filter2){}

double Bandpass::returnTopCap() const
{
    return m_LowPass->Frequency();
}

