#include "LRLowPass.hpp"

/**
 * Constructor for LRLowPass with a start values.
 * <p>
 * Creates a Lowpass with a specific values.
 * </p>
 *
 * @param   firstComponent      Value for Inductor.
 * @param   secondComponent     Value for Resistor.
 */
LRLowPass::LRLowPass(double firstComponent, double secondComponent) 
    : PassFilter(FilterType::LowPass) 
{
    m_firstComponent = std::make_unique<Inductor>(firstComponent);
    m_secondComponent = std::make_unique<Resistor>(secondComponent);
}

/**
 * Returns the Frequenz of the item.
 * <p>
 * Calculates and returns the Frequenz of the item.
 * </p>
 *
 * @return   Frequenz.
 */
double LRLowPass::Frequency() const 
{
    return m_secondComponent->getValue() 
        / ( 2 * PI * m_firstComponent->getValue() );
}

  