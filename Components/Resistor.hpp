#ifndef RESISTOR_HPP
#define RESISTOR_HPP

#include "Component.hpp"

class Resistor : public Component 
{
public:
  Resistor(double value) : Component(value) {}

  friend std::unique_ptr<Resistor> operator+ (
    std::shared_ptr<Resistor> const Component1,
    std::shared_ptr<Resistor> const Component2)
  {
    return std::make_unique<Resistor>(
      Component1->returnValue() 
      + Component2->returnValue() );
  }

  friend std::unique_ptr<Resistor> operator- (
    std::shared_ptr<Resistor> const Component1,
    std::shared_ptr<Resistor> const Component2)
  {
    return std::make_unique<Resistor>( 
      Component1->returnValue() 
      - Component2->returnValue() );
  }

  friend double operator/ (
    std::shared_ptr<Resistor> const Component1,
    std::shared_ptr<Resistor> const Component2)
  {
    return Component1->returnValue() / Component2->returnValue();
  }
};
#endif //RESISTOR_HPP