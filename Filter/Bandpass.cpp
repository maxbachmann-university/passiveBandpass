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
    std::shared_ptr<LowPass> lowPass,
    std::shared_ptr<HighPass> highPass)
    : m_LowPass(lowPass), m_HighPass(highPass){}

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
