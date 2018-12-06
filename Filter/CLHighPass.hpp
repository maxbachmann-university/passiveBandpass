#ifndef CLHIGHPASS_HPP
#define CLHIGHPASS_HPP

#include "PassFilter.hpp"

class CLHighPass: public PassFilter
{
public:
  double Frequency() const override;

  CLHighPass(double firstComponent, double secondComponent);
  //CLHighPass(std::shared_ptr<Component> m_firstComponent, std::shared_ptr<Component> m_secondComponent;);
};
#endif //RLHIGHPASS_HPP

