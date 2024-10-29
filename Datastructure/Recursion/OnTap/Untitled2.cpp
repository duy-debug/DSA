// S(n)=1+1/2+1/3+1/4+1/n
#include <stdio.h>
float S(int n){
	if(n==1) return 1;
	else return S(n-1)+1.0/n;
}
int main(){
	int n;
	printf("Nhap n: ");
	scanf("%d", &n);
	printf("Tong: %.2f", S(n));
}

