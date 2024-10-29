// So luong chu so cua so nguyen duong
#include <stdio.h>
int Soluong(int n){
	if(n<10) return 1;
	else return Soluong(n/10)+1;
}
int main(){
	int n;
	printf("Nhap n:");
	scanf("%d", &n);
	printf("Tong chu so so nguyen duong: %d", Soluong(n));
}
