#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  vector<int> arr;
  arr.push_back(-1);
  int i = 1;
  while (arr.size() < 1010) {
    int n = i;
    while (n) {
      arr.push_back(i);
      n--;
    }
    i++;
  }
  int a, b;
  cin >> a >> b;
  int ans = 0;
  for (int i=a; i<=b; ++i) {
    ans += arr[i];
  }
  cout << ans;
  return 0;
}