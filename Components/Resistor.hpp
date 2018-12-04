#include "Component.hpp"

#ifndef RESISTOR_HPP
#define RESISTOR_HPP

class Resistor : public Component {
public:
  Resistor(double value) : Component(value) {}
};
#endif //RESISTOR_HPP