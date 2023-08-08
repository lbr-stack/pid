#include "pid.hpp"

namespace PIDControl {

PID::PID()
    : _ready(false), _Kp(0.0), _Ki(0.0), _Kd(0.0), _intg(0.0), _prev_err(0.0) {}

PID::PID(double Kp, double Ki, double Kd)
    : _ready(true), _Kp(Kp), _Ki(Ki), _Kd(Kd), _intg(0.0), _prev_err(0.0) {}

PID::~PID() {}

bool PID::is_ready() { return _ready; }

void PID::reset() {
  _intg = 0.0;
  _prev_err = 0.0;
}

void PID::set_gains(double Kp, double Ki, double Kd) {
  _Kp = Kp;
  _Ki = Ki;
  _Kd = Kd;
  _ready = true;
}

double PID::mv(const double &set, const double &pv, const double &dt) {

  // Check if the PID controller is ready
  if (!_ready) {
    std::cout << "Error: PID gains not set.\n";
    return 0.0;
  }

  // Calculate error
  double err = set - pv;

  // Proportional term
  double P = _Kp * err;

  // Integral term
  _intg += err * dt;
  double I = _Ki * _intg;

  // Derivative term
  double deriv = (err - _prev_err) / dt;
  double D = _Kd * deriv;

  // Calculate manipulated variable
  double mv = P + I + D;

  // Save error to previous error
  _prev_err = err;

  return mv;
}

double PID::next(const double &set, const double &pv, const double &dt) {
  return pv + dt * mv(set, pv, dt);
}

} // namespace PIDControl
