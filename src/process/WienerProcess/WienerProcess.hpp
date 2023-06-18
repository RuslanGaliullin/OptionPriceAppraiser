#pragma once
#include "../Process.hpp"

namespace simulation {

class WienerProcess : public Process {
public:
  explicit WienerProcess(double sigma) : _sigma(sigma) {}

  std::vector<double> generateSequence(int T) const override;

private:
  double _sigma = 1;

  [[nodiscard]] double realiseRandomVariable(int s, int t) const override;
};

} // namespace simulation
