#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int mul = a*b*c;
    int cnt[10] = {0};
    while(mul) {
        ++cnt[mul%10];
        mul /= 10;
    }
    for (int i=0; i<10; ++i) {
        cout << cnt[i] << '\n';
    }
    return 0;
}
