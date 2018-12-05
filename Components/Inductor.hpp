#ifndef INDUCTOR_HPP
#define INDUCTOR_HPP

#include "Component.hpp"

class Inductor : public Component 
{
public:
  explicit Inductor(double value);

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