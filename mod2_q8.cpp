#include <iostream>
#include <string>
using namespace std;

bool localVerify(const string &attempt) {
    const string secret = "1234";
    return attempt == secret;
}

int main() {
    for (int code = 0; code <= 9999; ++code) {
        string attempt = to_string(code);
        while (attempt.size() < 4) attempt = "0" + attempt;
        if (localVerify(attempt)) {
            cout << "Local simulation found OTP: " << attempt << "\n";
            break;
        }
    }
    return 0;
}