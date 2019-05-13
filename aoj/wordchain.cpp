#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <set>
#include <queue>

using namespace std;

vector<string> words;
vector<set<int>> startC;
vector<set<int>> endC;
vector<set<int>> equalSide;

void solve(int here, vector<int>& ans) {
    int s = words[here].front()-'a';
    int e = words[here].back()-'a';
    startC[s].erase(here);
    endC[e].erase(here);
    if (s == e) equalSide[s].erase(here);



    while (!equalSide[e].empty()) {
        solve(*equalSide[e].begin(), ans);
    }

    while (!startC[e].empty()) {
        solve(*startC[e].begin(), ans);
    }

    ans.push_back(here);
}

bool isPossible(int& s, int& e) {
    for (int i=0; i<26; ++i) {
        if (abs((int)startC[i].size()-(int)endC[i].size()) > 1) {
            return false;
        }
        if (startC[i].size() == endC[i].size()) continue;
        if (startC[i].size() == endC[i].size()+1) {
            if (e != -1) return false;

            e = i;
        }
        if (endC[i].size() == startC[i].size()+1) {
            if (s != -1) return  false;

            s = i;
        }
    }
    if ((s == -1 && e != -1) || (s != -1 && e == -1)) return false;

    return true;
}

int main() {
    int c;
    cin >> c;
    while (c--) {
        int n;
        cin >> n;
        words = vector<string>(n);
        startC = vector<set<int>>(26, set<int>());
        endC = vector<set<int>>(26, set<int>());
        equalSide = vector<set<int>>(26, set<int>());
        while (n--) {
            cin >> words[n];
            startC[words[n].front()-'a'].insert(n);
            endC[words[n].back()-'a'].insert(n);
            if (words[n].front() == words[n].back()) {
                equalSide[words[n].front()-'a'].insert(n);
            }
        }
        int s = -1;
        int e = -1;
        if (!isPossible(s, e)) {
            cout << "IMPOSSIBLE" << '\n';
        } else {
            int here = 0;
            if (s != -1 && e != -1) {
                if (!equalSide[e].empty()) {
                    here = *equalSide[e].begin();
                } else {
                    here = *startC[e].begin();
                }
            }
            vector<int> ans;
            solve(here, ans);


            for (int i=ans.size()-1; i>=0; --i) {
                cout << words[ans[i]] << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}
