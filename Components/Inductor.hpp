/** @file */
#ifndef INDUCTOR_HPP
#define INDUCTOR_HPP

#include "Component.hpp"

/**
 * @brief       Class for a Inductor.
 * @details     This class contains a value and operators for counting them.
 * @author      Maximilian Bachmann <bachmann.maxim-tfe17@it.dhbw-ravensburg.de>
 * @author      Felix Bandle <bandle.felix-tfe17@it.dhbw-ravensburg.de>
 * @author      Florian Vetter <vetter.florian-tfe17@it.dhbw-ravensburg.de>
 */
class Inductor : public Component 
{
public:
  explicit Inductor(double value);    //!< Value of the Inductor.

  friend std::unique_ptr<Inductor> operator+ (
    std::shared_ptr<Inductor> const Component1,
    std::shared_ptr<Inductor> const Component2);

  friend std::unique_ptr<Inductor> operator- (
    std::shared_ptr<Inductor> const Component1,
    std::shared_ptr<Inductor> const Component2);

  friend double operator/ (
    std::shared_ptr<Inductor> const Component1,
    std::shared_ptr<Inductor> const Component2);
};
#endif //INDUCTOR_HPP

