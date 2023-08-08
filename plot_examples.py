import os
import sys

try:
    import pandas as pd
    import matplotlib.pyplot as plt

    path = sys.argv[1]
except ImportError:
    print("You need to install pandas/matplotlib, run: pip install pandas matplotlib")
    sys.exit(1)

except IndexError:
    path = "."  # use current directory


def load_data(file_name):
    try:
        df = pd.read_csv(os.path.join(path, file_name))
    except FileNotFoundError:
        print(f"Error: {file_name} not found.")
        df = None
    return df


def plot_hello_pid():
    df = load_data("hello_pid.csv")
    if df is None:
        return
    df.plot(x="t", y=["sp", "pv"])


def plot_hello_pid_array():
    df = load_data("hello_pid_array.csv")
    if df is None:
        return
    fig, ax = plt.subplots(3, 1, sharex=True)
    for i in range(3):
        df.plot(x="t", y=[f"sp{i+1}", f"pv{i+1}"], ax=ax[i])


def main():
    plot_hello_pid()
    plot_hello_pid_array()
    plt.show()


if __name__ == "__main__":
    main()
