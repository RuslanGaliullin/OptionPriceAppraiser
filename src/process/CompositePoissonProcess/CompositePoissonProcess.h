#pragma once

namespace model_simulation {
class CompositePoissonProcess {
public:
  //  WienerProcess(uin64 T, double _sigma) : _T(T), _sigma(double) {}

  static std::vector<double> generateSequence(uin64 T, double lambda) const {
    if (T < 1) {
      throw new std::runtime_error("T should be equal or bigger than 1");
    }
    if (lambda <= 0) {
      throw new std::runtime_error("lambda should be bigger than 0");
    }
    std::vector<double> sequence(T);
    sequence[0] = 0;
    for (uint64_t i = 1; i < T; ++i) {
      sequence[i] = realiseRandomVariable(sigma, i - 1, i);
    }
    return sequence;
  }

private:
  static double realiseRandomVariable(double lambda, int s, int t) {
    std::random_device rd;
    std::mt19937 gen(rd());

    std::poisson_distribution<double> d(lambda * std::abs(t, s));
    return distribution(gen);
  }
  uint64_t _T;
  double _sigma
};

} // namespace model_simulation