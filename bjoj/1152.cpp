#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int cnt = 0;
    char s[1000001];
    while(scanf("%s", &s) != EOF) {
        ++cnt;
    }
    cout << cnt;

    return 0;
}
