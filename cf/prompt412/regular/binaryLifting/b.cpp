#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> par;
vector<int> depth;
vector<vector<int>> conn;

void dfs(int cur, int p, int d, vector<bool> &visited) {
  if (visited[cur]) return;
  visited[cur] = true;
  depth[cur] = d;
  par[cur] = p;
  for (int i=0; i<conn[cur].size(); ++i) {
    dfs(conn[cur][i], cur, d+1, visited);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> N;
  par.resize(N+1);
  depth.resize(N+1);
  conn.resize(N+1);
  
  for (int i=0; i<N-1; ++i) {
    int x, y;
    cin >> x >> y;
    conn[x].push_back(y);
    conn[y].push_back(x);
  }
  
  vector<bool> visited(N+1, false);
  dfs(1, 1, 0, visited);
  vector<vector<int>> st(N+1, vector<int>(17));
  for (int i=1; i<=N; ++i) st[i][0] = par[i];
  for (int j=1; j<17; ++j) for (int i=1; i<=N; ++i) {
    st[i][j] = st[st[i][j-1]][j-1];
  }
  int Q;
  cin >> Q;
  while (Q--) {
    int a, b;
    cin >> a >> b;
    int ans = 0;
    for (int i=16; i>=0; --i) {
      if (depth[a] - (1 << i) >= depth[b]) {
        a = st[a][i];
        ans += 1 << i;
      }
      if (depth[b] - (1 << i) >= depth[a]) {
        b = st[b][i];
        ans += 1 << i;
      }
    }
    if (a == b) {
      cout << ans << '\n';
      continue;
    }
    for (int i=16; i>=0; --i) {
      if (st[a][i] == st[b][i]) continue;
      a = st[a][i];
      b = st[b][i];
      ans += 1 << (i+1);
    }
    cout << ans + 2 << '\n';
  }
  return 0;
}