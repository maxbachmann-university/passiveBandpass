#include "HighPass.hpp"
#include "Bandpass.hpp"

std::unique_ptr<Bandpass> operator+ ( 
    std::shared_ptr<HighPass> const highPass,
    std::shared_ptr<LowPass> const lowPass)
{
    return std::make_unique<Bandpass>(lowPass, highPass);
}