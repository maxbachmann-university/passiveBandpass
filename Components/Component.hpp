/** @file */
#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <memory>
class Capacitor;

/**
 * @brief       Class Components for inheriting basic operators and functions to its childs.
 * @details     This class provides some of the basic operators and functions to its childs: 
 *              Resistor, Capacitor and Inductor.
 * @author      Maximilian Bachmann <bachmann.maxim-tfe17@it.dhbw-ravensburg.de>
 * @author      Felix Bandle <bandle.felix-tfe17@it.dhbw-ravensburg.de>
 * @author      Florian Vetter <vetter.florian-tfe17@it.dhbw-ravensburg.de>
 */
class Component 
{
public:

  virtual ~Component() = default;
  Component(Component&&) = default;
  Component& operator=(Component&&) = default;
  Component(const Component&) = default;
  Component& operator=(const Component&) = default;

  double getValue() const;
  void setValue(double value);

protected:
  Component() {};

private:
  double m_value = 0;    //!< Value of the Component.

};
#endif //COMPONENT_HPP