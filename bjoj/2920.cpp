#include <cstdio>
#include <cstring>


using namespace std;

int main() {
    char s[9];
    s[8] = '\0';
    for(int i=0; i<8; ++i) {
        scanf(" %c", &s[i]);
    }
    if (strcmp(s, "12345678") == 0) {
        printf("ascending");
    } else if (strcmp(s, "87654321") == 0) {
        printf("descending");
    } else {
        printf("mixed");
    }

    return 0;

}
