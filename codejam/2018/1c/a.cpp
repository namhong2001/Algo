#include <iostream>
#include <set>
#include <vector>

using namespace std;

typedef set<char> sc;

int N, L;
string ans;

bool solve(string s, vector<sc> &letters, set<string> &inputs) {
  if (s.size() == L) {
    if (inputs.find(s) == inputs.end()) {
      ans = s;
      return true;
    }
    return false;
  }
  int idx = s.size();
  for (auto &c : letters[idx]) {
    if (solve(s + c, letters, inputs)) return true;
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T;
  cin >> T;
  for (int t=1; t<=T; ++t) {
    cin >> N >> L;
    vector<sc> letters(L);
    set<string> inputs;
    for (int i=0; i<N; ++i) {
      string s;
      cin >> s;
      inputs.insert(s);
    }
    for (auto &s : inputs) {
      for (int i=0; i<L; ++i) {
        letters[i].insert(s[i]);
      }
    }
    if (solve("", letters, inputs)) {
      cout << "Case #" << t << ": " << ans << '\n';
    } else {
      cout << "Case #" << t << ": " << "-" << '\n';
    }
  }
  return 0;
}

