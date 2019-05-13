#include <iostream>

using namespace std;

int main() {
    const int N = 10000;
    bool n[N+1] = {false};
    for(int i=1; i<=N; ++i) {

        if (!n[i]) {
            cout << i << '\n';
        }
        int c = i;
        int d = i;

        while(c>0) {
            d += c%10;
            c /= 10;
        }
        n[d] = true;
    }

    return 0;
}
