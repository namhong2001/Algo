#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int n;
    cin >> n;
    int seq[n];
    char op[2*n];
    int stk[n];
    for(int i=0; i<n; ++i) {
        scanf("%d", &seq[i]);
    }
    int pos = -1;
    int curNum = 1;
    for (int i=0, opi=0; i<n; ++i){
        while(seq[i] >= curNum) {
            ++pos;
            stk[pos] = curNum;
            ++curNum;
            op[opi] = '+';
            ++opi;
        }
        if (seq[i] == stk[pos]) {
            op[opi] = '-';
            ++opi;
            --pos;
        } else {
            cout << "NO";
            return 0;
        }
    }
    for (auto i : op) {
        printf("%c\n", i);
    }
    return 0;
}
