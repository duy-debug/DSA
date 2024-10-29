// S(n)=x+x^2/2+x^3/3+x^n/n
#include <stdio.h>
#include <math.h>
float S(int n, int x){
	if(n==1) return x;
	else return S(n-1,x)+(float)pow(x,n)/n;
}
int main(){
	int n,x;
	printf("Nhap n: ");
	scanf("%d", &n);
	printf("Nhap x: ");
	scanf("%d", &x);
	printf("Tong: %.2f", S(n,x));
}
