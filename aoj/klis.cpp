#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N_MAX = 500;

int N, K;
int nums[N_MAX];
int len_cache[N_MAX+1][N_MAX+1];
int cnt_cache[N_MAX+1][N_MAX+1];

int len(int a, int b) {
    if (b >= N) return 0;

    int &ret = len_cache[a+1][b+1];
    if (ret != -1) return ret;

    int prevN = a > -1 ? nums[a] : -1;
    int curN = b > -1 ? nums[b] : -1;

    if (prevN > curN) ret = len(a, b+1);
    else ret = max(len(a, b+1), len(b, b+1)+1);

    return ret;
}


int cnt(int a, int b) {
    if (b >= N) return 0;
    if (len(a, b) == 1 && len(b, b+1) == 0) return cnt(a, b+1) + 1;

    int &ret = cnt_cache[a+1][b+1];
    if (ret != -1) return ret;


    int prevN = a > -1 ? nums[a] : -1;
    int curN = b > -1 ? nums[b] : -1;

    if (prevN > curN) ret = cnt(a, b+1);
    else {
        if (len(a, b+1) > len(b, b+1)+1) {
            ret = cnt(a, b+1);
        } else if (len(a, b+1) < len(b, b+1)+1) {
            ret = cnt(b, b+1);
        } else {
            ret = cnt(a, b+1) + max(cnt(b, b+1), 1);
        }
    }

    return ret;
}

void kth(int a, int b, vector<int> &klis, int k) {
    vector<int> cand;
    int prevN = a > -1 ? nums[a] : -1;
    int lis = len(a, b);

    for (int i=b; i<N; ++i) {
        if (nums[i] > prevN && lis == len(i, i+1)+1) {
            cand.push_back(i);
        }
    }

    sort(cand.begin(), cand.end(), [](int p, int q) {
         return nums[p] < nums[q];
    });

    for (int i=0; i<cand.size(); ++i) {
        if (cnt(a, cand[i]) >= k) {
            klis.push_back(cand[i]);
            kth(cand[i], cand[i]+1, klis, k);
            break;
        } else {
            k -= cnt(cand[i], cand[i]+1);
        }
    }
}

int main() {
    int c;
    cin >> c;
    while (c--) {
        cin >> N >> K;
        for (int i=0; i<N; ++i) {
            cin >> nums[i];
        }
        memset(len_cache, -1, sizeof(len_cache));
        memset(cnt_cache, -1, sizeof(cnt_cache));
        vector<int> klis;

        kth(-1, 0, klis, K);

        cout << klis.size() << endl;
        for (auto i : klis) {
            cout << nums[i] << ' ';
        }
        cout << endl;
    }

    return 0;
}
