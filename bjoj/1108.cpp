#include <iostream>
#include <vector>
#include <map>
#include <stack>

using namespace std;

typedef long long ll;

vector<vector<ll>> adj;
vector<ll> discovered;
vector<ll> scc_id;
vector<vector<ll>> scc_vertices;
stack<ll> st;
ll scc_counter = 0;
ll vertex_counter = 0;


map<string, ll> site_id;
ll site_id_counter = 0;
ll get_site_id(string &name) {
    if (site_id.find(name) == site_id.end()) {
        site_id[name] = site_id_counter++;
    }
    return site_id[name];
}

ll dfs(ll here) {
    ll ret = discovered[here] = vertex_counter++;
    st.push(here);
    for (ll there : adj[here]) {
        if (discovered[there] == -1) {
            ret = min(ret, dfs(there));
        } else if (scc_id[there] == -1) {
            ret = min(ret, discovered[there]);
        }
    }
    if (ret == discovered[here]) {
        vector<ll> vertices;
        while (true) {
            ll v = st.top();
            st.pop();
            vertices.push_back(v);
            scc_id[v] = scc_counter;
            if (v == here) break;
        }
        ++scc_counter;
        scc_vertices.push_back(vertices);
    }
    return ret;
}

ll solve(ll target_id) {
    discovered = scc_id = vector<ll>(site_id.size(), -1);
    for (ll i=0; i<site_id.size(); ++i) {
        if (discovered[i] == -1) {
            dfs(i);
        }
    }
    vector<ll> score(site_id.size(), 1);
    for (ll i=scc_vertices.size()-1; i>=0; --i) {
        for (ll here : scc_vertices[i]) {
            for (ll there : adj[here]) {
                if (scc_id[here] != scc_id[there]) {
                    score[there] += score[here];
                }
            }
        }
    }
    return score[target_id];
}

int main() {
    ll n;
    cin >> n;
    for (ll i=0; i<n; ++i) {
        string here;
        ll parent_cnt;
        cin >> here >> parent_cnt;
        ll here_id = get_site_id(here);
        for (ll j=0; j<parent_cnt; ++j) {
            string parent;
            cin >> parent;
            ll parent_id = get_site_id(parent);
            adj.resize(site_id.size());
            adj[parent_id].push_back(here_id);
        }
    }
    string target;
    cin >> target;
    ll target_id = get_site_id(target);
    adj.resize(site_id.size());
    cout << solve(target_id) << '\n';
    return 0;
}
