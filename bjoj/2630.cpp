#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;

int cnt[3] = {};

int solve(vii &arr, int x, int y, int n) {
  if (n == 1) return arr[x][y];
  int a1 = solve(arr, x, y, n/2);
  int a2 = solve(arr, x, y+n/2, n/2);
  int a3 = solve(arr, x+n/2, y, n/2);
  int a4 = solve(arr, x+n/2, y+n/2, n/2);
  if (a1 == a2 && a2 == a3 && a3 == a4) {
    return a1;
  }
  cnt[a1]++;
  cnt[a2]++;
  cnt[a3]++;
  cnt[a4]++;
  return 2;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int N;
  cin >> N;
  vii arr(N, vi(N));
  for (int i=0; i<N; ++i) for (int j=0; j<N; ++j) cin >> arr[i][j];
  int s = solve(arr, 0, 0, N);
  cnt[s]++;
  cout << cnt[0] << '\n' << cnt[1];
  return 0;
}