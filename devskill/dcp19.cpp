#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct OneRange {
    int s, e, len;
};

int main() {
    int T;
    cin >> T;
    for (int t=1; t<=T; ++t) {
        int N, Q;
        cin >> N >> Q;
        vector<int> arr(N);
        for (int i=0; i<N; ++i) cin >> arr[i];
        vector<vector<int>> st(N, vector<int>(26));
        for (int i=0; i<N; ++i) st[i][0] = arr[i];
        for (int j=1; j<26; ++j) {
            for (int i=0; i+(1<<j)<=N; ++i) {
                st[i][j] = min(st[i][j-1], st[i+(1<<(j-1))][j-1]);
            }
        }
        auto minQuery = [&](int s, int e) {
            int r = e-s+1;
            int ret = arr[s];
            for (int j=0; j<26; ++j) {
                if (r & (1<<j)) {
                    ret = min(ret, st[s][j]);
                    s += 1<<j;
                }
            }
            return ret;
        };
        vector<OneRange> onearr;
        bool onRange = false;
        for (int i=0; i<N; ++i) {
            if (arr[i] == 1) {
                if (!onRange) {
                    onRange = true;
                    onearr.push_back({i, i, 1});
                } else {
                    onearr.back().e = i;
                    onearr.back().len++;
                }
            } else {
                onRange = false;
            }
        }
        int onearrsize = onearr.size();
        vector<vector<OneRange>> onest(onearrsize, vector<OneRange>(26));
        for (int i=0; i<onearrsize; ++i) onest[i][0] = onearr[i];
        for (int j=1; j<26; ++j) {
            for (int i=0; i+(1<<j)<=onearrsize; ++i) {
                if (onest[i][j-1].len < onest[i+(1<<(j-1))][j-1].len) {
                    onest[i][j] = onest[i+(1<<(j-1))][j-1];
                } else {
                    onest[i][j] = onest[i][j-1];
                }
            }
        }
        auto oneLenMaxQuery = [&](int s, int e) {
            int r = e-s+1;
            OneRange ret = onearr[s];
            for (int j=0; j<26; ++j) {
                if (r & (1<<j)) {
                    if (ret.len < onest[s][j].len) {
                        ret = onest[s][j];
                    }
                    s += 1<<j;
                }
            }
            return ret;
        };
        vector<int> oneEnd(N);
        vector<int> oneStart(N);
        int ostart = -1, oend = -1;
        for (int i=0; i<N; ++i) {
            if (arr[i] == 1) {
                if (ostart == -1) ostart = i;
                oneStart[i] = ostart;
            } else {
                ostart = -1;
            }
        }
        for (int i=N-1; i>=0; --i) {
            if (arr[i] == 1) {
                if (oend == -1) oend = i;
                oneEnd[i] = oend;
            } else {
                oend = -1;
            }
        }
        auto solveOne = [&](int s, int e) {
            auto sIter = lower_bound(onearr.begin(), onearr.end(), OneRange {s, e, e-s+1}, [&](OneRange A, OneRange B){return A.s < B.s;});
            auto eIter = prev(upper_bound(onearr.begin(), onearr.end(), OneRange {s, e, e-s+1}, [&](OneRange A, OneRange B){return A.e < B.e;}));
            int sidx = sIter - onearr.begin();
            int eidx = eIter - onearr.begin();
            OneRange ret = {-1, -1, -1};
            if (eidx >= sidx) ret = oneLenMaxQuery(sidx, eidx);
            // cerr << "here" << endl;
            // cerr << ret.s << ' ' << ret.e << ' ' << ret.len << endl;
            if (arr[s] == 1) {
                int len = min(oneEnd[s], e) - s + 1;
                if (len >= ret.len) ret = {s, min(oneEnd[s], e), len};
            }
            if (arr[e] == 1) {
                int len = e - max(oneStart[e], s) + 1;
                if (len > ret.len) ret = {max(oneStart[e], s), e, len};
            }
            return ret;
        };
        cout << "Case " << t << ":" << '\n';
        while (Q--) {
            int s, e;
            cin >> s >> e;
            s--, e--;
            int mn = minQuery(s, e);
            if (mn == 0) {
                cout << 0 << ' ' << s+1 << ' ' << e+1 << '\n';
            } else if (mn > 1) {
                if (arr[s] == mn) {
                    cout << mn << ' ' << s+1 << ' ' << s+1 << '\n';
                } else {
                    int l = s, r = e; // l: false, r: true,
                    while (l+1 < r) {
                        int mid = (l+r)/2;
                        if (minQuery(s, mid) == mn) r = mid;
                        else l = mid;
                    }
                    cout << mn << ' ' << r+1 << ' ' << r+1 << '\n';
                }
            } else if (mn == 1) {
                OneRange sol = solveOne(s, e);
                cout << 1 << ' ' << sol.s+1 << ' ' << sol.e+1 << '\n';
            }
        }
    }
}