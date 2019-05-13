#include <iostream>

using namespace std;

const int mod = 1e9;

int main() {
    int n;
    cin >> n;
    int *prev = new int[10];
    int *now = new int[10];
    for (int i=1; i<10; ++i) {
        prev[i] = 1;
    }
    prev[0] = 0;
    n--;
    while (n--) {
        for (int i=0; i<10; ++i) {
            int prev_left = i-1 >= 0 ? prev[i-1] : 0;
            int prev_right = i+1 <= 9 ? prev[i+1] : 0;
            now[i] = (prev_left + prev_right) % mod;
        }
        int *temp = prev;
        prev = now;
        now = temp;
    }
    int sum = 0;
    for (int i=0; i<10; ++i) {
        sum += prev[i];
        sum %= mod;
    }
    cout << sum;

    return 0;
}
