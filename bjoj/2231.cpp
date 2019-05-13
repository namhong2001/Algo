#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    int len = to_string(n).size();
    for (int i=n-9*len; i<n; ++i) {
        int sum = i;
        for (char c : to_string(i)) {
            sum += c - '0';
        }
        if (sum == n) {
            cout << i;
            return 0;
        }
    }
    cout << 0;
    return 0;
}
