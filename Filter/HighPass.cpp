/** @file */
#include "HighPass.hpp"
#include "Bandpass.hpp"

/**
 * Operator for combining a highPass and a lowPass Filter.
 * <p>
 * Creates and returns a Bandpass with a highPass and lowPass.
 * </p>
 *
 * @param   highPass      HighPass.
 * @param   lowPass       LowPass.
 * 
 * @return Bandpass.
 */
std::unique_ptr<Bandpass> operator+ ( 
    std::shared_ptr<HighPass> const highPass,
    std::shared_ptr<LowPass> const lowPass)
{
    return std::make_unique<Bandpass>(lowPass, highPass);
}