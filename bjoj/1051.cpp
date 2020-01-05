#include <iostream>
#include <vector>

using namespace std;

int N, M;

bool hasSquare(vector<string> &arr, int len) {
  for (int i=0; i<N; ++i) {
    for (int j=0; j<M; ++j) {
      int nx = i + len - 1;
      int ny = j + len - 1;
      if (nx >= N || ny >= M) continue;
      if (arr[i][j] == arr[nx][j] && arr[i][j] == arr[i][ny] && arr[i][j] == arr[nx][ny]) {
        return true;
      }
    }
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> N >> M;
  vector<string> arr(N);
  for (int i=0; i<N; ++i) cin >> arr[i];
  for (int i=min(N, M); i>0; --i) {
    if (hasSquare(arr, i)) {
      cout << i*i << '\n';
      return 0;
    }
  }
  return 0;
}