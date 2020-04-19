#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;

int rowCnt(vii &matrix) {
  int N = matrix.size();
  int ret = 0;
  for (int i=0; i<N; ++i) {
    vector<bool> checked(N+1, false);
    for (int j=0; j<N; ++j) {
      if (checked[matrix[i][j]]) {
        ret++;
        break;
      }
      checked[matrix[i][j]] = true;
    }
  }
  return ret;
}

int colCnt(vii &matrix) {
  int N = matrix.size();
  int ret = 0;
  for (int j=0; j<N; ++j) {
    vector<bool> checked(N+1, false);
    for (int i=0; i<N; ++i) {
      if (checked[matrix[i][j]]) {
        ret++;
        break;
      }
      checked[matrix[i][j]] = true;
    }
  }
  return ret;
}

int trace(vii &matrix) {
  int N = matrix.size();
  int ret = 0;
  for (int i=0; i<N; ++i) ret += matrix[i][i];
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T;
  cin >> T;
  for (int t=1; t<=T; ++t) {
    int N;
    cin >> N;
    vii matrix(N, vi(N));
    for (int i=0; i<N; ++i) for (int j=0; j<N; ++j) cin >> matrix[i][j];
    cout << "Case #" << t << ": " << trace(matrix) << ' ' << rowCnt(matrix) << ' ' << colCnt(matrix) << '\n';
  }
  return 0;
}