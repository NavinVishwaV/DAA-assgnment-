#include <iostream>
#include <vector>
#include <string>
using namespace std;

void chooseRecursive(const vector<string> &arr, int start, int r, vector<string> &buffer) {
    if (r == 0) {
        for (int i = 0; i < buffer.size(); ++i) cout << buffer[i] << (i + 1 == buffer.size() ? "\n" : " ");
        return;
    }
    for (int i = start; i <= arr.size() - r; ++i) {
        buffer.push_back(arr[i]);
        chooseRecursive(arr, i + 1, r - 1, buffer);
        buffer.pop_back();
    }
}

int main() {
    int n, r;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<string> arr(n);
    cout << "Enter elements:\n";
    for (int i = 0; i < n; ++i) cin >> arr[i];
    cout << "Enter r (size of combinations): ";
    cin >> r;
    vector<string> buffer;
    chooseRecursive(arr, 0, r, buffer);
    return 0;
}