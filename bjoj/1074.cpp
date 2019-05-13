#include <iostream>
#include <cmath>

using namespace std;


int solve (int n, int r, int c) {
    if (n == 0) return 0;
    int half = pow(2, n-1);
    int cnt = 0;
    for (int i=half; i<=pow(2, n); i+=half) {
        for (int j=half; j<=pow(2, n); j+=half) {
            if (r <= i && c <= j) {
                return cnt+solve(n-1, r-i+half, c-j+half);
            }
            cnt += half*half;
        }
    }
}

int main() {
    int n, r, c;
    cin >> n >> r >> c;
    cout << solve(n, r+1, c+1);
    return 0;
}
