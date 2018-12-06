#ifndef CRHIGHPASS_HPP
#define CRHIGHPASS_HPP

#include "PassFilter.hpp"

class CRHighPass: public PassFilter {
public:
  double Frequency() const override;

  CRHighPass(double firstComponent, double secondComponent);
};
#endif //CRHIGHPASS_HPP

