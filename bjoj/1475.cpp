#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    if (n==0) {
        cout << 1;
        return 0;
    }
    int arr[10] = {0};
    while(n>0) {
        arr[n%10]++;
        n /= 10;
    }
    arr[6] = (arr[6] + arr[9] + 1)/2;
    arr[9] = 0;
    int m = 0;
    for(int i=0; i<10; ++i) {
        if (arr[i] > m) m = arr[i];
    }
    cout << m;
    return 0;
}
