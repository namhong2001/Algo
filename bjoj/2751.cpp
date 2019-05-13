#include <cstdio>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int arr[10001] = {0};
    while(n--) {
        int a;
        scanf("%d", &a);
        ++arr[a];
    }
    for (int i=0; i<10001; ++i) {
        while(arr[i]--) {
            printf("%d\n", i);
        }
    }

    return 0;
}
