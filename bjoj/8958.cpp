#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int n;
    cin >> n;
    char s[80];
    int cnt, sum;
    while(n--) {
        cnt = 0;
        sum = 0;
        cin >> s;
        for(int i=0; i<strlen(s); ++i) {
            if(s[i] == 'O') {
                ++cnt;
                sum += cnt;
            } else {
                cnt = 0;
            }
        }
        cout << sum << '\n';
    }
    return 0;
}
