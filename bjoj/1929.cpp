#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    bool arr[n+1] = {false};
    arr[0] = true;
    arr[1] = true;
    for (int i=2; i<=(int)ceil(sqrt(n)); ++i) {
        for (int j=i; i*j<=n; ++j) {
            arr[i*j] = true;
        }
    }
    for (int i=m; i<=n; ++i) {
        if (!arr[i]) {
            cout << i << '\n';
        }
    }
    return 0;
}

