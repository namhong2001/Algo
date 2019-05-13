#include <iostream>
#include <sstream>
#include <vector>
#include <queue>


using namespace std;


vector<vector<int>> adj;
vector<vector<int>> capacity, flow;

int k, n;
int v;
int network_flow(int s, int t) {
    int total = 0;

    while (true) {
        vector<int> parent(v, -1);
        queue<int> q;
        parent[s] = s;
        q.push(s);
        while (!q.empty() && parent[t] == -1) {
            int here = q.front(); q.pop();
            for (int there : adj[here]) {
                if (capacity[here][there] - flow[here][there] > 0 &&
                    parent[there] == -1) {
                    parent[there] = here;
                    q.push(there);
                }
            }
        }
        if (parent[t] == -1) break;
        for (int p=t; p!=s; p=parent[p]) {
            flow[parent[p]][p]++;
            flow[p][parent[p]]--;
        }
        total++;
    }
    return total;
}

void print_path(int here) {
    if (here < 2 || here%2) {
        cout << (here > 1 ? here/2+2 : here+1) << ' ';
    }
    for (int there : adj[here]) {
        if (flow[here][there] > 0) {
            flow[here][there] = 0;
            print_path(there);
            return;
        }
    }
}

int main() {
    for (int t=1; ; t++) {
        cin >> k >> n;
        if (k == 0 && n == 0) break;
        v = n*2-2;
        adj = vector<vector<int>>(v);
        capacity.assign(v, vector<int>(v, 0));
        flow.assign(v, vector<int>(v, 0));
        string temp; getline(cin, temp);
        for (int a=0; a<n; ++a) {
            string s;
            getline(cin, s);
            stringstream ss(s);
            int ain = a > 1 ? 2*a-2 : a;
            int aout = a > 1 ? 2*a-1 : a;
            int b;
            while (ss >> b) {
                b--;
                int bin = b > 1 ? 2*b-2 : b;
                int bout = b > 1 ? 2*b-1 : b;
                capacity[aout][bin] = 1;
                adj[aout].push_back(bin);
            }
            if (a > 1) {
                capacity[ain][aout] = 1;
                adj[ain].push_back(aout);
            }
        }
        cout << "Case " << t << ":" << '\n';
        if (network_flow(0, 1) < k) {
            cout << "Impossible" << '\n';
        } else {
            while (k--) {
                print_path(0);
                cout << '\n';
            }
        }
        cout << '\n';
    }

    return 0;
}
