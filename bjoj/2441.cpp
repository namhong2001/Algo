#include <cstdio>
#include <iostream>

using namespace std;


int main() {
    int n;
    cin >> n;

    for(int i=0; i<n; i++) {
        for(int blk=i; blk > 0; --blk) {
            printf(" ");
        }
        for(int st=n-i; st > 0; --st) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}

