#include "pid.hpp"

namespace PID {

PIDArray::PIDArray(unsigned int n, double proportional_gain,
                   double integral_gain, double derivative_gain)
    : _n(n) {

  for (unsigned int i = 0; i < n; ++i)
    _pid.push_back(PID(proportional_gain, integral_gain, derivative_gain));
}

PIDArray::PIDArray(unsigned int n, std::vector<double> proportional_gain,
                   std::vector<double> integral_gain,
                   std::vector<double> derivative_gain)
    : _n(n) {

  for (unsigned int i = 0; i < n; ++i)
    _pid.push_back(
        PID(proportional_gain[i], integral_gain[i], derivative_gain[i]));
}

PIDArray::~PIDArray() {}

unsigned int PIDArray::size() { return _n; }

std::vector<double>
PIDArray::manipulated_variable(std::vector<double> set_point,
                               std::vector<double> process_variable,
                               double time_step) {

  std::vector<double> mv(_n);
  for (unsigned int i = 0; i < _n; ++i) {
    mv.push_back(_pid[i].manipulated_variable(set_point[i], process_variable[i],
                                              time_step));
  }

  return mv;
}

std::vector<double> PIDArray::next(std::vector<double> set_point,
                                   std::vector<double> process_variable,
                                   double time_step) {

  for (unsigned int i = 0; i < _n; ++i) {
    process_variable[i] =
        _pid[i].next(set_point[i], process_variable[i], time_step);
  }

  return process_variable;
}

} // namespace PID
