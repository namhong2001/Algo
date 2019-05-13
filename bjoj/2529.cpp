#include <cstdio>
#include <iostream>

using namespace std;


int k;
char signs[10];

string solve() {
    int ans[10];
    bool used[10];
    memset(ans, -1, sizeof(ans));
    memset(used, false, sizeof(used));

    for (int i=0; i<k; ++i) {
        if (signs[i] == '<') continue;
        int digit;
        for (digit=9; digit>=0; --digit) {
            if (used[digit]) continue;
        }
        ans[i] = digit;

    }


}

int main() {
    cin >> k;
    for (int i=0; i<k; ++i) {
        scanf(" %c", &signs[i]);
    }

    return 0;
}
