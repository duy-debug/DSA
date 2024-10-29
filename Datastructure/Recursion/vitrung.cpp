#include <stdio.h>
int S(int n, int sogio){
	if(sogio==0) return n;
	else return S(n,sogio-1)*2;
}	
int main(){
	int n, sogio;
	printf("Nhap so vi trung: ");
	scanf("%d", &n);
	printf("Nhap so gio: ");
	scanf("%d", &sogio);
	printf("Tong so vi trung: %d", S(n,sogio));
}
