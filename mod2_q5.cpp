#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    const int N = 5;
    vector<vector<int>> dist(N, vector<int>(N));
    cout << "Enter 5x5 distance matrix (row by row):\n";
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> dist[i][j];
    vector<int> cities;
    for (int i = 1; i < N; ++i) cities.push_back(i);
    long long bestCost = LLONG_MAX;
    vector<int> bestRoute;
    do {
        long long cost = 0;
        int current = 0;
        for (int v : cities) {
            cost += dist[current][v];
            current = v;
        }
        cost += dist[current][0];
        if (cost < bestCost) {
            bestCost = cost;
            bestRoute.clear();
            bestRoute.push_back(0);
            for (int v : cities) bestRoute.push_back(v);
            bestRoute.push_back(0);
        }
    } while (next_permutation(cities.begin(), cities.end()));
    cout << "Best cost: " << bestCost << "\n";
    cout << "Route: ";
    for (int i = 0; i < bestRoute.size(); ++i) cout << bestRoute[i] << (i + 1 == bestRoute.size() ? "\n" : " ");
    return 0;
}