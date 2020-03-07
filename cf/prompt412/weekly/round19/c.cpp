#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

typedef pair<int,int> pii;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int N, Q;
  cin >> N >> Q;
  vector<vector<int>> unreadByApp(N+1);
  queue<pii> noti;
  set<pii> unread;
  int notiIdx = 0;
  for (int i=0; i<Q; ++i) {
    int a, b;
    cin >> a >> b;
    if (a == 1) {
      unreadByApp[b].push_back(notiIdx);
      noti.emplace(b, notiIdx);
      unread.emplace(b, notiIdx);
      notiIdx++;
    } else if (a == 2) {
      while (!unreadByApp[b].empty()) {
        int idx = unreadByApp[b].back();
        unreadByApp[b].pop_back();
        unread.erase({b, idx});
      }
    } else if (a == 3) {
      while (!noti.empty() && noti.front().second < b)
      
    }
  }
  int ans = 0;
  for (int i=0; i<noti.size(); ++i) {
    int app = noti[i];
    if (i > globalLastRead && i > lastRead[app]) ans++;
  }
  cout << ans;
  return 0;
}