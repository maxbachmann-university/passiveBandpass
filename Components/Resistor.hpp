#ifndef RESISTOR_HPP
#define RESISTOR_HPP

#include "Component.hpp"

class Resistor : public Component {
public:
  Resistor(double value) : Component(value) {}
};
#endif //RESISTOR_HPP