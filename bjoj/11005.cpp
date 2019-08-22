#include <iostream>
#include <algorithm>

using namespace std;

char toC(int num) {
    if (num < 10) return '0'+num;
    else return 'A'+(num-10);
}

int main() {
    int N, B;
    cin >> N >> B;
    string s;
    while (N) {
        s += toC(N%B);
        N/=B;
    }
    reverse(s.begin(), s.end());
    cout << s << endl; 
    return 0;
} 
