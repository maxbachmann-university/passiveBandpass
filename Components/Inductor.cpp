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
 * Operator for combining two Inductors.
 * <p>
 * Returns a Inductor with combined value.
 * </p>
 *
 * @param   Component1      First Inductor.
 * @param   Component2      Second Inductor.
 * 
 * @return New Inductor with new value.
 */
std::unique_ptr<Inductor> operator&& (
    std::shared_ptr<Inductor> const Component1,
    std::shared_ptr<Inductor> const Component2)
{
    return std::make_unique<Inductor>( 
        Component1->getValue() 
        + Component2->getValue() );
}

/**
 * Operator for combining two Inductors.
 * <p>
 * Returns a Inductor with combined value.
 * </p>
 *
 * @param   Component1      First Inductor.
 * @param   Component2      Second Inductor.
 * 
 * @return New Inductor with new value.
 */
std::unique_ptr<Inductor> operator|| (
    std::shared_ptr<Inductor> const Component1,
    std::shared_ptr<Inductor> const Component2)
{
    return std::make_unique<Inductor>( 
        1 / (1/Component1->getValue() + 1/Component2->getValue()) );
}

/**
 * Operator for comparing two Inductors.
 * <p>
 * Returns a bool wether the values of the Inductors are
 * the same or not.
 * </p>
 *
 * @param   Component1      First Inductor.
 * @param   Component2      Second Inductor.
 * 
 * @return Bool if true or not.
 */
bool operator== (
    std::shared_ptr<Inductor> const Component1,
    std::shared_ptr<Inductor> const Component2)
{
    return Component1->getValue() == Component2->getValue();
}

/**
 * Operator for comparing two Inductors.
 * <p>
 * Returns a bool wether the values of the Inductors aren't
 * the same or not.
 * </p>
 *
 * @param   Component1      First Inductor.
 * @param   Component2      Second Inductor.
 * 
 * @return Bool if true or not.
 */
bool operator!= (
    std::shared_ptr<Inductor> const Component1,
    std::shared_ptr<Inductor> const Component2)
{
    return Component1->getValue() != Component2->getValue();
}

/**
 * Operator for combining two Inductors.
 * <p>
 * Returns a Inductor with combined value.
 * </p>
 *
 * @param   Component1      First Inductor.
 * @param   Component2      Second Inductor.
 * 
 * @return New Inductor with new value.
 */
Inductor operator&& ( Inductor const Component1, Inductor const Component2)
{
    return Inductor( Component1.getValue() + Component2.getValue() );
}

/**
 * Operator for combining two Inductors.
 * <p>
 * Returns a Inductor with combined value.
 * </p>
 *
 * @param   Component1      First Inductor.
 * @param   Component2      Second Inductor.
 * 
 * @return New Inductor with new value.
 */
Inductor operator|| ( Inductor const Component1, Inductor const Component2)
{
    return Inductor( 1 / (1/Component1.getValue() + 1/Component2.getValue()));
}

/**
 * Operator for comparing two Inductors.
 * <p>
 * Returns a bool wether the values of the Inductors are
 * the same or not.
 * </p>
 *
 * @param   Component1      First Inductor.
 * @param   Component2      Second Inductor.
 * 
 * @return Bool if true or not.
 */
bool operator== ( Inductor const Component1, Inductor const Component2)
{
    return Component1.getValue() == Component2.getValue();
}

/**
 * Operator for comparing two Inductors.
 * <p>
 * Returns a bool wether the values of the Inductors aren't
 * the same or not.
 * </p>
 *
 * @param   Component1      First Inductor.
 * @param   Component2      Second Inductor.
 * 
 * @return Bool if true or not.
 */
bool operator!= ( Inductor const Component1, Inductor const Component2)
{
    return Component1.getValue() != Component2.getValue();
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
    Inductor const Component1,
    Inductor const Component2)
{
    return Component1.getValue() / Component2.getValue();
}

