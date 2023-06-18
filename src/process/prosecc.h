#pragma once

namespace simulation {

class Process {
public:
  Process(uin64 T) : _T(T) {}

private:
  uint64_t _T;
};

} // namespace simulation
