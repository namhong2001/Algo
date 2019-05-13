#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> adj(26);
vector<int> indegree(26, 0);
vector<bool> characters(26, false);


string solve() {
    string ans;
    queue<int> q;
    for (int i=0; i<26; ++i) {
        if (characters[i] && indegree[i] == 0) {
            q.push(i);
        }
    }
    bool has_multiple = false;

    while (!q.empty()) {
        if (q.size() > 1) {
            has_multiple = true;
        }
        int here = q.front();
        q.pop();
        ans += 'a' + here;
        for (int there : adj[here]) {
            if (--indegree[there] == 0) {
                q.push(there);
            }
        }
    }
    for (int i=0; i<26; ++i) {
        if (indegree[i] > 0) {
            return "!";
        }
    }
    if (has_multiple) return "?";
    return ans;
}

int main() {
    int n;
    cin >> n;
    string curr, prev;
    while (n--) {
        cin >> curr;
        if (!prev.empty()) {
            for (int i=0; i<prev.size(); ++i) {
                if (i == curr.size()) {
                    cout << "!" << endl;
                    return 0;
                }
                if (prev[i] != curr[i]) {
                    adj[prev[i]-'a'].push_back(curr[i]-'a');
                    indegree[curr[i]-'a']++;
                    break;
                }
            }
        }
        for (int i=0; i<curr.size(); ++i) {
            characters[curr[i]-'a'] = true;
        }
        prev = curr;
    }
    cout << solve() << endl;

    return 0;
}
