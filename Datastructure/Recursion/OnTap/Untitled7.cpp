// Tong cac chu so chan cua so nguyen duong
#include <stdio.h>
int Tong(int n){	
	if(n==0) return 0;
	if(n%10%2==0) return n%10+Tong(n/10);
	else return Tong(n/10);
}
int main(){
	int n;
	printf("Nhap n: ");
	scanf("%d", &n);
	printf("Tong so chu so chan: %d", Tong(n));
}
