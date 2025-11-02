#include <iostream>
#include <vector>
#include <string>
using namespace std;

void generatePermutations(vector<string> &arr, int start) {
    if (start == arr.size() - 1) {
        for (int i = 0; i < arr.size(); ++i) cout << arr[i] << (i + 1 == arr.size() ? "\n" : " ");
        return;
    }
    for (int i = start; i < arr.size(); ++i) {
        swap(arr[start], arr[i]);
        generatePermutations(arr, start + 1);
        swap(arr[start], arr[i]);
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<string> arr(n);
    cout << "Enter elements separated by space:\n";
    for (int i = 0; i < n; ++i) cin >> arr[i];
    generatePermutations(arr, 0);
    return 0;
}