#include <iostream>
#include <cmath>

using namespace std;

int main() {
    bool arr[10001] = {false};
    arr[0] = true;
    arr[1] = true;
    for (int i=2; i<=(int)ceil(sqrt(10000)); ++i) {
        for (int j=i; i*j<=10000; ++j) {
            arr[i*j] = true;
        }
    }

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int half = n/2;
        for (int i = half; i<=n; ++i) {
            if (!arr[i] && !arr[n-i]) {
                cout << n-i << ' ' << i << '\n';
                break;
            }
        }
    }
    return 0;
}

