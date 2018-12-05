#ifndef RESISTOR_HPP
#define RESISTOR_HPP

#include "Component.hpp"

class Resistor : public Component 
{
public:
  explicit Resistor(double value);

  friend std::unique_ptr<Resistor> operator+ (
    std::shared_ptr<Resistor> const Component1,
    std::shared_ptr<Resistor> const Component2);

  friend std::unique_ptr<Resistor> operator- (
    std::shared_ptr<Resistor> const Component1,
    std::shared_ptr<Resistor> const Component2);

  friend double operator/ (
    std::shared_ptr<Resistor> const Component1,
    std::shared_ptr<Resistor> const Component2);
};
#endif //RESISTOR_HPP