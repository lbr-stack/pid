import os
import sys

try:
    import pandas as pd
except ImportError:
    print("You need to install pandas, run: pip install pandas")
    sys.exit(1)

try:
    import matplotlib.pyplot as plt
except ImportError:
    print("You need to install matplotlib, run: pip install matplotlib")
    sys.exit(1)

try:
    path = sys.argv[1]
except IndexError:
    path = "."  # use current directory


def load_data(file_name):
    csv_file_name = os.path.join(path, file_name)
    try:
        df = pd.read_csv(csv_file_name)
    except FileNotFoundError:
        print(f"Error: {file_name} not found.")
        df = None
    return df


def plot_hello_pid():
    df = load_data("hello_pid.csv")
    if df is None:
        return

    df.plot(x="t", y=["sp", "pv"])


def main():
    plot_hello_pid()
    plt.show()


if __name__ == "__main__":
    main()
