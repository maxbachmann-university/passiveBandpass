#include "Component.hpp"

#ifndef RESISTOR_HPP
#define RESISTOR_HPP

class Resistor : public Component {
public:
  Resistor(double value) : Component() {
    m_value = value;
  }
};
#endif //RESISTOR_HPP