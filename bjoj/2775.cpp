#include <iostream>

using namespace std;


int residents(int arr[15][15], int k, int n) {
    if (n==0 || k < 0) return 0;
    return arr[k][n] ? arr[k][n] : residents(arr, k-1, n) + residents(arr, k, n-1);
}


int main() {
    int t;
    cin >> t;
    int arr[15][15] = {0};
    for(int i=1; i<=14; ++i) {
        arr[0][i] = i;
    }

    while(t--) {
        int k, n;
        cin >> k >> n;
        cout << residents(arr, k, n) << endl;
    }
    return 0;
}

