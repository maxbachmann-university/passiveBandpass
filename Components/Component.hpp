#ifndef COMPONENT_HPP
#define COMPONENT_HPP

class Component {
public:
  virtual ~Component() = default; // Virtual destructor needed, because the derived classes are only accessed via a pointer to this class
  Component(Component&&) = default; // Defining a destructor disables the default move constructor ...
  Component& operator=(Component&&) = default; // ... and the corresponding assignment operator
  Component(const Component&) = default; // Defining a move constructor disables the default copy constructor ...
  Component& operator=(const Component&) = default; // ... and the corresponding assignment operator

  double returnValue() {return m_value; } const
  void setValue(double value) { m_value = value; }

protected:
  Component() {};
  Component(double value) : m_value(value) {};

private:
  double m_value = 0;

};
#endif //COMPONENT_HPP