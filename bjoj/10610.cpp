#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  string N;
  cin >> N;
  vector<int> cnt(10);
  int digitSum = 0;
  for (char c : N) {
    int digit = c - '0';
    digitSum += digit;
    cnt[digit]++;
  }
  if (digitSum % 3 == 0 && cnt[0] > 0) {
    for (int i=9; i>=0; --i) {
      while (cnt[i]) {
        cout << i;
        cnt[i]--;
      }
    }
  } else cout << -1;
  return 0;
}