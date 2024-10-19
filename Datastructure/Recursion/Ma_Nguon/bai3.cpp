#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int S(int n){
	if(n==1) return 1;
	else return S(n-1)+pow(-1,n+1)*n;
}
int main(){
	int n;
	printf("Nhap n:");
	scanf("%d", &n);
	printf("S=%d", S(n));
}
