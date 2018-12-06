#include "CRHighPass.hpp"

/**
 * Constructor for CRHighPass with a start values.
 * <p>
 * Creates a Highpass with a specific values.
 * </p>
 *
 * @param   firstComponent      Value for Capacitor.
 * @param   secondComponent     Value for Resistor.
 */
CRHighPass::CRHighPass(
    double firstComponent,
    double secondComponent) 
{
    m_firstComponent = std::make_unique<Capacitor>(firstComponent);
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
double CRHighPass::Frequency() const
{
    return 1 / ( 2 * PI * m_firstComponent->getValue() 
      * m_secondComponent->getValue() );
}

  