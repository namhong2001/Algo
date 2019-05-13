#include <cstdio>

int main() {
    char c[101];
    while(fgets(c, sizeof c, stdin)) {
        printf("%s", c);
    }
    return 0;
}
