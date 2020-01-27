#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(const string &A, const string &B) {
  if (A.size() != B.size()) return A.size() < B.size();
  int an = 0, bn = 0;
  for (int i=0; i<A.size(); ++i) {
    if (A[i] >= '0' && A[i] <= '9') an += A[i] - '0';
  }
  for (int i=0; i<B.size(); ++i) {
    if (B[i] >= '0' && B[i] <= '9') bn += B[i] - '0';
  }
  if (an != bn) return an < bn;
  return A < B;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int N;
  cin >> N;
  vector<string> arr(N);
  for (int i=0; i<N; ++i) cin >> arr[i];
  sort(arr.begin(), arr.end(), comp);
  for (int i=0; i<N; ++i) cout << arr[i] << '\n';
  return 0;
}