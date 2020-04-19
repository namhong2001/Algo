#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int,int> pii;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T;
  cin >> T;
  for (int t=1; t<=T; ++t) {
    int N, L;
    cin >> N >> L;
    vector<int> cnt;
    
    int sum = 0;
    for (int i=0; i<L; ++i) {
      int c;
      cin >> c;
      sum += c;
      cnt.push_back(c);
    }
    int remains = N - sum;
    for (int i=0; i<remains; ++i) {
      cnt.push_back(0);
    }
    vector<int> arr = cnt;
    for (int &a : arr) {
      a *= 100;
      a %= N;
    }
    int add = 100 % N;
    int half = (N+1) / 2;
    vector<pii> srt;
    for (int i=0; i<arr.size(); ++i) {
      srt.push_back({arr[i], cnt[i]});
    }
    sort(srt.begin(), srt.end(), greater<pii>());
    
    for (int i=0; i<srt.size(); ++i) {
      if (srt[i].first >= half) continue;
      if (srt[i].first + add >= N) continue;
      while (remains && srt[i].first < half && srt[i].first + add < N) {
        srt[i].first += add;
        srt[i].second++;
        remains--;
      }
    }
    int ans = 0;
    for (pii s : srt) {
      int a = s.first;
      int c = s.second;
      ans += c * 100 / N;
      if (a >= half) ans++;
    }
    cout << "Case #" << t << ": " << ans << '\n';
  }
  return 0;
}