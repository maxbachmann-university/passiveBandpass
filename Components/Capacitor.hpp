#ifndef CAPACITOR_HPP
#define CAPACITOR_HPP

#include "Component.hpp"

class Capacitor : public Component {
public:
  Capacitor(double value) : Component(value) {}
};
#endif //CAPACITOR_HPP