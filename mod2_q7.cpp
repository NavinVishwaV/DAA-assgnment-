#include <iostream>
#include <vector>
using namespace std;

void combineCheck(const vector<int> &indices, int start, int r, const vector<int> &weight, const vector<int> &value, int capacity, vector<int> &buffer, long long &bestValue, vector<int> &bestSet) {
    if (r == 0) {
        int sumW = 0, sumV = 0;
        for (int idx : buffer) {
            sumW += weight[idx];
            sumV += value[idx];
        }
        if (sumW <= capacity && sumV > bestValue) {
            bestValue = sumV;
            bestSet = buffer;
        }
        return;
    }
    for (int i = start; i <= (int)indices.size() - r; ++i) {
        buffer.push_back(indices[i]);
        combineCheck(indices, i + 1, r - 1, weight, value, capacity, buffer, bestValue, bestSet);
        buffer.pop_back();
    }
}

int main() {
    const int N = 6;
    vector<int> weight(N), value(N);
    cout << "Enter weight and value for 6 items:\n";
    for (int i = 0; i < N; ++i) cin >> weight[i] >> value[i];
    int capacity;
    cout << "Enter knapsack capacity: ";
    cin >> capacity;
    vector<int> indices(N);
    for (int i = 0; i < N; ++i) indices[i] = i;
    long long bestValue = 0;
    vector<int> bestSet;
    for (int r = 1; r <= N; ++r) {
        vector<int> buffer;
        combineCheck(indices, 0, r, weight, value, capacity, buffer, bestValue, bestSet);
    }
    cout << "Maximum value: " << bestValue << "\n";
    cout << "Selected items: ";
    for (int i = 0; i < bestSet.size(); ++i) cout << bestSet[i] << (i + 1 == bestSet.size() ? "\n" : " ");
    return 0;
}