#include <iostream>
#include <cmath>

using namespace std;

int main() {
    while(true) {
        int n;
        cin >> n;

        if (n == 0) break;

        bool arr[2*n+1] = {false};
        arr[0] = true;
        arr[1] = true;
        for (int i=2; i<=(int)ceil(sqrt(2*n)); ++i) {
            for (int j=i; i*j<=2*n; ++j) {
                arr[i*j] = true;
            }
        }

        int cnt = 0;
        for (int i=n+1; i<=2*n; ++i) {
            if (!arr[i]) {
                ++cnt;
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}


