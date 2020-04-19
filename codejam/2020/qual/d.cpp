#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

int T, B;

string solve() {
  vector<int> bits(B, 0);
  vector<bool> checked(B, false);
  int midLeft = B/2 - 1;
  int midRight = B/2;
  int left = midLeft;
  int right = midRight;
  int queryCnt = 0;
  auto findDiffIndex = [&]() {
    for (int i = midLeft; i>left; --i) {
      if (bits[i] != bits[midRight + midLeft - i]) {
        return i;
      }
    }
    return -1;
  };
  auto findSameIndex = [&]() {
    for (int i = midLeft; i>left; --i) {
      if (bits[i] == bits[midRight + midLeft - i]) {
        return i;
      }
    }
    return -1;
  };
  auto query = [&](int pos) {
    cout << pos+1 << endl;
    int val;
    cin >> val;
    queryCnt++;
    return val;
  };
  auto complement = [&]() {
    for (auto &bit : bits) {
      bit = bit == 1 ? 0 : 1;
    }
  };
  while (left >= 0) {
    if (queryCnt > 0 && queryCnt % 10 == 0) {
      int dIdx = findDiffIndex();
      if (dIdx == -1) {
        int val = query(midLeft);
        if (val != bits[midLeft]) {
          complement();
        }
      } else {
        int val = query(dIdx);
        if (val != bits[dIdx]) {
          int sIdx = findSameIndex();
          if (sIdx == -1) {
            complement();
          } else {
            int sVal = query(sIdx);
            if (sVal != bits[sIdx]) {
              complement();
            } else {
              reverse(bits.begin(), bits.end());
            }
          }
        } else {
          int sIdx = findSameIndex();
          if (sIdx != -1) {
            int sVal = query(sIdx);
            if (sVal != bits[sIdx]) {
              reverse(bits.begin(), bits.end());
              complement();
            }
          }
        }
      }
      while (queryCnt % 10 < 2) {
        query(midLeft); // to make check query cnt 2
      }
    }
    bits[left] = query(left);
    bits[right] = query(right);
    left--;
    right++;
  }
  string ret(B, '*');
  for (int i=0; i<B; ++i) ret[i] = bits[i] + '0';
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> T >> B;
  while (T--) {
    string ans = solve();
    cout << ans << endl;
    string ret;
    cin >> ret;
    assert(ret == "Y");
  }
  return 0;
}