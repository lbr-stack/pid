#include "pid.hpp"
#include <iostream>

int main() {

  PID pid(4., 0.01, 0.1);

  double set_point = 1.0;
  double time_step = 0.1;
  double process_variable = 0.2;

  int n_steps = 20;

  std::cout << "x(0) = " << process_variable << "\n";

  for (unsigned int i = 0; i < n_steps; ++i) {
    double control =
        pid.manipulated_variable(set_point, process_variable, time_step);
    process_variable += control * time_step;
    std::cout << "x(" << i + 1 << ") = " << process_variable << "\n";
  }

  return 0;
}
