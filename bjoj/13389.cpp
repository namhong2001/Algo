#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct Query {
    int m, l, r;
};

bool operator < (const Query &A, const Query &B) {
    return A.m < B.m;
}




int vacant_cnt(vector<Query> &queries, int cur_index) {
    vector<Query> sub(queries.begin(), queries.begin()+cur_index);
    auto comp = [](const Query &A, const Query &B) {
        return A.l < B.l;
    };
    sort(sub.begin(), sub.end(), comp);
    Query &cur = queries[cur_index];
    if (sub.empty()) return cur.r-cur.l+1;
    int left = cur.l;
    int right = cur.r;
    int ret = 0;
    for (Query &a : sub) {
        if (left > right) break;
        if (a.l > left) {
            int to = min(a.l-1, right);
            ret += to - left + 1;
            left = a.r+1;
        } else {
            left = max(left, a.r+1);
        }
    }
    if (left <= right) ret += right-left+1;
    return ret;
}

int get_next_start(int cur_start, int cnt, set<int> &used) {

}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Query> queries;
    set<int> used;

    for (int i=0; i<m; ++i) {
        int l, r, a;
        cin >> l >> r >> a;
        queries.push_back({a, l, r});
    }
    sort(queries.begin(), queries.end());
    vector<Query> cq;
    int result = 1;
    for (int i=0; i<queries.size(); ++i) {
        Query &q = queries[i];
        if(cq.empty()) {
            cq.push_back(q);
            continue;
        }

        Query &b = cq.back();

        if (b.m == q.m) {
            if ((b.l < q.l && b.r < q.l) || (b.l > q.r && b.r > q.r)) {
                result = 0;
                break;
            }
            b.l = min(b.l, q.l);
            b.r = max(b.r, q.r);
        } else {
            cq.push_back(q);
        }
    }
    if (result == 0) { cout << result << endl; return 0; }

    int last_num = 0;
    for (int i=0; i<cq.size(); ++i) {
        int cnt = vacant_cnt(cq, i);
//        cout << i << ' ' << cq[i].l << ' ' << cq[i].r << ' ' << cnt << endl;
        if (cnt == 0) { result = 0; break; }
        cnt--;
        for (int u : used) {
            if (u <= last_num) continue;
            if (u <= last_num + cnt) cnt++;
        }
        last_num += cnt;
        if (last_num >= cq[i].m) { result = 0; break; }
        used.insert(cq[i].m);
    }
    cout << result << endl;
}
