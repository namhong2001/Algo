#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[10] = {0};
    while(n>0) {
        arr[n%10]++;
        n /= 10;
    }
    for (int i=9; i>=0; --i) {
        for (int k=0; k<arr[i]; ++k) {
            printf("%d", i);
        }
    }
    return 0;
}
