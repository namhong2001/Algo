#include <iostream>

using namespace std;

const int MAX_N = 90;

long long int fibo_memo[MAX_N+1] = {0};

long long int fibo(int n) {
    if (n <= 1) return n;
    if (fibo_memo[n]) return fibo_memo[n];
    else {
        fibo_memo[n] = fibo(n-2) + fibo(n-1);
        return fibo_memo[n];
    }
}

int main() {
    int n;
    cin >> n;
    cout << fibo(n);
    return 0;
}
