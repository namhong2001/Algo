#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int,int> pii;

struct Schedule {
  int s, e, idx;
  bool operator < (const Schedule &rhs) {
    return s == rhs.s ? e < rhs.e : s < rhs.s;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T;
  cin >> T;
  for (int t=1; t<=T; ++t) {
    int N;
    cin >> N;
    vector<Schedule> schedules;
    for (int i=0; i<N; ++i) {
      int s, e;
      cin >> s >> e;
      schedules.push_back({s, e, i});
    }
    sort(schedules.begin(), schedules.end());
    int C = 0, J = 0;
    string ans(N, '*');
    for (auto &schedule : schedules) {
      int s = schedule.s;
      int e = schedule.e;
      int idx = schedule.idx;
      if (C <= s) {
        ans[idx] = 'C';
        C = e;
      } else if (J <= s) {
        ans[idx] = 'J';
        J = e;
      } else {
        ans = "IMPOSSIBLE";
        break;
      }
    }
    cout << "Case #" << t << ": " << ans << '\n';
  }
  return 0;
}