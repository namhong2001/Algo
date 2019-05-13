#include <iostream>
#include <cstdio>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[8001] = {0};

    for (int i=0; i<n; ++i) {
        int a;
        scanf("%d", &a);
        arr[a+4000]++;
    }
    int sum = 0;
    for (int i=0; i<8001; ++i) {
        sum += arr[i]*i;
    }
    cout << fixed << setprecision(0) << (double)sum / n - 4000 << '\n';
    int median = -1;
    int c = 0;
    while(c <= n/2) {
         ++median;
        c += arr[median];
    }
    cout << median - 4000 << '\n';

    vector<int> maxFreq;
    int maxC = 0;
    for(int i=0; i<8001; ++i) {
        if (arr[i] > maxC) {
            maxC = arr[i];
        }
    }
    for (int i=0; i<8001; ++i) {
        if (arr[i] == maxC) {
            maxFreq.push_back(i);
        }
    }
    sort(maxFreq.begin(), maxFreq.end());
    if (maxFreq.size() == 1) {
        cout << maxFreq[0] - 4000 << '\n';
    } else {
        cout << maxFreq[1] - 4000 << '\n';
    }

    int maxN;
    int minN;
    for (int i=0; i<8001; ++i) {
        if (arr[i]) {
            minN = i;
            break;
        }
    }
    for (int i=8001-1; i>=0; --i) {
        if (arr[i]) {
            maxN = i;
            break;
        }
    }
    cout << maxN - minN << '\n';
    return 0;
}
