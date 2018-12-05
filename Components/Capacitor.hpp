#ifndef CAPACITOR_HPP
#define CAPACITOR_HPP

#include "Component.hpp"

class Capacitor : public Component 
{
public:
  Capacitor(double value);

  /*friend std::unique_ptr<Capacitor> operator+ (
    std::shared_ptr<Capacitor> const Component1,
    std::shared_ptr<Capacitor> const Component2);

  friend std::unique_ptr<Capacitor> operator- (
    std::shared_ptr<Capacitor> const Component1,
    std::shared_ptr<Capacitor> const Component2);

  friend double operator/ (
    std::shared_ptr<Capacitor> const Component1,
    std::shared_ptr<Capacitor> const Component2);*/
};
#endif //CAPACITOR_HPP