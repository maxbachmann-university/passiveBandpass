/** @file */
#include "Bandpass.hpp"
#include "PassFilter.hpp"
#include <iostream>

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
    : Filter(FilterType::Bandpass), m_LowPass(Filter1), m_HighPass(Filter2){}

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

/**
 * Returns the Bandwidth.
 *
 * @return   The Bandwidth.
 */
double Bandpass::returnBandwidth() const
{
    return m_LowPass->Frequency() - m_HighPass->Frequency();
}

/**
 * Returns the Bandwidth.
 *
 * @return   The Bandwidth.
 */
double Bandpass::returnResonanceFrequency() const
{
    return sqrt(m_LowPass->Frequency() * m_HighPass->Frequency());
}

/**
 * calculates the Performance
 *
 * @param   returnValue     Reference to a double holding the Performance
 * @return wether the output value would have been bigger then double max
 */
bool Bandpass::returnPerformance(double& returnValue) const
{
    double min = 1 / (std::numeric_limits<double>::max() 
        / returnResonanceFrequency());

    if (min >= returnBandwidth())
    {
        returnValue = std::numeric_limits<double>::max();
        return 0;
    }
    else{
        returnValue = returnResonanceFrequency() / returnBandwidth();
        return 1;
    }
}

