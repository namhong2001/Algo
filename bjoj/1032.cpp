#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int N;
  cin >> N;
  vector<string> arr(N);
  for (int i=0; i<N; ++i) cin >> arr[i];
  int sz = arr[0].size();
  string ans = "";
  for (int i=0; i<sz; ++i) {
    set<char> ss;
    for (int j=0; j<N; ++j) {
      ss.insert(arr[j][i]);
    }
    if (ss.size() == 1) ans += *ss.begin();
    else ans += '?';
  }
  cout << ans;
  return 0;
}