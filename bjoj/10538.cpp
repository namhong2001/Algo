#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int> getPartialMatch(const string& N) {
    int m = N.size();
    vector<int> pi(m, 0);
    int matched = 0;
    for (int i=1; i<m; ++i) {
        while(matched > 0 && N[i] != N[matched]) {
            matched = pi[matched-1];
        }
        if(N[i] == N[matched]) {
            ++matched;
            pi[i] = matched;
        }
    }
    return pi;
}

set<pair<int,int>> kmpSearch(const string H[], int hm, int wm, const string& N, int *flag) {
    int n = N.size();
    vector<int> pi = getPartialMatch(N);
    set<pair<int,int>> ret;

    for (int k=0; k<hm; ++k) {
        string h = H[k];
        int matched = 0;
        for (int i=0; i<wm; ++i) {
            while(matched > 0 && h[i] != N[matched]) {
                matched = pi[matched-1];
            }
            if(h[i] == N[matched]) {
                ++matched;
                if (matched == n) {

                    ret.insert(make_pair(k, i - matched + 1));
                    matched = pi[matched-1];
                }
            }
        }
    }
    return ret;
}

int main() {
    int hp, wp, hm, wm;
    cin >> hp >> wp >> hm >> wm;
    string p[hp];
    for (int i=0; i<hp; ++i) {
        cin >> p[i];
    }
    string m[hm];
    for(int i=0; i<hm; ++i) {
        cin >> m[i];
    }

    int flag[hm][wm] = { {0} };
    int cnt = 0;

    for(int i=0; i<hm; ++i) {
        for(int j=0; j<wm; ++j) {
            flag[i][j] = 0;
        }
    }

    // set flag
    for (int ni=1; ni <= hp; ++ni) {
        string N = p[ni-1];
        vector<int> pi = getPartialMatch(N);

        for (int hi=0; hi<hm; ++hi) {
            string h = m[hi];
            int matched = 0;
            for (int i=0; i<wm; ++i) {
                while(matched > 0 && h[i] != N[matched]) {
                    matched = pi[matched-1];
                }
                if(h[i] == N[matched]) {
                    ++matched;
                    if (matched == wp) {
//                        ret.insert(make_pair(k, i - matched + 1));
                        cout << hi << ' ' << i-matched+1 << ' ' << ni << ' ';
                        flag[hi][i-matched+1] = ni;
                        cout << flag[hi][i-matched+1] << endl;
                        matched = pi[matched-1];
                    }
                }
            }
        }
    }

    for(int i=0; i<hm; ++i) {
        for(int j=0; j<wm; ++j) {
            cout << flag[i][j];
        }
        cout << endl;
    }


    for (int i=0; i<hm; ++i) {
        for (int j=0; j<wm; ++j) {
            if (flag[i][j] == 1) {
                int k;
                for (k=1; k<hp; ++k) {
                    if (flag[i+k][j] != k+1) {
                        break;
                    }
                }
                if (k == hp) ++cnt;
            }
        }
    }



//    set<pair<int, int>> kmpResult[hp];
//    for (int i=0; i<hp; ++i) {
//        kmpResult[i] = kmpSearch(m, hm, wm, p[i], flag);
//    }
//
//
//    int cnt = 0;
//    for (auto it = kmpResult[0].begin(); it != kmpResult[0].end(); ++it) {
//        int first = it->first;
//        int second = it->second;
//        int i;
//        for (i=1; i<hp; ++i) {
//            auto target = kmpResult[i];
//            if (target.find(make_pair(first+i, second)) == target.end()) {
//                break;
//            }
//        }
//        if (i == hp) {
//            cnt++;
//        }
//    }

    cout << cnt;
    return 0;
}
