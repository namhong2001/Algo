#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int N_MAX = 100;
const int K_MAX = 10000;

int cases(int money, int begin, vector<int> &value) {
    int coin = value[begin];
    if (money == 0) return 1;
    if (begin == value.size()-1) {
        if (money % coin) return 0;
        else return 1;
    }

    int ret = 0;
    for (int i=0; i*coin <= money; ++i) {
        ret += cases(money-i*coin, begin+1, value);
    }
    return ret;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> value;
    for (int i=0; i<n; ++i) {
        int v;
        cin >> v;
        value.push_back(v);
    }
    sort(value.begin(), value.end(), greater<int>());
    cout << cases(k, 0, value);
    return 0;
}
