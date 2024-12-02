#include<stdio.h>
#include <stdlib.h>
#include<string.h>
struct sinhVien{
	char maSV[100];
	char hoTen[100];
	float diemTB;
};

char* getHo(char hoTen[]){
	int i=0;
	char ho[10];
	while(hoTen[i]!=' '){
		ho[i]=hoTen[i];
		i++;
	}
	return ho;
}
char* getTen(char hoTen[]){
	int i=0;
	while(hoTen[i]!=' '){
		i++;
	}
	i++;
	char ten[100];
	int j=0;
	while(i<strlen(hoTen)){
		ten[j]=hoTen[i];
		i++;
		j++;
	}
	return ten;
}
int docfile( char *filename, sinhVien ds[], int &n) {
    FILE *file = fopen(filename, "r");
    if (file==NULL) {
        printf("Khong the mo file");
        return 0;
    }

    while (fscanf(file, "%s %[^0123456789] %f", ds[n].maSV, ds[n].hoTen, &ds[n].diemTB) == 3) {
    	ds[n].hoTen[strlen(ds[n].hoTen)-1]='\0';
        n++;
    }
    fclose(file);
    return 1;
}

void ghifile(char *filename, sinhVien ds[], int n) {
    FILE *file = fopen(filename, "w");
    if (file==NULL) {
        printf("Khong the mo file");
        return ;
    }

    for (int i = 0; i < n; i++) {
        fprintf(file, "%s %s %.2f\n", ds[i].maSV, ds[i].hoTen, ds[i].diemTB);
    }
   
    fclose(file);
    
}

void swap(sinhVien &a, sinhVien &b){
	sinhVien tam = a;
	a = b;
	b = tam;
}
void sxMSSV(sinhVien ds[], int n){
	
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(strcmp(ds[i].maSV,ds[j].maSV)<0){
				swap(ds[i],ds[j]);
			}
		}
	}
}
void sxHo(sinhVien ds[], int n){
	
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(strcmp(getHo(ds[i].hoTen),getHo(ds[j].hoTen))<0){
				swap(ds[i],ds[j]);
			}
		}
	}
}
void sxTen(sinhVien ds[], int n){
	
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(strcmp(getTen(ds[i].hoTen),getTen(ds[j].hoTen))<0){
				swap(ds[i],ds[j]);
			}
		}
	}
}
void sxdiemTB(sinhVien ds[], int n){
	
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(ds[i].diemTB>ds[j].diemTB){
				swap(ds[i],ds[j]);
			}
		}
	}
}

int main(){
	sinhVien ds[100];
	int n=0;
	if(!docfile("sinhvien.inp.txt",ds,n)){
		return 0;
	}
	for(int i=0;i<n;i++){
		printf("%s ",ds[i].maSV);
		fputs(ds[i].hoTen, stdout);
		printf(" %.2f\n",ds[i].diemTB);
	}
	int choice;
	printf("Chon tieu chi sap xep:\n");
    printf("1. Ma so sinh vien\n");
    printf("2. Ho\n");
    printf("3. Ten\n");
    printf("4. Diem trung binh\n");
    printf("Nhap lua chon cua ban: ");
	scanf("%d",&choice);
	
	switch (choice) {
        case 1:
            sxMSSV(ds,n);
            break;
        case 2:
            sxHo(ds,n);
            break;
        case 3:
            sxTen(ds,n);
            break;
        case 4:
            sxdiemTB(ds,n);
            break;
        default:
            printf("Lua chon khong hop le!\n");
            return 0;
    }
    ghifile("sinhvien.out.txt",ds,n);
}
