#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int c;
    cin >> c;
    while(c--) {
        int n;
        cin >> n;
        vector<int> cache;
        while (n--) {
            int num;
            cin >> num;
            auto it = lower_bound(cache.begin(), cache.end(), num);
            if (it == cache.end()) cache.push_back(num);
            else *it = num;
        }

        cout << cache.size() << endl;
    }

    return 0;
}

