#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int gt(int n){
	if(n==1) return 1;
	else return n*gt(n-1);
}
int S(int n){
	if(n==1) return 1;
	else return gt(n)+S(n-1);
}
int main(){
	int n;
	printf("Nhap n:");
	scanf("%d", &n);
	printf("S=%d", S(n));
}
