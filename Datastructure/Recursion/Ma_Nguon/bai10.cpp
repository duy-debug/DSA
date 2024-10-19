#include <stdio.h>
long long gt(int n){
    if(n==1) return 1;
    else return gt(n-1)*n;
}
long long xn(int n){
    if(n==0) return 1;
    else{
        long long sum=0;
        for(int i=0; i<n; i++){
            sum+=gt(n-i)*xn(i);
        }
        return sum;
    }
}
int main(){
    int n;
    printf("Nhap n: "); scanf("%d", &n);
    printf("Gia tri Xn= %lld", xn(n));
}
