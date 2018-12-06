/** @file */
#include "Inductor.hpp"

/**
 * Constructor for Inductor with a start value.
 * <p>
 * Creates a Inductor with a specific value.
 * </p>
 *
 * @param   value      The start value.
 */
Inductor::Inductor(double value) 
{
    setValue(value);
}

/**
 * Operator for adding two Inductors.
 * <p>
 * Creates and returns a Inductor with the combined size of two Inductors given to the operator.
 * </p>
 *
 * @param   Component1      First Inductor with value.
 * @param   Component2      Second Inductor with value.
 * 
 *  * @return  Inductor with new value.
 */
std::unique_ptr<Inductor> operator+ (
    std::shared_ptr<Inductor> const Component1,
    std::shared_ptr<Inductor> const Component2)
{
    return std::make_unique<Inductor>( 
        Component1->getValue() 
        + Component2->getValue() );
}

/**
 * Operator for subtracting two Inductors.
 * <p>
 * Creates and returns a Inductor with the subtracted size of the first Inductor by the second one.
 * </p>
 *
 * @param   Component1      First Inductor with value.
 * @param   Component2      Second Inductor with value.
 * 
 * @return  Inductor with new value.
 */
std::unique_ptr<Inductor> operator- (
    std::shared_ptr<Inductor> const Component1,
    std::shared_ptr<Inductor> const Component2)
{
    return std::make_unique<Inductor>( 
        Component1->getValue() 
        - Component2->getValue() );
}

/**
 * Operator for dividing two Inductors.
 * <p>
 * Returns the divided size of the first Inductor by the second one.
 * </p>
 *
 * @param   Component1      First Inductor with value.
 * @param   Component2      Second Inductor with value.
 * 
 * @return  Value of the result.
 */
double operator/ (
    std::shared_ptr<Inductor> const Component1,
    std::shared_ptr<Inductor> const Component2)
{
    return Component1->getValue() / Component2->getValue();
}

