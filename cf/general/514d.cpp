#include <iostream>
#include <vector>
#include <deque>

using namespace std;

typedef pair<int,int> pii;

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<vector<int>> arr(N, vector<int>(M));
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            cin >> arr[i][j];
        }
    }
    vector<deque<pii>> maxstack(M);
    auto getsum = [&]() {
        int ret = 0;
        for (int i=0; i<M; ++i) {
            if (!maxstack[i].empty()) ret += maxstack[i].front().first;
        }
        return ret;
    };
    auto popfrontuntil = [&](int index) {
        for (int i=0; i<M; ++i) {
            while (!maxstack[i].empty() && maxstack[i].front().second <= index) {
                maxstack[i].pop_front();
            }
        }
    };
    auto pushback = [&](int index) {
        for (int i=0; i<M; ++i) {
            while (!maxstack[i].empty() && maxstack[i].back().first <= arr[index][i]) {
                maxstack[i].pop_back();
            }
            maxstack[i].emplace_back(arr[index][i], index);
        }
    };
    int maxlen = 0;
    vector<int> ans(M);

    auto updateans = [&]() {
        for (int i=0; i<M; ++i) {
            ans[i] = maxstack[i].empty() ? 0 : maxstack[i].front().first;
        }
    };

    int s = 0, e = 0; // [s, e)
    for (e=1; e<=N; ++e) {
        pushback(e-1);
        while (getsum() > K) {
            s++;
            popfrontuntil(s-1);
        }
        if (e-s > maxlen) {
            maxlen = e-s;
            updateans();
        }
    }
    for (int i=0; i<M; ++i) cout << ans[i] << ' ';
    return 0;
}