#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        int arr[n];
        for(int i=0; i<n; ++i) {
            cin >> arr[i];
        }
        int cnt = 0;
        int pri = 999;
        for(int i=0; i<n; ++i) {
            if (arr[i] > arr[m]) cnt++;
            if (arr[i] == arr[m] && i < m) cnt++;

        }
        cout << cnt + 1 << '\n';
    }

    return 0;
}
