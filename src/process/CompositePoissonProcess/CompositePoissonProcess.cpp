#include "CompositePoissonProcess.hpp"
namespace simulation {
std::vector<double> CompositePoissonProcess::generateSequence(int T) const {
  if (T < 1) {
    throw new std::runtime_error("T should be equal or bigger than 1");
  }
  if (_lambda <= 0) {
    throw new std::runtime_error("lambda should be bigger than 0");
  }
  std::vector<double> sequence(T);
  sequence[0] = 0;
  for (int i = 1; i < T; ++i) {
    sequence[i] = realiseRandomVariable(i - 1, i);
  }
  return sequence;
}
double CompositePoissonProcess::realiseRandomVariable(int s, int t) const {
  std::random_device rd;
  std::mt19937 gen(rd());

  std::poisson_distribution<> distribution(_lambda * std::abs(t - s));

  return distribution(gen);
}
} // namespace simulation