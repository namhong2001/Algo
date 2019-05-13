#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int INF = 987654321;

vector<vector<int>> capacity(52, vector<int>(52, 0));
vector<vector<int>> flow(52, vector<int>(52, 0));


int get_id(string &s) {
    char c = s[0];
    if ('A' <= c && c <= 'Z') return c-'A';
    if ('a' <= c && c <= 'z') return c-'a'+26;
    return -1;
}

int network_flow(int s, int t) {
    int total = 0;
    while (true) {
        queue<int> q;
        vector<int> parent(52, -1);
        parent[s] = s;
        q.push(s);
        while (!q.empty() && parent[t] == -1) {
            int here = q.front(); q.pop();
            for (int there=0; there<52; ++there) {
                if (capacity[here][there]-flow[here][there] > 0 &&
                    parent[there] == -1) {
                    parent[there] = here;
                    q.push(there);
                }
            }
        }
        if (parent[t] == -1) break;
        int path_min = INF;
        for (int p=t; p!=s; p=parent[p]) {
            path_min = min(path_min, capacity[parent[p]][p]-flow[parent[p]][p]);
        }
        for (int p=t; p!=s; p=parent[p]) {
            flow[parent[p]][p] += path_min;
            flow[p][parent[p]] -= path_min;
        }
        total += path_min;
    }
    return total;
}

int main() {
    int n;
    cin >> n;
    for (int i=0; i<n; ++i) {
        string a, b;
        int c;
        cin >> a >> b >> c;
        int aid = get_id(a);
        int bid = get_id(b);
        capacity[aid][bid] += c;
        capacity[bid][aid] += c;
    }
    cout << network_flow(0, 25);
    return 0;
}

