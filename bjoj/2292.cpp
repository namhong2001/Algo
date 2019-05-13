#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int i, sum;
    for(i=1, sum=1; sum < n; ++i) {
        sum += 6*i;
    }
    cout << i;
    return 0;
}
