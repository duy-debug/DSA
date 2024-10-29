#include <stdio.h>
float laisuat(float x, float a, float b, int n){
	if(n==0) return x;
	else{
		x+=1.0*x*a/100;
		if(n%10==0)
			x+=b;
		return laisuat(x,a,b,n-1);
	} 
}
int main(){
	float x, a, b;
	int n;
	printf("Nhap so tien muon gui: ");
	scanf("%f", &x);
	printf("Nhap lai suat: ");
	scanf("%f", &a);
	printf("Nhap so tien thuong: ");
	scanf("%f", &b);
	printf("Nhap so nam: ");
	scanf("%d", &n);
	printf("So tien nhan duoc: %.2f", laisuat(x,a,b,b));
}
