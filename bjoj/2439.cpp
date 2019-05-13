#include <cstdio>
#include <iostream>

using namespace std;


int main() {
    int n;
    cin >> n;

    for(int i=1; i<=n; i++) {
        for(int blk=n-i; blk > 0; --blk) {
            printf(" ");
        }
        for(int st=0; st<i; ++st) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}

