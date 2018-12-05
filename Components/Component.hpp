#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <memory>
class Capacitor;

class Component 
{
public:
  virtual ~Component() = default;
  Component(Component&&) = default;
  Component& operator=(Component&&) = default;
  Component(const Component&) = default;
  Component& operator=(const Component&) = default;

  double getValue() const;
  void setValue(double value);

protected:
  Component() {};

private:
  double m_value = 0;

};
#endif //COMPONENT_HPP