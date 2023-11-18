#include <fstream>

#include "pid/pid.hpp"

int main() {

  std::ofstream file("hello_pid_array.csv");

  const double Kp[3] = {10., 5., 1.};
  const double Ki[3] = {0.1, 0.1, 0.1};
  const double Kd[3] = {0.01, 0.01, 0.01};
  pid_control::PID pid[3];

  for (unsigned int i = 0; i < 3; ++i)
    pid[i].set_gains(Kp[i], Ki[i], Kd[i]);

  double set_point[3] = {1.0, 1.0, 1.0};
  double process_variable[3] = {0.2, 0.5, 0.8};

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

  for (unsigned int t = 0; t < n_steps; ++t) {

    for (unsigned int i = 0; i < 3; ++i) {
      process_variable[i] =
          pid[i].next(set_point[i], process_variable[i], time_step);
    }

    time += time_step;

    if (time > 1.) {
      double new_set_point[3] = {0.1, 0.4, 0.5};
      for (unsigned i = 0; i < 3; ++i)
        set_point[i] = new_set_point[i];
    }

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
