#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <ctime>

using namespace std;

struct Node {
    int minValue;
    int maxValue;
    int index;
    bool operator<(const Node& rhs) const {
        return (maxValue - minValue) > (rhs.maxValue - rhs.minValue);
    }
};

const int SIZE = 2001;

multimap<int, int> links[SIZE];
vector<Node> arr[SIZE];

int solve(int n) {
    priority_queue<Node> q;
    multimap<int, int>::iterator it;
    Node node;
    int ans, idx, minV, maxV, minV2, maxV2, i, k, c;
    bool flag;

    ans = 1000001;

    for (it = links[0].begin(); it != links[0].end(); it++) {
        node.index = it->first;
        node.minValue = it->second;
        node.maxValue = it->second;

        if (node.index == n - 1) {
            ans = min(ans, node.maxValue - node.minValue);
            continue;
        }

        q.push(node);
        arr[node.index].push_back(node);
    }
    int pq_cnt = 0;
    int view_cnt = 0;
    while (!q.empty()) {
        node = q.top();
        q.pop();
        pq_cnt++;
        if (node.maxValue - node.minValue >= ans) continue;
        view_cnt++;
        idx = node.index;
        minV = node.minValue;
        maxV = node.maxValue;

        for (it = links[idx].begin(); it != links[idx].end(); it++) {
            view_cnt++;
            k = it->first;
            c = it->second;
            flag = true;
            minV2 = min(minV, c);
            maxV2 = max(maxV, c);
            if (k == n - 1) {
                ans = min(ans, maxV2 - minV2);
                continue;
            }
            for (i = 0; i < arr[k].size(); i++) {
                view_cnt++;
                if (arr[k][i].minValue >= minV2 && maxV2 >= arr[k][i].maxValue) {
                    flag = false;
                    break;
                }
            }
            if (flag == true) {
                node.index = k;
                node.minValue = minV2;
                node.maxValue = maxV2;
                q.push(node);
                arr[k].push_back(node);
            }
        }
    }
    cout << pq_cnt << ' ' << view_cnt << endl;

    return ans;
}

int main(int argc, const char * argv[]) {
    clock_t BE, EN;
    BE = clock();
    int t, n, m, i, a, b, c;

    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &m);

        for (i = 0; i < n; i++) {
            links[i].clear();
            arr[i].clear();
        }

        for (i = 0; i < m; i++) {
            scanf("%d %d %d", &a, &b, &c);
            if (b != 0 && a != n - 1) links[a].insert(make_pair(b, c));
            if (a != 0 && b != n - 1) links[b].insert(make_pair(a, c));
        }

        printf("%d\n", solve(n));
    }
    EN = clock();
    cout << "time : " << 1000.0 * (EN-BE)/CLOCKS_PER_SEC << "ms" << endl;

    return 0;
}
