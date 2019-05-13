#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <sstream>
#include <set>
#include <algorithm>

using namespace std;

int word_counter;
map<string, int> word_to_id;
vector<string> id_to_word(3100);
vector<set<int>> adj(3100);
vector<set<int>> r_adj(3100);
vector<int> discovered(3100, -1);
vector<int> scc_id(3100, -1);
vector<int> scc_cnt(3100, 0);
stack<int> st;
int scc_counter;
int vertex_counter;

vector<string> split(string &str) {
    vector<string> ret;
    stringstream ss(str);
    string temp;
    while (ss >> temp) {
        ret.push_back(temp);
    }
    return ret;
}

vector<int> topol;
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
        while(true) {
            int v = st.top();
            st.pop();
            scc_id[v] = scc_counter;
            scc_cnt[scc_counter]++;
            if (v == here) break;
        }
        ++scc_counter;
    }
    topol.push_back(here);
    return ret;
}



vector<int> ans;
vector<bool> visited(3100, false);
void s_dfs(int here) {
    visited[here] = true;
    for (int there : r_adj[here]) {
        if (!visited[there]) {
            s_dfs(there);
        }
    }
    ans.push_back(here);
}

vector<int> solve() {
    topol.clear();
    discovered.assign(3100, -1);
    scc_id.assign(3100, -1);
    scc_cnt.assign(3100, 0);
    st = stack<int>();
    vertex_counter = 0;
    scc_counter = 0;
    for (int i=0; i<word_counter; ++i) {
        if (discovered[i] == -1) {
            dfs(i);
        }
    }

    ans.clear();
    visited.assign(3100, false);
    for (int here : topol) {
        if (!visited[here] && scc_cnt[scc_id[here]] > 1) {
            s_dfs(here);
        }
    }
    return ans;
}

int main() {
    string n_str;
    while (getline(cin, n_str)) {
        int n = stoi(n_str);
        if (n == 0) continue;

        word_counter = 0;
        word_to_id.clear();
        id_to_word.assign(3100, "");
        adj.assign(3100, set<int>());
        r_adj.assign(3100, set<int>());
        while (n--) {
            string temp;
            getline(cin, temp);
            vector<string> in_str = split(temp);
            vector<int> in_ids;
            for (string &s : in_str) {
                if (word_to_id.find(s) == word_to_id.end()) {
                    word_to_id[s] = word_counter;
                    id_to_word[word_counter] = s;
                    word_counter++;
                }
                in_ids.push_back(word_to_id[s]);
            }

            for (int i=1; i<in_ids.size(); ++i) {
                adj[in_ids[i]].insert(in_ids[0]);
                r_adj[in_ids[0]].insert(in_ids[i]);
            }
        }
        vector<int> ans_ids = solve();
        vector<string> ans_str;
        for (int id : ans_ids) {
            ans_str.push_back(id_to_word[id]);
        }
        sort(ans_str.begin(), ans_str.end());
        cout << ans_str.size() << endl;
        for (string w : ans_str) {
            cout << w << ' ';
        }
        cout << '\n';
    }

    return 0;
}
