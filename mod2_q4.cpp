#include <iostream>
#include <vector>
using namespace std;

int main() {
    int r1, c1, r2, c2;
    cout << "Enter rows and columns of first matrix: ";
    cin >> r1 >> c1;
    cout << "Enter rows and columns of second matrix: ";
    cin >> r2 >> c2;
    if (c1 != r2) {
        cout << "Error: incompatible dimensions\n";
        return 0;
    }
    vector<vector<int>> A(r1, vector<int>(c1));
    vector<vector<int>> B(r2, vector<int>(c2));
    cout << "Enter first matrix values:\n";
    for (int i = 0; i < r1; ++i)
        for (int j = 0; j < c1; ++j)
            cin >> A[i][j];
    cout << "Enter second matrix values:\n";
    for (int i = 0; i < r2; ++i)
        for (int j = 0; j < c2; ++j)
            cin >> B[i][j];
    vector<vector<int>> C(r1, vector<int>(c2, 0));
    for (int i = 0; i < r1; ++i)
        for (int j = 0; j < c2; ++j)
            for (int k = 0; k < c1; ++k)
                C[i][j] += A[i][k] * B[k][j];
    cout << "Result matrix:\n";
    for (int i = 0; i < r1; ++i) {
        for (int j = 0; j < c2; ++j) cout << C[i][j] << (j + 1 == c2 ? "\n" : " ");
    }
    return 0;
}