#include <iostream>
#include <algorithm>

using namespace std;

int toN(char c) {
    if ('0' <= c && c <= '9') return c-'0';
    else return c-'A'+10;
} 

int main() {
    string N;
    int B;
    cin >> N >> B;
    reverse(N.begin(), N.end());
    int mul = 1;
    int ret = 0;
    for (char c : N) {
        ret += mul * toN(c);
        mul *= B;
    }
    cout << ret << endl; 
    return 0;
}

