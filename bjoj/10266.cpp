#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr1(n);
    vector<int> arr2(n);
    for (int i=0; i<n; ++i) {
        scanf(" %d", &arr1[i]);
    }
    for (int i=0; i<n; ++i) {
        scanf(" %d", &arr2[i]);
    }

    if (arr1[0] == 0) {
        arr1[0] = 360000;
    }
    if (arr2[0] == 0) {
        arr2[0] = 360000;
    }
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());



    int arr1_0 = arr1[0];
    for (int i=0; i<n-1; ++i) {
        arr1[i] = arr1[i+1] - arr1[i];
    }
    arr1[n-1] = arr1_0 + 360000 - arr1[n-1];



    int arr2_0 = arr2[0];
    for (int i=0; i<n-1; ++i) {
        arr2[i] = arr2[i+1] - arr2[i];
    }
    arr2[n-1] = arr2_0 + 360000 - arr2[n-1];

    int cnt = 0;
    for (cnt=0; cnt<n; ++cnt) {
        if (arr1[cnt] != arr2[cnt]) {
            break;
        }
    }
    if (cnt == n) {
        cout << "possible";
    } else {
        cout << "impossible";
    }
    return 0;
}
