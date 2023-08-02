#include <vector>

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

class PIDArray {

private:
  unsigned int _n; // size of array
  std::vector<PID> _pid;

public:
  // Constructors
  PIDArray(unsigned int n, double proportional_gain, double integral_gain,
           double derivative_gain);

  PIDArray(unsigned int n, std::vector<double> proportional_gain,
           std::vector<double> integral_gain,
           std::vector<double> derivative_gain);

  // Destructor
  ~PIDArray();

  // Return the size of the array
  unsigned int size();

  // Compute manipuated variable (i.e. control output)
  std::vector<double> manipulated_variable(std::vector<double> set_point,
                                           std::vector<double> process_variable,
                                           double time_step);

  // Compute next
  std::vector<double> next(std::vector<double> set_point,
                           std::vector<double> process_variable,
                           double time_step);
};
