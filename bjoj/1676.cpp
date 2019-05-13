#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int count_2 = 0;
    int count_5 = 0;
    for (int i=1; i<=n; ++i) {
        int num = i;
        while (num % 2 == 0) {
            count_2++;
            num /= 2;
        }
        while (num % 5 == 0) {
            count_5++;
            num /= 5;
        }
    }
    int ret = count_2 > count_5 ? count_5 : count_2;
    cout << ret;
    return 0;
}
