#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

const int INF = 987654321;

set<string> f = {"Mugunghwa", "ITX-Saemaeul", "ITX-Cheongchun"};
set<string> half = {"S-Train", "V-Train"};

int main() {
    int n, r;
    cin >> n >> r;
    map<string, int> id;
    for (int i=0; i<n; ++i) {
        string s;
        cin >> s;
        id[s] = i;
    }
    int m;
    cin >> m;
    vector<int> course(m);
    for (int i=0; i<m; ++i) {
        string s;
        cin >> s;
        course[i] = id[s];
    }
    int k;
    cin >> k;
    vector<vector<int>> adj1(n, vector<int>(n, INF));
    vector<vector<int>> adj2(n, vector<int>(n, INF));
    for (int i=0; i<n; ++i) adj1[i][i] = adj2[i][i] = 0;

    while (k--) {
        string type, s, e;
        int c;
        cin >> type >> s >> e >> c;
        int sid = id[s];
        int eid = id[e];
        adj1[sid][eid] = adj1[eid][sid] = min(adj1[sid][eid], c);
        if (f.find(type) != f.end()) {
            adj2[sid][eid] = adj2[eid][sid] = 0;
        } else if (half.find(type) != half.end()){
            adj2[sid][eid] = adj2[eid][sid] = min(adj2[sid][eid], c/2);
        } else {
            adj2[sid][eid] = adj2[eid][sid] = min(adj2[sid][eid], c);
        }
    }
    for (int k=0; k<n; ++k) {
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                adj1[i][j] = min(adj1[i][j], adj1[i][k] + adj1[k][j]);
                adj2[i][j] = min(adj2[i][j], adj2[i][k] + adj2[k][j]);
            }
        }
    }
    int normalcost = 0;
    int naeilcost = r;
    for (int i=0; i<m-1; ++i) {
        normalcost += adj1[course[i]][course[i+1]];
        naeilcost += adj2[course[i]][course[i+1]];
    }
    if (normalcost > naeilcost) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
