#pragma once
#include "../Process.hpp"

namespace simulation {
class CompositePoissonProcess : public Process {
public:
  explicit CompositePoissonProcess(double lambda) : _lambda(lambda) {}

  std::vector<double> generateSequence(int T) const override ;

private:
  double _lambda = 1;

  double realiseRandomVariable(int s, int t) const override;
};

} // namespace simulation