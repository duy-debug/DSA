#include <stdio.h>
#include <math.h>
#include <stdlib.h>
float LaiSuat(float x, float a, float b, int n){
	if(n==0) return x;
	else
		x*=(1+a/100);
		if(n%10==0){
			x+=b;
		}
		return LaiSuat(x,a,b,n-1);
}
int main(){
	float x, a, b;
	int n;
	printf("Nhap so tien gui ban dau: "); scanf("%f", &x);
	printf("Nhap lai suat hang nam: "); scanf("%f", &a);
	printf("Nhap gia tri qua tang sau 10 nam: "); scanf("%f", &b);
	printf("Nhap so nam gui: "); scanf("%d", &n);
	printf("So tienÅn sau khi gui: %f", LaiSuat(x,a,b,n));
}
