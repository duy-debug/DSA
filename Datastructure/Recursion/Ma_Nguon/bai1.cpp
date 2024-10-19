#include <stdio.h>
#include <math.h>
#include <stdlib.h>
float S(int n){
    if(n==1) return 1;
    else return S(n-1)+(float)1/n;
}
int main(){
    int n;
    printf("Nhap (n>0): ");
    scanf("%d", &n);
    printf("S= %.2f", S(n));
}
