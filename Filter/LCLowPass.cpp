#include "LCLowPass.hpp"

/**
 * Constructor for LCLowPass with a start values.
 * <p>
 * Creates a Lowpass with a specific values.
 * </p>
 *
 * @param   firstComponent      Value for Inductor.
 * @param   secondComponent     Value for Capacitor.
 */
LCLowPass::LCLowPass(double firstComponent, double secondComponent)
    : LowPass() 
{
    m_firstComponent = std::make_unique<Inductor>(firstComponent);
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
double LCLowPass::Frequency() const
{
    return 1 / ( 2 * PI * sqrt(m_firstComponent->getValue()
      * m_secondComponent->getValue()));
}

