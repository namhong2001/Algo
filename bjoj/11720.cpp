#include <cstdio>

int main() {
    int n, x, sum = 0;
    scanf("%d\n", &n);
    while(n--) {
        scanf("%1d", &x);
        sum += x;
    }
    printf("%d", sum);
    return 0;
}
