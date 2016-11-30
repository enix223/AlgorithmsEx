#!/usr/bin/env python

import numpy as np
import matplotlib.pyplot as plt

packages = ['divide and conquery']


def plot_benchmark(filepath):
    arr = np.loadtxt(filepath, dtype={'names': ('dnc', 'es'), 'formats': ('float', 'float')}, delimiter=' ')
    x = np.arange(arr.size)
    plt.plot(x, arr['dnc'], 'g^', x, arr['es'], 'rs')
    plt.show()


if __name__ == '__main__':
    plot_benchmark('../results/benchmark_divide_and_conquer.txt')
