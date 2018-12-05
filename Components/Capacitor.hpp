#ifndef CAPACITOR_HPP
#define CAPACITOR_HPP

#include "Component.hpp"

class Capacitor : public Component 
{
public:
  Capacitor(double value) : Component(value) {}

  friend std::unique_ptr<Capacitor> operator+ (
    std::shared_ptr<Capacitor> const Component1,
    std::shared_ptr<Capacitor> const Component2)
  {
    return std::make_unique<Capacitor>( 
      Component1->returnValue() 
      + Component2->returnValue() );
  }

  friend std::unique_ptr<Capacitor> operator- (
    std::shared_ptr<Capacitor> const Component1,
    std::shared_ptr<Capacitor> const Component2)
  {
    return std::make_unique<Capacitor>( 
      Component1->returnValue() 
      - Component2->returnValue() );
  }

  friend double operator/ (
    std::shared_ptr<Capacitor> const Component1,
    std::shared_ptr<Capacitor> const Component2)
  {
    return Component1->returnValue() / Component2->returnValue();
  }
};
#endif //CAPACITOR_HPP