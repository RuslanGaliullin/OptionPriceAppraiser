#pragma once
#include <random>
#include <vector>
namespace simulation {

class WienerProcess {
public:
  //  WienerProcess(uin64 T, double _sigma) : _T(T), _sigma(double) {}

  static std::vector<double> generateSequence(uin64 T, double sigma) const {
    if (T < 1) {
      throw new std::runtime_error("T should be equal or bigger than 1");
    }
    if (sigma < 0) {
      throw new std::runtime_error("Square_sigma couldn't be less than zero");
    }
    std::vector<double> sequence(T);
    sequence[0] = 0;
    for (uint64_t i = 1; i < T; ++i) {
      sequence[i] = realiseRandomVariable(sigma, i - 1, i);
    }
    return sequence;
  }

private:
  static double realiseRandomVariable(double sigma, int s, int t) {
    std::random_device rd{};
    std::mt19937 gen{rd()};

    std::normal_distribution<> distribution{0, sigma(std::abs(s - t))};
    return distribution(gen);
  }
  uint64_t _T;
  double _sigma
};

} // namespace simulation
