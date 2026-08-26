#include <benchmark/benchmark.h>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include "src/linked_list.h"

// Builds a nearly-sorted list: sorted sequence with ~1% of elements swapped.
static LinkedList makeNearlySorted(int n) {
    std::vector<int> data(n);
    for (int i = 0; i < n; i++) data[i] = i;

    int swaps = std::max(1, (n * 8) / 10);
    for (int i = 0; i < swaps; i++) {
        int a = rand() % (n - 1);
        std::swap(data[a], data[a + 1]);
    }

    LinkedList list;
    for (int i = n - 1; i >= 0; i--)
        list.insertAtHead(data[i]);
    return list;
}

static void BM_InsertionSort(benchmark::State &state) {
    auto n = state.range(0);
    for (auto _ : state) {
        LinkedList list = makeNearlySorted(n);
        list.insertionSort();
    }
}

static void BM_OptimizedInsertionSort(benchmark::State &state) {
    auto n = state.range(0);
    for (auto _ : state) {
        LinkedList list = makeNearlySorted(n);
        list.optimizedInsertionSort();
    }
}

BENCHMARK(BM_InsertionSort)->Arg(1000)->Arg(5000)->Arg(10000)->Arg(20000);
BENCHMARK(BM_OptimizedInsertionSort)->Arg(1000)->Arg(5000)->Arg(10000)->Arg(20000);

BENCHMARK_MAIN();
