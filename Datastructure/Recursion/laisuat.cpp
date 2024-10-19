#include <stdio.h>
float Lai_Suat(float x, float a, float b, int n){
	if(n==0) return x;
	else 
		x=x+x*a/100;
		if(n%10==0){
			x+=b;
		}	
		return Lai_Suat(x,a,b,n-1);
}
int main(){
	float x, a, b;
	int n;
	printf("Nhap so tien gui: ");
	scanf("%f", &x);
	printf("Nhap lai suat: ");
	scanf("%f", &a);
	printf("Nhap gia tri qua tang: ");
	scanf("%f", &b);
	printf("Nhap so nam gui tien: ");
	scanf("%d", &n);
	printf("Tong so tien sau khi gui: %.2f", Lai_Suat(x,a,b,n));
}
