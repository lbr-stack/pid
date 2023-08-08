#include "pid.hpp"
#include <fstream>
#include <iostream>

int main() {

  std::ofstream file("hello_pid.csv");

  PIDControl::PID pid(4., 0.01, 0.1);

  double set_point = 1.0;
  double process_variable = 0.2;

  double time_step = 0.1;
  double time = 0.0;

  int n_steps = 20;

  file << "t,sp,pv\n";
  file << time << "," << set_point << "," << process_variable << "\n";

  std::cout << "x(0) = " << process_variable << "\n";

  for (unsigned int i = 0; i < n_steps; ++i) {
    process_variable = pid.next(set_point, process_variable, time_step);
    time += time_step;
    file << time << "," << set_point << "," << process_variable << "\n";
    std::cout << "x(" << i + 1 << ") = " << process_variable << "\n";
  }

  file.close();

  return 0;
}
