
class PID {

private:
  double _proportional_gain;
  double _integral_gain;
  double _derivative_gain;
  double _integral;   // integral accumulated over time
  double _prev_error; // error from previous time step

public:
  // Constructor
  PID(double proportional_gain, double integral_gain, double derivative_gain);

  // Destructor
  ~PID();

  // Compute manipuated variable (i.e. control output)
  double manipulated_variable(double set_point, double process_variable,
                              double time_step);

  // Compute next
  double next(double set_point, double process_variable, double time_step);
};
