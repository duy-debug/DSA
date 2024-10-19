#include <stdio.h>
int Xn(int n);
int Yn(int n);
int Xn(int n){
    if(n==0) return 1;
    else return 2*Xn(n-1)+3*Yn(n-1);
}
int Yn(int n){
    if(n==0) return 1;
    else return 3*Xn(n-1)-2*Yn(n-1);
}
int main(){
    int n;
    printf("Nhap n: "); scanf("%d", &n);
    printf("Gia tri xn= %d\n", Xn(n));
    printf("Gia tri yn= %d", Yn(n));
}