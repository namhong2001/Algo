#include <iostream>

using namespace std;


int main() {
    int c;
    cin >> c;
    bool flag[1001] = {false};
    flag[0] = flag[1] = true;
    for (int i=2; i<1001; ++i) {
        for (int j=i; i*j<1001; ++j) {
            flag[i*j] = true;
        }
    }

    while(c--) {
        int n;
        cin >> n;
        int recipe[200];
        for (int i=0; i<n; ++i) {
            cin >> recipe[i];
        }
        int cur[200];
        for (int i=0; i<n; ++i) {
            cin >> cur[i];
        }
        for (int i=0; i<1001; ++i) {
            if (flag[i]) continue;

            int j;
            for(j=0; j<n; ++j) {
                if(recipe[j] % i > 0) break;
            }
            if (j==n) {
                for(int k=0; k<n; ++k) {
                    recipe[k] /= i;
                }
            }
        }
        int max_factor = 0;
        for (int i=0; i<n; ++i) {
            int candidate = cur[i] % recipe[i] ? cur[i] / recipe[i] + 1 : cur[i] / recipe[i];
            if (candidate > max_factor) {
                max_factor = candidate;
            }
        }
        for (int i=0; i<n; ++i) {
            recipe[i] *= max_factor;
        }
        for (int i=0; i<n; ++i) {
            cout << recipe[i] - cur[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
