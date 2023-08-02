# pid

PID controller implementation in C++.

# Build

First clone the repository
- (ssh) `git clone git@github.com:cmower/pid.git`
- (https) `git clone https://github.com/cmower/pid.git`

Then build library and examples using the following.
```
cd pid
mkdir build
cd build
cmake ..
cmake --build .
```

The example executables can be found in the `build/` directory.

## Visualize output from examples

When you run each of the examples, a CSV file is written containing the data from the example.
You can plot these by using the [plot_examples.py](plot_examples.py) script.

This script requires you to install [pandas](https://pandas.pydata.org/) and [matplotlib](https://matplotlib.org/):
```
pip install pandas matplotlib
```

You need to run the examples at least once in order to plot the results.



