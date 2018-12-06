#ifndef CRHIGHPASS_HPP
#define CRHIGHPASS_HPP

#include "HighPass.hpp"

class CRHighPass: public HighPass {
public:
  double Frequency() const override;

  CRHighPass(double firstComponent, double secondComponent);
};
#endif //CRHIGHPASS_HPP

