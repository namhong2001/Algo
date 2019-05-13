#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;

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


ll get_cnt(RMQ &rmq_c, RMQ &rmq_d, vector<int> &C, vector<int> &D, int i, int K) {
    int N = C.size();
    int L, R, LL, RR;

    auto comp = [&]()



    int ci = C[i];

    int l = 0, r = i;
    while (l != r) {
        int mid = (l+r)/2;
        int d = rmq_d.query(mid, i);
        int c = rmq_c.query(mid, i);
        if (c == i && D[d] <= C[c] + K) r = mid;
        else l = mid+1;
    }
    L = l;
    l = i, r = N-1;
    while (l != r) {
        int mid = (l+r+1)/2;
        int d = rmq_d.query(i, mid);
        int c = rmq_c.query(i, mid);
        if (c == i && D[d] <= C[c] + K) l = mid;
        else r = mid-1;
    }
    R = r;
    l = 0, r = i;
    while (l != r) {
        int mid = (l+r)/2;
        int d = rmq_d.query(mid, i);
        int c = rmq_c.query(mid, i);
        if (c == i && D[d] < C[c] - K) r = mid;
        else l = mid+1;
    }
    LL = l;
    l = i, r = N-1;
    while (l != r) {
        int mid = (l+r+1)/2;
        int d = rmq_d.query(i, mid);
        int c = rmq_c.query(i, mid);
        if (c == i && D[d] < C[c] - K) l = mid;
        else r = mid-1;
    }
    RR = r;


    ll ret = 0;
    if (L == R) {
        if (D[L] <= C[L] + K) ret += 1;
    } else {
        ret += 1ll*(i-L+1)*(R-i+1);
    }

    if (LL == RR) {
        if (D[LL] < C[LL] - K) ret -= 1;
    } else {
        ret -= 1ll*(i-LL+1)*(RR-i+1);
    }

//    cout << i << ' ' << L << ' ' << R << ' ' << LL << ' ' << RR << ' ' << ret << endl;
    return ret;
}



int main() {
    int T;
    cin >> T;
    for (int t=1; t<=T; ++t) {
        int N, K;
        cin >> N >> K;
        vector<int> C;
        vector<int> D;
        for (int i=0; i<N; ++i) {
            int c;
            cin >> c;
            C.push_back(c);
        }
        for (int i=0; i<N; ++i) {
            int d;
            cin >> d;
            D.push_back(d);
        }
        RMQ rmq_c(C);
        RMQ rmq_d(D);
        ll ans = 0;
        for (int i=0; i<N; ++i) {
            ans += get_cnt(rmq_c, rmq_d, C, D, i, K);
        }
        cout << "Case #" << t << ": " << ans << endl;
    }
    return 0;
}
