import matplotlib.pyplot as plt
import numpy as np

# Read benchmark results
sizes = []
times = []
with open("results.csv", "r") as f:
    for line in f:
        size, time = map(float, line.strip().split(","))
        sizes.append(size)
        times.append(time)


# Plot the results
plt.figure(figsize=(10, 6))
plt.plot(sizes, times, marker='o', linestyle='-', label='Merge Sort Time')
plt.xlabel("Array Size")
plt.ylabel("Time(s)")
plt.title("Merge Sort Benchmark on Centaurus")
plt.legend()
plt.grid(True, which="both", linestyle="--", linewidth=0.5)

plt.savefig("benchmark_plot.png")
plt.show()
