// S(n)=1/(1*2)+1/(2*3)+1/(n*(n-1))
#include <stdio.h>
double S(int n){
	if(n==1) return 0;
	else return S(n-1)+1.0/(n*(n-1));
}
int main(){
	int n;
	printf("Nhap n: ");
	scanf("%d", &n);
	printf("Tong: %.2f", S(n));
}
