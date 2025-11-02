#include <iostream>
#include <vector>
using namespace std;

int main() {
    const int N = 6;
    vector<int> weight(N), value(N);
    cout << "Enter weight and value for 6 items (each line: weight value):\n";
    for (int i = 0; i < N; ++i) cin >> weight[i] >> value[i];
    int capacity;
    cout << "Enter knapsack capacity: ";
    cin >> capacity;
    long long bestValue = 0;
    vector<int> bestSet;
    int totalMasks = 1 << N;
    for (int mask = 0; mask < totalMasks; ++mask) {
        int sumW = 0, sumV = 0;
        vector<int> chosen;
        for (int i = 0; i < N; ++i) {
            if (mask & (1 << i)) {
                sumW += weight[i];
                sumV += value[i];
                chosen.push_back(i);
            }
        }
        if (sumW <= capacity && sumV > bestValue) {
            bestValue = sumV;
            bestSet = chosen;
        }
    }
    cout << "Maximum value: " << bestValue << "\n";
    cout << "Selected item indices: ";
    for (int i = 0; i < bestSet.size(); ++i) cout << bestSet[i] << (i + 1 == bestSet.size() ? "\n" : " ");
    return 0;
}