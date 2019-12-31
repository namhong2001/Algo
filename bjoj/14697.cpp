#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int A, B, C, N;
  cin >> A >> B >> C >> N;
  for (int i=0; i*A<=N; ++i)
    for (int j=0; i*A + j*B<=N; ++j)
      for (int k=0; i*A + j*B + k*C <= N; ++k)
        if (i*A + j*B + k*C == N) {
          cout << 1;
          return 0;
        }

  cout << 0;  
  return 0;
}