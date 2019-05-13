#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <iterator>

using namespace std;


int common(const string &a, const string &b) {
    int sz = min(a.size(), b.size());
    for (int i=0; i<sz; ++i) {
        if (a[i] != b[i]) return i;
    }
    return sz;
}


int main() {
    int T;
    cin >> T;
    for (int t=1; t<=T; ++t) {
        int N;
        cin >> N;
        set<string, greater<string>> rwords;
        unordered_set<string> used_suffix;
        for (int i=0; i<N; ++i) {
            string s;
            cin >> s;
            reverse(s.begin(), s.end());
            rwords.insert(s);
        }
        while (true) {
            int cnt = 0;
            set<string, greater<string>>::iterator target;
            for (auto it = rwords.begin(); it!=rwords.end(); ++it) {
                if (next(it) == rwords.end()) break;
                int new_cnt = common(*it, *(next(it)));
                while (new_cnt > cnt) {
                    if (used_suffix.find(it->substr(0, new_cnt)) == used_suffix.end()) {
                        target = it;
                        cnt = new_cnt;
                        break;
                    }
                    new_cnt--;
                }
            }
            if (cnt == 0) break;
            used_suffix.insert(target->substr(0, cnt));
            rwords.erase(target, next(target, 2));
        }
        cout << "Case #" << t << ": " << N-rwords.size() << endl;
    }
    return 0;
}
