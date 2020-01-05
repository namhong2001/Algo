#include <iostream>
#include <vector>

using namespace std;

const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

int N;

int candy(vector<string> &arr) {
  int ans = 1;
  for (int i=0; i<N; ++i) {
    int cnt = 1;
    for (int j=1; j<N; ++j) {
      if (arr[i][j] == arr[i][j-1]) cnt++;
      else cnt = 1;
      ans = max(ans, cnt);
    }
  }

  for (int i=0; i<N; ++i) {
    int cnt = 1;
    for (int j=1; j<N; ++j) {
      if (arr[j][i] == arr[j-1][i]) cnt++;
      else cnt = 1;
      ans = max(ans, cnt);
    }
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> N;
  vector<string> arr(N);
  int ans = 1;
  for (int i=0; i<N; ++i) cin >> arr[i];
  for (int i=0; i<N; ++i) for (int j=0; j<N; ++j) for (int k=0; k<4; ++k) {
    int nx = i + dx[k];
    int ny = j + dy[k];
    if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
    swap(arr[i][j], arr[nx][ny]);
    ans = max(ans, candy(arr));
    swap(arr[i][j], arr[nx][ny]);
  }
  cout << ans;
  return 0;
}