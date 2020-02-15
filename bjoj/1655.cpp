#include <iostream>
#include <queue>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  priority_queue<int> left;
  priority_queue<int, vector<int>, greater<int>> right;
  int N;
  cin >> N;
  while (N--) {
    int a;
    cin >> a;
    left.push(a);
    if (!right.empty() && left.top() > right.top()) {
      right.push(left.top());
      left.pop();
    }
    if (left.size() > right.size()) {
      right.push(left.top());
      left.pop();
    }
    if (left.size() < right.size()) {
      left.push(right.top());
      right.pop();
    }
    cout << left.top() << '\n';
  }
  return 0;
}