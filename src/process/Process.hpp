#pragma once
#include <cmath>
#include <random>
#include <vector>

namespace simulation {

class Process {
public:
  virtual std::vector<double_t> generateSequence(int T) const = 0;

private:
  virtual double realiseRandomVariable(int s, int t) const = 0;
};
} // namespace simulation
