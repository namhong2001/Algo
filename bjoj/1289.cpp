#include <iostream>
#include <vector>
#include <utility>

using namespace std;

const long long int MOD = 1e9 + 7;
const long long int N_MAX = 1e5;

vector<pair<int, int>> edges[N_MAX+1];

//long long modInv(long long a, int M) {
//  if (M == 1)
//    return a;
//  if (M == 0)
//    return 1;
//
//  long long  tmp = modInv(a, M / 2);
//  if (M % 2)
//    return (long long)((long long)((tmp*tmp) % MOD)*a) % MOD;
//  else
//    return (long long)(tmp*tmp) % MOD;
//}

long long int ans;
long long int getCost(int me, int parent) {
    vector<long long int> costs;
    long long int costsSum = 0;
    for (auto child : edges[me]) {
        if (child.first == parent) continue;
        long long int childCost = getCost(child.first, me);
        long long int cost = (child.second + childCost * child.second) % MOD;
        costs.push_back(cost);
        costsSum = (costsSum + cost) % MOD;
    }
    long long int neighborCost = (costsSum * costsSum) % MOD;
    for (long long int cost : costs) {
        neighborCost = (neighborCost + (MOD - cost) * cost) % MOD;
    }

    neighborCost = (neighborCost * 500000004) % MOD;
    return costsSum;
    ans = (ans + neighborCost + costsSum) % MOD;
}

int main() {
    int n;
    int a, b, w;
    cin >> n;
    for (int i=0; i<n-1; ++i) {
        cin >> a >> b >> w;
        edges[a].push_back({b, w});
        edges[b].push_back({a, w});
    }
    getCost(a, a);
    cout << ans;
    return 0;
}
