#include "Component.hpp"

#ifndef INDUCTOR_HPP
#define INDUCTOR_HPP

class Inductor : public Component {
public:
  Inductor(double value) : Component(value) {}
};
#endif //INDUCTOR_HPP