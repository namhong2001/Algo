#include <stdio.h>

int main(){
int a=0, A[1020]={0, }, i=0, j=0, B[1020]={0, };
scanf("%d",&a);
for(i=0;i<a;i++) scanf("%d", A+i);
A[a]=10000;
for(i=0;i<=a;i++){
    for(j=0;j<i;j++){
        if(A[j]<A[i] && B[j]>B[i]) B[i]=B[j];
    }
    B[i]++;
}
printf("%d", B[a]-1);
}
