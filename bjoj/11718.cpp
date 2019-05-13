#include <cstdio>

int main() {
    char s[100];
    while(scanf("%[^\n]\n", s) == 1) {
        printf("%s\n", s);
    }
    return 0;
}
