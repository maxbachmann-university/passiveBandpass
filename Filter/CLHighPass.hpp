#ifndef CLHIGHPASS_HPP
#define CLHIGHPASS_HPP

#include "HighPass.hpp"

class CLHighPass: public HighPass 
{
public:
  double Frequency() const override;

  CLHighPass(double firstComponent, double secondComponent);
  //CLHighPass(std::shared_ptr<Component> m_firstComponent, std::shared_ptr<Component> m_secondComponent;);
};
#endif //RLHIGHPASS_HPP