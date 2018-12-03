#ifndef COMPONENT_HPP
#define COMPONENT_HPP

class Component {
public:
  virtual ~Component() = default; // Virtual destructor needed, because the derived classes are only accessed via a pointer to this class
  Component(Component&&) = default; // Defining a destructor disables the default move constructor ...
  Component& operator=(Component&&) = default; // ... and the corresponding assignment operator
  Component(const Component&) = default; // Defining a move constructor disables the default copy constructor ...
  Component& operator=(const Component&) = default; // ... and the corresponding assignment operator

  double returnValue() {return m_value; }

protected:
  Component();
  double m_value;
};
#endif //COMPONENT_HPP