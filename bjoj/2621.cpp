#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

vector<string> color(5);
vector<int> num(5);
map<int,int> numCnt;
set<string> colorType;

int maxn;

bool checkStraight() {
  sort(num.begin(), num.end());
  for (int i=0; i<4; ++i) {
    if (num[i] != num[i+1]-1) return false;
  }
  return true;
}


int check900() {
  if (colorType.size() == 1 && checkStraight()) {
    return 900 + maxn;
  }
  return -1;
}

int check800() {
  if (numCnt.size() == 2) {
    auto a = numCnt.begin();
    auto b = next(a);
    if (a->second == 1) return b->first + 800;
    if (b->second == 1) return a->first + 800;
  }
  return -1;
}

int check700() {
  if (numCnt.size() == 2) {
    auto a = numCnt.begin();
    auto b = next(a);
    if (a->second == 3) return a->first * 10 + b->first + 700;
    else return b->first * 10 + a->first + 700;
  }
  return -1;
}

int check600() {
  if (colorType.size() == 1) {
    return maxn + 600;
  }
  return -1;
}

int check500() {
  if (checkStraight()) {
    return maxn + 500;
  }
  return -1;
}
int check400() {
  for (auto x : numCnt) {
    if (x.second == 3) {
      return x.first + 400;
    }
  }
  return -1;
}

int check300() {
  if (numCnt.size() == 3) {
    vector<int> targets;
    for (auto x : numCnt) {
      if (x.second == 2) {
        targets.push_back(x.first);
      }
    }
    if (targets.size() == 2) {
      return max(targets[0], targets[1]) * 10 + 
        min(targets[0], targets[1]) + 300;
    }
  }
  return -1;
}

int check200() {
  for (auto x : numCnt) {
    if (x.second == 2) return x.first + 200;
  }
  return -1;
}

int check100() {
  return maxn + 100;
}




int solve() {
  return max({
    check900(),
    check800(),
    check700(),
    check600(),
    check500(),
    check400(),
    check300(),
    check200(),
    check100()
  });
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  for (int i=0; i<5; ++i) {
    string c;
    int n;
    cin >> c >> n;
    color[i] = c;
    num[i] = n;
    numCnt[n]++;
    colorType.insert(c);
  }
  maxn = *max_element(num.begin(), num.end());
  cout << solve();
  return 0;
}