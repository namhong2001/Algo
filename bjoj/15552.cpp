#include <cstdio>

int main() {
    int n, a, b;
    scanf("%d\n", &n);
    while(n--) {
        scanf("%d %d\n", &a, &b);
        printf("%d\n", a+b);
    }
    return 0;
}
