#include <iostream>

using namespace std;

int main() {
    int n, a, cnt = 0;
    int x,y;
    cin >> n;
    a = n;


    while(n != a || cnt == 0) {
        ++cnt;
        a = a%10*10 + (a/10 + a%10)%10;
    }
    cout << cnt;

    return 0;
}
