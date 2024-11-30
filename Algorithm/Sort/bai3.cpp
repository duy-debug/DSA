#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct sinhvien{
	int mssv;
	char ten[50];
	float dtb;
};
sinhvien *sv;
int n;
void readfile(char *s){
	FILE *f=fopen(s,"r");
	if(f==NULL){
		printf("Khong the mo file");
	}
	else{
		char temp[255];
		fscanf(f,"%d",&n);
		sv=(sinhvien*)malloc(n*sizeof(sinhvien));
		for(int i=0; i<n; i++){
			fscanf(f,"%d",&sv[i].mssv);
			fgetc(f);
			fgets(sv[i].ten, sizeof(sv[i].ten), f);
			sv[i].ten[strcspn(sv[i].ten, "\n")] = '\0';
			fscanf(f,"%f",&sv[i].dtb);
		}
		fclose(f);
	}
}
void Print(){
	printf("So sinh vien: %d\n", n);
	for(int i=0; i<n; i++){
		printf("%d	", sv[i].mssv);
		printf("%s	", sv[i].ten);
		printf("%.2f\n", sv[i].dtb);
	}
}
int main(){
	char *s="sinhvien.inp.txt";
	readfile(s);
	Print();
}
