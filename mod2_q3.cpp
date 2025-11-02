#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int number;
    cout << "Enter an integer: ";
    cin >> number;
    unsigned int n = static_cast<unsigned int>(number);
    string binary;
    if (n == 0) binary = "0";
    else {
        while (n > 0) {
            binary.push_back((n % 2) ? '1' : '0');
            n /= 2;
        }
        reverse(binary.begin(), binary.end());
    }
    srand(static_cast<unsigned int>(time(nullptr)));
    int pos = rand() % binary.size();
    cout << "Binary representation: " << binary << "\n";
    cout << "Selected position (0-based): " << pos << "\n";
    cout << "Bit at position: " << binary[pos] << "\n";
    cout << (binary[pos] == '1' ? "true\n" : "false\n");
    return 0;
}