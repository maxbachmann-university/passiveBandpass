/** @file */
#include "Bandpass.hpp"
#include "LowPass.hpp"
#include "HighPass.hpp"

/**
 * Constructor for Bandpass with a start value.
 * <p>
 * Creates a Capacitor with a specific value.
 * </p>
 *
 * @param   lowPass      LowPass Filter.
 * @param   highPass     HighPass Filter.
 */
Bandpass::Bandpass(
    std::shared_ptr<PassFilter> Filter1,
    std::shared_ptr<PassFilter> Filter2)
    : m_LowPass(Filter1), m_HighPass(Filter2){}

/**
 * Returns the Top Frequenz.
 *
 * @return   The Top Frequenz.
 */
double Bandpass::returnTopCap() const
{
    return m_LowPass->Frequency();
}

/**
 * Returns the Bottom Frequenz.
 *
 * @return   The Bottom Frequenz.
 */
double Bandpass::returnBottomCap() const
{
    return m_HighPass->Frequency();
}
