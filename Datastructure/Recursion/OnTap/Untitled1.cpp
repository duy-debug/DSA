#include <stdio.h>
// S(n)=1^2+2^2+3^2+(n-1)^2
int S(int n){
	if(n==1) return 1;
	else return S(n-1)+n*n;
}
int main(){
	int n;
	printf("Nhap n: ");
	scanf("%d", &n);
	printf("Tong: %d", S(n));
}
