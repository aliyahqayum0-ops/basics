import csv
import matplotlib.pyplot as plt

sizes = []
insertion_times = []
optimized_times = []

with open("results.csv") as f:
    # skip non-CSV preamble lines before the header
    lines = [l for l in f if l.startswith('"BM_') or l.startswith("name,")]
    reader = csv.DictReader(lines)
    for row in reader:
        name = row["name"]
        time_ns = float(row["real_time"])
        n = int(name.split("/")[1])
        if "BM_InsertionSort/" in name:
            sizes.append(n)
            insertion_times.append(time_ns / 1e6)  # convert to ms
        elif "BM_OptimizedInsertionSort/" in name:
            optimized_times.append(time_ns / 1e6)

plt.figure()
plt.plot(sizes, insertion_times, marker="o", label="Insertion Sort O(n²)")
plt.plot(sizes, optimized_times, marker="o", label="Optimized Insertion Sort")
plt.xlabel("Input Size (n)")
plt.ylabel("Time (ms)")
plt.title("Insertion Sort vs Optimized Insertion Sort on Linked List")
plt.legend()
plt.tight_layout()
plt.savefig("sort_comparison.png")
print("Plot saved to sort_comparison.png")
