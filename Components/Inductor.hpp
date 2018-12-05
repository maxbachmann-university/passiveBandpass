#ifndef INDUCTOR_HPP
#define INDUCTOR_HPP

#include "Component.hpp"

class Inductor : public Component 
{
public:
  Inductor(double value) : Component(value) {}

  friend std::unique_ptr<Inductor> operator+ (
    std::shared_ptr<Inductor> const Component1,
    std::shared_ptr<Inductor> const Component2)
  {
    return std::make_unique<Inductor>( 
      Component1->returnValue() 
      + Component2->returnValue() );
  }

  friend std::unique_ptr<Inductor> operator- (
    std::shared_ptr<Inductor> const Component1,
    std::shared_ptr<Inductor> const Component2)
  {
    return std::make_unique<Inductor>( 
      Component1->returnValue() 
      - Component2->returnValue() );
  }

  friend double operator/ (
    std::shared_ptr<Inductor> const Component1,
    std::shared_ptr<Inductor> const Component2)
  {
    return Component1->returnValue() / Component2->returnValue();
  }
};
#endif //INDUCTOR_HPP