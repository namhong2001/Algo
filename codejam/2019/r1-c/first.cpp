#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

char get_winner(bool hasR, bool hasS, bool hasP) {
    if (hasR && hasS) return 'R';
    if (hasR && hasP) return 'P';
    if (hasS && hasP) return 'S';
    if (hasR) return 'P';
    if (hasS) return 'R';
    if (hasP) return 'S';
}

char get_loser(char winner) {
    if (winner == 'R') return 'S';
    if (winner == 'S') return 'P';
    if (winner == 'P') return 'R';
}

int main() {
    int T;
    cin >> T;
    for (int t=1; t<=T; ++t) {
        int A;
        cin >> A;
        vector<string> all_programs;
        unordered_set<string> programs;
        for (int i=0; i<A; ++i) {
            string program;
            cin >> program;
            programs.insert(program);
            all_programs.push_back(program);
        }
        string ans;
        while (!programs.empty()) {
            bool hasR=false, hasS=false, hasP=false;
            for (string s : programs) {
                int idx = ans.size()%s.size();
                if (s[idx] == 'R') hasR = true;
                else if (s[idx] == 'S') hasS = true;
                else if (s[idx] == 'P') hasP = true;
            }
            if (hasR && hasS && hasP) {
                ans = "IMPOSSIBLE";
                break;
            }
            char winner = get_winner(hasR, hasS, hasP);
            char loser = get_loser(winner);
            for (string s : all_programs) {
                int idx = ans.size()%s.size();
                if (s[idx] == loser) programs.erase(s);
            }
            ans += winner;
        }
        cout << "Case #" << t << ": " << ans << endl;
    }
    return 0;
}
