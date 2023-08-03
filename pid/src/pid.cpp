#include "pid.hpp"

namespace PID {

PID::PID(double proportional_gain, double integral_gain, double derivative_gain)
    : _proportional_gain(proportional_gain), _integral_gain(integral_gain),
      _derivative_gain(derivative_gain), _integral(0.0), _prev_error(0.0) {}

PID::~PID() {}

double PID::manipulated_variable(double set_point, double process_variable,
                                 double time_step) {

  // Calculate error
  double error = set_point - process_variable;

  // Proportional term
  double P = _proportional_gain * error;

  // Integral term
  _integral += error * time_step;
  double I = _integral_gain * _integral;

  // Derivative term
  double derivative = (error - _prev_error) / time_step;
  double D = _derivative_gain * derivative;

  // Calculate manipulated variable
  double manip_variable = P + I + D;

  // Save error to previous error
  _prev_error = error;

  return manip_variable;
}

double PID::next(double set_point, double process_variable, double time_step) {
  double mv = manipulated_variable(set_point, process_variable, time_step);
  return process_variable + time_step * mv;
}

} // namespace PID
