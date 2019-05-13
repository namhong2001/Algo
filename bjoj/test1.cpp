#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;



struct RMQ { // range maximum query
    vector<int> A;
    vector<vector<int>> B;
    RMQ() {};
    RMQ(vector<int> &A) {
        this->A = A;
        int logbound = floor(log2((double)A.size()));
        B = vector<vector<int>>(A.size(), vector<int>(logbound+1));
        for (int i=0; i<=logbound; ++i) {
            for (int j=0; j<A.size(); ++j) {
                if (i == 0) {
                    B[j][i] = j;
                } else {
                    int second_idx = min(j+(int)pow(2, i-1), (int)A.size()-1);
                    if (A[B[j][i-1]] >= A[B[second_idx][i-1]]) {
                        B[j][i] = B[j][i-1];
                    } else {
                        B[j][i] = B[second_idx][i-1];
                    }
                }
            }
        }
    }
    int query(int l, int r) { // inclusive
        int sz = r-l+1;
        int logsz = floor(log2((double)sz));
        if (A[B[l][logsz]] >= A[B[r-pow(2, logsz)+1][logsz]]) {
            return B[l][logsz];
        } else {
            return B[r-pow(2, logsz)+1][logsz];
        }
    }
};

int main() {
    srand(time(nullptr));
    int n = 1e5, m = 30;
    cout << n << ' ' << m << endl;
    vector<int> arr(n);
    for (int i=0; i<n; ++i) arr[i] = i+1;
    random_device rd;
    mt19937 g(rd());
    shuffle(arr.begin(), arr.end(), g);
    RMQ rmq(arr);
    for (int i=0; i<m; ++i) {
        int l = rand()%n;
        int r = rand()%n;
        if (l > r) swap(l, r);
        int a = rmq.query(l, r);

        cout << l+1 << ' ' << r+1 << ' ' << arr[a] << endl;
    }
    return 0;
}
