#include "pid.hpp"
#include <fstream>

int main() {

  std::ofstream file("hello_pid_array.csv");

  std::vector<double> Kp = {10., 5., 1.};
  std::vector<double> Ki = {0.1, 0.1, 0.1};
  std::vector<double> Kd = {0.01, 0.01, 0.01};
  PIDArray pid_array(3, Kp, Ki, Kd);

  std::vector<double> set_point = {1.0, 1.0, 1.0};
  std::vector<double> process_variable = {0.2, 0.5, 0.8};

  double time_step = 0.1;
  double time = 0.0;

  int n_steps = 20;

  file << "t,sp1,pv1,sp2,pv2,sp3,pv3\n";
  file << time << ",";
  for (unsigned int i = 0; i < 3; ++i) {
    file << set_point[i] << "," << process_variable[i];
    if (i < 2)
      file << ",";
    else
      file << "\n";
  }

  for (unsigned int i = 0; i < n_steps; ++i) {
    process_variable = pid_array.next(set_point, process_variable, time_step);
    time += time_step;

    if (time > 1.)
      set_point = {0.1, 0.4, 0.5};

    file << time << ",";
    for (unsigned int i = 0; i < 3; ++i) {
      file << set_point[i] << "," << process_variable[i];
      if (i < 2)
        file << ",";
      else
        file << "\n";
    }
  }

  file.close();

  return 0;
}
