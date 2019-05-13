#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    bool arr[10001] = {false};
    arr[0] = true;
    arr[1] = true;
    for (int i=2; i<(int)ceil(sqrt(10001)); ++i) {
        for (int j=i; i*j<10001; ++j) {
            arr[i*j] = true;
        }
    }
    int sum = 0;
    int minPrime = 0;
    for (int i=m; i<=n; ++i) {
        if (!arr[i]) {
            if (sum == 0) {
                minPrime = i;

            }
            sum += i;
        }

    }
    if (sum == 0) {
        cout << -1;
    } else {
        cout << sum << '\n' << minPrime;
    }


    return 0;
}
