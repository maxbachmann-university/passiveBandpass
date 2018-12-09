#include "RCLowPass.hpp"

/**
 * Constructor for RCLowPass with a start values.
 * <p>
 * Creates a Lowpass with a specific values.
 * </p>
 *
 * @param   firstComponent      Value for Resistor.
 * @param   secondComponent     Value for Capacitor.
 */
RCLowPass::RCLowPass(double firstComponent, double secondComponent) 
    : PassFilter(FilterType::LowPass) 
{
    m_firstComponent = std::make_unique<Resistor>(firstComponent);
    m_secondComponent = std::make_unique<Capacitor>(secondComponent);
}

/**
 * Returns the Frequenz of the item.
 * <p>
 * Calculates and returns the Frequenz of the item.
 * </p>
 *
 * @return   Frequenz.
 */
double RCLowPass::Frequency() const 
{
    return 1 / ( 2 * PI * m_firstComponent->getValue() 
        * m_secondComponent->getValue() );
}

