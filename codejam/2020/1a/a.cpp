#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct token {
  string left, mid, right;
};

token tokenize(string &str) {
  int leftIdx = 0;
  string left = "";
  while (leftIdx < str.size()) {
    if (str[leftIdx] == '*') break;
    left += str[leftIdx];
    leftIdx++;
  }
  int rightIdx = str.size()-1;
  string right = "";
  while (rightIdx >= 0) {
    if (str[rightIdx] == '*') break;
    right = str[rightIdx] + right;
    rightIdx--;
  }
  string mid = "";
  for (int midIdx = leftIdx; midIdx <= rightIdx; ++midIdx) {
    if (str[midIdx] == '*') continue;
    mid += str[midIdx];
  }
  return {
    left, mid, right
  };
}

string logestString(vector<string> &strs) {
  if (strs.size() == 0) return "";
  string ret = strs[0];
  for (auto &str : strs) {
    if (str.size() > ret.size()) ret = str;
  }
  return ret;
}

bool startWith(string &A, string &B) {
  if (A.size() < B.size()) return startWith(B, A);
  for (int i=0; i<B.size(); ++i) {
    if (A[i] != B[i]) return false;
  }
  return true;
}

bool endWith(string &A, string &B) {
  if (A.size() < B.size()) return endWith(B, A);
  string aa = A;
  string bb = B;
  reverse(aa.begin(), aa.end());
  reverse(bb.begin(), bb.end());
  return startWith(aa, bb);
}

string solve(vector<string> &arr) {
  vector<token> tokens;
  for (auto &str : arr) {
    tokens.push_back(tokenize(str));
  }
  vector<string> lefts;
  for (auto &token : tokens) {
    lefts.push_back(token.left);
  }
  vector<string> mids;
  for (auto &token : tokens) {
    mids.push_back(token.mid);
  }
  vector<string> rights;
  for (auto &token : tokens) {
    rights.push_back(token.right);
  }
  string leftLongest = logestString(lefts);
  for (auto &left : lefts) {
    if (!startWith(leftLongest, left)) return "*";
  }
  string rightLongest = logestString(rights);
  for (auto &right : rights) {
    if (!endWith(rightLongest, right)) return "*";
  }
  string ans = "";
  ans += leftLongest;
  for (auto &mid : mids) ans += mid;
  ans += rightLongest;
  return ans;
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
    vector<string> arr;
    for (int i=0; i<N; ++i) {
      string a;
      cin >> a;
      arr.push_back(a);
    }
    string ans = solve(arr);
    cout << "Case #" << t << ": " << ans << '\n';
  }
  return 0;
}