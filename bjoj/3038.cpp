#include <iostream>
#include <vector>

using namespace std;

vector<int> A, B;
vector<int>& prevL = A;
vector<int>& curL = B;
vector<int> leafs;


void solve(int n) {
    curL.push_back(1);
    leafs.push_back(0);
    for (int i=1; i<n; ++i) {
        swap(prevL, curL);
        curL.clear();
        curL.push_back(1);
        curL.insert(curL.end(), prevL.begin(), prevL.end());
        curL.insert(curL.end(), prevL.begin(), prevL.end());
        int leafSize = leafs.size();
        for (int j=0; j<leafSize; ++j) {
            leafs.push_back((1<<i) + leafs[j]);
            leafs[j]++;
        }
        for (int j=1; j<curL.size(); ++j) {
            curL[j] *= 2;
            if (j < (1<<i)) curL[j]++;
        }
        for (auto j : leafs) {
            if (j < (1<<i)) curL[j]--;
            else curL[j]++;
        }
    }
}

int main() {
    int n;
    cin >> n;
    solve(n);
    for (auto i : curL) {
        cout << i << ' ';
    }
    return 0;
}
