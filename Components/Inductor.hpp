#ifndef INDUCTOR_HPP
#define INDUCTOR_HPP

#include "Component.hpp"

class Inductor : public Component {
public:
  Inductor(double value) : Component(value) {}
};
#endif //INDUCTOR_HPP