#pragma once

#include <iostream>

namespace pid_control {

class PID {

private:
  bool _ready;      // true when PID is ready to use
  double _Kp;       // proportional gain
  double _Ki;       // integral gain
  double _Kd;       // derivative gain
  double _intg;     // integral accumulated over time
  double _prev_err; // error from previous time step

public:
  // Constructor
  PID();
  PID(double Kp, // proportional gain
      double Ki, // integral gain
      double Kd  // derivative gain
  );

  // Destructor
  ~PID();

  // True when the PID controller is ready
  bool is_ready();

  // Reset PID
  void reset();

  // Set gains
  void set_gains(double Kp, // proportional gain
                 double Ki, // integral gain
                 double Kd  // derivative gain
  );

  // Compute manipuated variable (i.e. control output)
  double mv(const double &set, // set point
            const double &pv,  // process variable
            const double &dt   // time step
  );

  // Compute next process variable
  double next(const double &set, // set point
              const double &pv,  // process variable
              const double &dt   // time step
  );
};

} // namespace pid_control
