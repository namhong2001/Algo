#include <iostream>

using namespace std;

int main() {
    int x;
    cin >> x;
    int i, sum;
    for(i=1, sum=0; sum < x; ++i) {
        sum += i;
    }
    if (i%2) {
        cout << i-sum+x-1 << '/' << sum+1-x;
    } else {
        cout << sum+1-x << '/' << i-sum+x-1;
    }
    return 0;
}
