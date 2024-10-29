// S(n)=1+1/3+1/5+1/(2n+1)
#include <stdio.h>
float S(int n){
	if(n==0) return 1;
	else return S(n-1)+1.0/(2*n+1);
}
int main(){
	int n;
	printf("Nhap n: ");
	scanf("%d", &n);
	printf("Tong: %.2f", S(n));
}
