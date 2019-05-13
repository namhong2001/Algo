#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>

using namespace std;
const int N_MAX = 5e5;
const int start = 100;

int main() {
    int n, m;
    cin >> n >> m;
    bool is_broken[10] = {};
    for (int i=0; i<m; ++i) {
        int a;
        cin >> a;
        is_broken[a] = true;
    }
    int upper_num_cnt = 987654321;;
    for (int i=n; i<=N_MAX*2; ++i) {
        int candi = i;
        bool possible = true;
        while (candi > 0) {
            if (is_broken[candi%10]) {
                possible = false;
                break;
            }
            candi /= 10;
        }
        if (i == 0 && is_broken[0]) possible = false;
        if (possible) {
           upper_num_cnt = to_string(i).size() + i - n;
           break;
        }
    }
    int lower_num_cnt = 987654321;;
    for (int i=n-1; i>=0; --i) {
        int candi = i;
        bool possible = true;
        while (candi > 0) {
            if (is_broken[candi%10]) {
                possible = false;
                break;
            }
            candi /= 10;
        }
        if (i == 0 && is_broken[0]) possible = false;
        if (possible) {
           lower_num_cnt = to_string(i).size() + n - i;
           break;
        }
    }
    cout << min({upper_num_cnt, lower_num_cnt, abs(n-100)});

    return 0;
}
