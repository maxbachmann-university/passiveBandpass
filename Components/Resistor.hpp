/** @file */
#ifndef RESISTOR_HPP
#define RESISTOR_HPP

#include "Component.hpp"

/**
 * @brief       Class for a Resistor.
 * @details     This class contains a value and operators for counting them.
 * @author      Maximilian Bachmann <bachmann.maxim-tfe17@it.dhbw-ravensburg.de>
 * @author      Felix Bandle <bandle.felix-tfe17@it.dhbw-ravensburg.de>
 * @author      Florian Vetter <vetter.florian-tfe17@it.dhbw-ravensburg.de>
 */
class Resistor : public Component 
{
public:
  explicit Resistor(double value);    //!< Value of the Resistor.

  friend std::unique_ptr<Resistor> operator+ (
    std::shared_ptr<Resistor> const Component1,
    std::shared_ptr<Resistor> const Component2);

  friend std::unique_ptr<Resistor> operator- (
    std::shared_ptr<Resistor> const Component1,
    std::shared_ptr<Resistor> const Component2);

  friend double operator/ (
    std::shared_ptr<Resistor> const Component1,
    std::shared_ptr<Resistor> const Component2);
};
#endif //RESISTOR_HPP

