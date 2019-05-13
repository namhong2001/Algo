#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>


using namespace std;

vector<vector<int>> adj;
vector<int> discovered;
vector<int> scc_id;
int scc_counter;
int vertex_counter;
stack<int> st;


int l;
int nit(int a) {
    if (a%2) return a-1;
    return a+1;
}

int dfs(int here) {
    int ret = discovered[here] = vertex_counter++;
    st.push(here);
    for (int there : adj[here]) {
        if (discovered[there] == -1) {
            ret = min(ret, dfs(there));
        } else if (scc_id[there] == -1) {
            ret = min(ret, discovered[there]);
        }
    }
    if (ret == discovered[here]) {
        while (true) {
            int v = st.top();
            st.pop();
            scc_id[v] = scc_counter;
            if (v == here) break;
        }
        scc_counter++;
    }
    return ret;
}


string solve() {
    discovered = scc_id = vector<int>(l, -1);
    scc_counter = vertex_counter = 0;
    for (int i=0; i<l; ++i) {
        if (discovered[i] == -1) dfs(i);
    }
    for (int i=0; i<l; i+=2) {
        if (scc_id[i] == scc_id[i+1]) return "No";
    }
    return "Yes";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        l = (n+m)*2;
        adj.clear();
        adj.resize(l);
        while (k--) {
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            a--, b--, c--, d--;
            int y_dir = c-a < 0 ? 1 : 0;
            int x_dir = d-b < 0 ? 1 : 0;
            a*=2, b=(b+n)*2, c*=2, d=(d+n)*2;
            a += x_dir, b += y_dir, c += x_dir, d += y_dir;
            if (a == c && b == d) continue;
            if (a == c) {
                adj[nit(a)].push_back(a);
            } else if (b == d) {
                adj[nit(b)].push_back(b);
            } else {
                adj[nit(a)].push_back(b);
                adj[nit(b)].push_back(a);
                adj[nit(b)].push_back(d);
                adj[nit(d)].push_back(b);
                adj[nit(a)].push_back(c);
                adj[nit(c)].push_back(a);
                adj[nit(c)].push_back(d);
                adj[nit(d)].push_back(c);
            }
        }
        cout << solve() << endl;
    }

    return 0;
}
