#include "Component.hpp"

#ifndef CAPACITOR_HPP
#define CAPACITOR_HPP

class Capacitor : public Component {
public:
  Capacitor(double value) : Component(value) {}
};
#endif //CAPACITOR_HPP