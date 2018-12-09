/** @file */
#include "Capacitor.hpp"

/**
 * Constructor for Capacitor with a start value.
 * <p>
 * Creates a Capacitor with a specific value.
 * </p>
 *
 * @param   value      The start value.
 */
Capacitor::Capacitor(double value)
{
    setValue(value);
}

/**
 * Operator for combining two Capacitors.
 * <p>
 * Returns a Capacitor with combined value.
 * </p>
 *
 * @param   Component1      First Capacitor.
 * @param   Component2      Second Capacitor.
 * 
 * @return New Capacitor with new value.
 */
std::unique_ptr<Capacitor> operator&& (
    std::shared_ptr<Capacitor> const Component1,
    std::shared_ptr<Capacitor> const Component2)
{
    return std::make_unique<Capacitor>( 
        1 / (1/Component1->getValue() + 1/Component2->getValue()) );
}

/**
 * Operator for combining two Capacitors.
 * <p>
 * Returns a Capacitor with combined value.
 * </p>
 *
 * @param   Component1      First Capacitor.
 * @param   Component2      Second Capacitor.
 * 
 * @return New Capacitor with new value.
 */
std::unique_ptr<Capacitor> operator|| (
    std::shared_ptr<Capacitor> const Component1,
    std::shared_ptr<Capacitor> const Component2)
{
    return std::make_unique<Capacitor>( 
        Component1->getValue() 
        + Component2->getValue() );
}

/**
 * Operator for comparing two Capacitors.
 * <p>
 * Returns a bool wether the values of the Capacitors are
 * the same or not.
 * </p>
 *
 * @param   Component1      First Capacitor.
 * @param   Component2      Second Capacitor.
 * 
 * @return Bool if true or not.
 */
bool operator== (
    std::shared_ptr<Capacitor> const Component1,
    std::shared_ptr<Capacitor> const Component2)
{
    return Component1->getValue() == Component2->getValue();
}

/**
 * Operator for comparing two Capacitors.
 * <p>
 * Returns a bool wether the values of the Capacitors aren't
 * the same or not.
 * </p>
 *
 * @param   Component1      First Capacitor.
 * @param   Component2      Second Capacitor.
 * 
 * @return Bool if true or not.
 */
bool operator!= (
    std::shared_ptr<Capacitor> const Component1,
    std::shared_ptr<Capacitor> const Component2)
{
    return Component1->getValue() != Component2->getValue();
}

/**
 * Operator for combining two Capacitors.
 * <p>
 * Returns a Capacitor with combined value.
 * </p>
 *
 * @param   Component1      First Capacitor.
 * @param   Component2      Second Capacitor.
 * 
 * @return New Capacitor with new value.
 */
Capacitor operator&& ( Capacitor const Component1, Capacitor const Component2)
{
    return Capacitor( 1 / (1/Component1.getValue() + 1/Component2.getValue()));
}

/**
 * Operator for combining two Capacitors.
 * <p>
 * Returns a Capacitor with combined value.
 * </p>
 *
 * @param   Component1      First Capacitor.
 * @param   Component2      Second Capacitor.
 * 
 * @return New Capacitor with new value.
 */
Capacitor operator|| ( Capacitor const Component1, Capacitor const Component2)
{
    return Capacitor( Component1.getValue() + Component2.getValue() );
}

/**
 * Operator for comparing two Capacitors.
 * <p>
 * Returns a bool wether the values of the Capacitors are
 * the same or not.
 * </p>
 *
 * @param   Component1      First Capacitor.
 * @param   Component2      Second Capacitor.
 * 
 * @return Bool if true or not.
 */
bool operator== ( Capacitor const Component1, Capacitor const Component2)
{
    return Component1.getValue() == Component2.getValue();
}

/**
 * Operator for comparing two Capacitors.
 * <p>
 * Returns a bool wether the values of the Capacitors aren't
 * the same or not.
 * </p>
 *
 * @param   Component1      First Capacitor.
 * @param   Component2      Second Capacitor.
 * 
 * @return Bool if true or not.
 */
bool operator!= ( Capacitor const Component1, Capacitor const Component2)
{
    return Component1.getValue() != Component2.getValue();
}

/**
 * Operator for dividing two Capacitors.
 * <p>
 * Returns the divided size of the first Capacitor by the second one.
 * </p>
 *
 * @param   Component1      First Capacitor with value.
 * @param   Component2      Second Capacitor with value.
 * 
 * @return  Value of the result.
 */
double operator/ (
    std::shared_ptr<Capacitor> const Component1,
    std::shared_ptr<Capacitor> const Component2)
{
    return Component1->getValue() / Component2->getValue();
}

/**
 * Operator for dividing two Capacitors.
 * <p>
 * Returns the divided size of the first Capacitor by the second one.
 * </p>
 *
 * @param   Component1      First Capacitor with value.
 * @param   Component2      Second Capacitor with value.
 * 
 * @return  Value of the result.
 */
double operator/ (
    Capacitor const Component1,
    Capacitor const Component2)
{
    return Component1.getValue() / Component2.getValue();
}

