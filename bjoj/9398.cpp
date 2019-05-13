#include <cstdio>

int main() {
    int n;
    const char grade[] = {'A', 'B', 'C', 'D', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F'};
    scanf("%d", &n);
    printf("%c", grade[(100-n-1)/10]);
    return 0;


}
