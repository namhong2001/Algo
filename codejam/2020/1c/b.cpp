#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef pair<int, char> pic;

char getZero(vector<string> inputs) {
  set<char> ss;
  for (auto s : inputs) {
    for (char c : s) {
      ss.insert(c);
    }
  }
  for (auto s : inputs) {
    ss.erase(s.front());
  }
  return *ss.begin();
}

string solve(vector<string> inputs) {
  char zero = getZero(inputs);
  map<char, int> mp;
  for (auto s : inputs) {
    mp[s.front()]++;
  }
  vector<pic> ans;
  for (auto item : mp) {
    if (item.first == zero) continue;
    ans.emplace_back(item.second, item.first);
  }
  sort(ans.begin(), ans.end(), greater<pic>());
  string ret = "";
  ret += zero;
  for (auto item : ans) {
    ret += item.second;
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T;
  cin >> T;
  
  
  for (int t=1; t<=T; ++t) {
    vector<string> inputs;
    int Q = 1e4;
    int u;
    cin >> u;
    while (Q--) {
      string dummy, s;
      cin >> dummy >> s;
      inputs.push_back(s);
    }
    cout << "Case #" << t << ": " << solve(inputs) << '\n';
  }
  return 0;
}