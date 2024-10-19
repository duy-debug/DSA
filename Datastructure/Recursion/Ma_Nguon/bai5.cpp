#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int SoLuongChuSo(int n){
	if(n<10) return 1;
	else return 1+SoLuongChuSo(n/10);
}
int main(){
	int n;
	printf("Nhap n:");
	scanf("%d", &n);
	printf("So luong chu so: %d", SoLuongChuSo(n));
}
