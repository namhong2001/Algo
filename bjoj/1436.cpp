#include <iostream>

using namespace std;

bool has3Six(int num) {
  int cnt = 0;
  while (num) {
    if (num % 10 == 6) cnt++;
    else cnt = 0;
    num /= 10;
    if (cnt >= 3) return true;
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int i=0;
  int N;
  cin >> N;
  for (int i=0; ; ++i) {
    if (has3Six(i)) {
      N--;
      if (N == 0) {
        cout << i;
        return 0;
      }
    }
  }
  return 0;
}