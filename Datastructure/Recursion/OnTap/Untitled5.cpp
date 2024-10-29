// S(n)=1/(1+1/(1+1/(1+1/(...1/(1/1+1/(1+1))))))
#include <stdio.h>
float S(int n){
	if(n==1) return 1;
	else return 1.0/(1+S(n-1));
}
int main(){
	int n;
	printf("Nhap n: ");
	scanf("%d", &n);
	printf("Tong: %.2f", S(n));
}
