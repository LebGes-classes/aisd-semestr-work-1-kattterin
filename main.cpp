#include <iostream>
#include <iomanip>
#include <chrono>
#include <vector>
#include <random>
#include "fenwiktree.h"

using namespace std;
using namespace std::chrono;

void printTableRow(int size, double build_time, double sum_time, double range_time) {
    cout << left << setw(10) << size
         << setw(15) << fixed << setprecision(2) << build_time
         << setw(15) << setprecision(2) << sum_time
         << setw(15) << setprecision(2) << range_time << endl;
}

int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 1000);

    //Headlines
    cout << left
        << setw(10) << "Size"
        << setw(15) << "Build(ms)"
        << setw(15) << "Sum(μs)"
        << setw(15) << "Range(μs)" << endl;

    vector<int> sizes = {10, 100, 1000, 10000, 100000};

    for (int size : sizes) {
        // Izmereniye vremeni postroyeniya
        auto start = high_resolution_clock::now();
        FenwikTree ft(size);
        
        // Zapolneniye dereva sluchaynymi znacheniyami
        for (int j = 0; j < size; j++) {
            ft.update(j, dist(gen));
        }
        auto build_time = duration_cast<milliseconds>(high_resolution_clock::now() - start).count();

        // Izmereniye vremeni operatsii sum
        int test_index = size / 2;
        start = high_resolution_clock::now();
        int sum_result = ft.sum(test_index);
        auto sum_time = duration_cast<microseconds>(high_resolution_clock::now() - start).count();

        // Izmereniye vremeni operatsii rangeSum
        int l = size / 4;
        int r = 3 * size / 4;
        start = high_resolution_clock::now();
        int range_result = ft.rangeSum(l, r);
        auto range_time = duration_cast<microseconds>(high_resolution_clock::now() - start).count();

        printTableRow(size, build_time, sum_time, range_time);
    }

    return 0;
}