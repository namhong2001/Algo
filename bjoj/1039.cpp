#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;

int pow(int a, int b) {
    int ret = 1;
    while (b--) ret *= a;
    return ret;
}

int bfs(int n, int k) {
    unordered_set<int> items;
    items.insert(n);

    while (k--) {
        unordered_set<int> n_items;
        for (int here : items) {
            int digits = 0;
            while (here/pow(10, digits)) digits++;
            for (int i=0; i<digits; ++i) {
                for (int j=i+1; j<digits; ++j) {
                    int a = here/pow(10, i) % 10;
                    int b = here/pow(10, j) % 10;
                    if (a == 0 && j == digits-1) continue;
                    int next = here-a*pow(10, i)+a*pow(10,j)-b*pow(10, j)+b*pow(10,i);
                    n_items.insert(next);
                }
            }
        }
        swap(items, n_items);
    }

    int ret = -1;
    for (int here : items) {
        ret = max(ret, here);
    }
    return ret;
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << bfs(n, k) << endl;

    return 0;
}
