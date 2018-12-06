#include "RLHighPass.hpp"

/**
 * Constructor for RLHighPass with a start values.
 * <p>
 * Creates a Highpass with a specific values.
 * </p>
 *
 * @param   firstComponent      Value for Resistor.
 * @param   secondComponent     Value for Inductor.
 */
RLHighPass::RLHighPass(double firstComponent, double secondComponent) 
    : HighPass() 
{
    m_firstComponent = std::make_unique<Resistor>(firstComponent);
    m_secondComponent = std::make_unique<Inductor>(secondComponent);
}

/**
 * Returns the Frequenz of the item.
 * <p>
 * Calculates and returns the Frequenz of the item.
 * </p>
 *
 * @return   Frequenz.
 */
double RLHighPass::Frequency() const 
{
    return m_firstComponent->getValue() 
        / ( 2 * PI * m_secondComponent->getValue() );
}

