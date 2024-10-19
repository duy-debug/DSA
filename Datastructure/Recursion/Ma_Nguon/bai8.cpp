#include <stdio.h>
long long Xn(int n){
    if(n==0) return 0;
    else if(n==1) return 1;
    else{
        long long a=Xn(n-1)+Xn(n-2);
        long long b=Xn(n-1)-Xn(n-2);
        return a*a+b*b;
    }
}
int main(){
    int n;
    printf("Nhap n: "); scanf("%d", &n);
    printf("Gia tri cua Xn=%lld", Xn(n));
    return 0;
}