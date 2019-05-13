#include <cstdio>

int main() {
    int n;
    int ret = 0;
    scanf("%d", &n);
//    while(n>=3) {
//        if (n%5 == 0) {
//            ret += n/5;
//            n=0;
//        } else {
//            n -= 3;
//            ret++;
//        }
//    }
//    if (n) {
//        printf("-1");
//    } else {
//        printf("%d", ret);
//    }
    printf("%d",n-4&&n-7?1+--n/5+n%5%2:-1);
    return 0;
}
