#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int R, N;
    cin >> R >> N;
    int arr[N];
    for (int i=0; i<N; ++i) cin >> arr[i];
    int cnt4 = R;
    int cnt2 = 2*R;
    for (int i=0; i<N; ++i) {
        while (arr[i] >= 4 && cnt4) {
            arr[i] -= 4;
            cnt4--;
        }
    }
    if (cnt4) {
        for (int i=0; i<N; ++i) {
            if (arr[i] == 3 && cnt4) {
                arr[i] = 0;
                cnt4--;
            }
        }
    }
    if (cnt4) {
        int two = 0;
        int one = 0;
        for (int i=0; i<N; ++i) {
            if (arr[i] == 2) two++;
            else if (arr[i] == 1) one++;
        }
        int m = min({two, one, cnt4});
        cnt4 -= m;
        two -= m;
        one -= m;
        int mm = min(one/2, cnt4);
        one -= 2*mm;
        cnt4 -= mm;
        int need = two + one;
        int has = cnt4 + cnt2;
        if (need > has) {
            cout << "NO";
            return 0;
        }
        cout << "YES";
        return 0;
    }
    // now we dont have cnt4
    for (int i=0; i<N; ++i) {
        cnt2 -= (arr[i]+1) / 2;
    }
    if (cnt2 < 0) {
        cout << "NO";
    } else {
        cout << "YES";
    }
    return 0;
}