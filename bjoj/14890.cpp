#include <iostream>

using namespace std;

int main() {
    int n, l;
    cin >> n >> l;
    int arr[n][n];
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            cin >> arr[i][j];
        }
    }
    int way = 0;
    for (int i=0; i<n; ++i) {
        int seq = 1;
        int j;
        for (j=1; j<n; ++j) {
            if (arr[i][j] == arr[i][j-1]) seq++;
            else if (arr[i][j] == arr[i][j-1]+1) {
                if (seq >= l) seq = 1;
                else break;
            } else if (arr[i][j] == arr[i][j-1]-1) {
                if (seq >= 0) seq = -1 * l + 1;
                else break;
            } else {
                break;
            }
        }
        if (j == n && seq >= 0) {
            way++;
        }


        seq = 1;
        for (j=1; j<n; ++j) {
            if (arr[j][i] == arr[j-1][i]) seq++;
            else if (arr[j][i] == arr[j-1][i]+1) {
                if (seq >= l) seq = 1;
                else break;
            } else if (arr[j][i] == arr[j-1][i]-1) {
                if (seq >= 0) seq = -1 * l + 1;
                else break;
            } else {
                break;
            }
        }
        if (j == n && seq >= 0) {
            way++;
        }
    }
    cout << way;
    return 0;
}
