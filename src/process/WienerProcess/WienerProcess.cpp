#include "WienerProcess.hpp"
namespace simulation {
std::vector<double> WienerProcess::generateSequence(int T) const {
  if (T < 1) {
    throw new std::runtime_error("T should be equal or bigger than 1");
  }
  if (_sigma < 0) {
    throw new std::runtime_error("Square_sigma couldn't be less than zero");
  }
  std::vector<double> sequence(T);
  sequence[0] = 0;
  for (int i = 1; i < T; ++i) {
    sequence[i] = realiseRandomVariable(i - 1, i);
  }
  return sequence;
}
double WienerProcess::realiseRandomVariable(int s, int t) const {
  std::random_device rd{};
  std::mt19937 gen{rd()};

  std::normal_distribution<> distribution{0, _sigma * std::abs(s - t)};
  return distribution(gen);
}
} // namespace simulation