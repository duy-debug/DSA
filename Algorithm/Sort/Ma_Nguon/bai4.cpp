#include <stdio.h>
#include <stdlib.h>
int n, a[1000];
void readfile(char *s){
	FILE *f=fopen(s,"r");
	if(f==NULL){
		printf("Khong the mo file");
	}
	else{
		fscanf(f,"%d",&n);
		for(int i=0; i<n; i++){
			fscanf(f,"%d",&a[i]);
		}
		fclose(f);
	}
}
void Print(){
	printf("%d\n", n);
	for(int i=0; i<n; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
}
void swap(int &x, int &y){
	int tem=x;
	x=y;
	y=tem;
}
void sort(){
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(a[i]>0 && a[j]>0 && a[i]>a[j])
				swap(a[i],a[j]);
		}
	}
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(a[i]<0 && a[j]<0 && a[i]<a[j])
				swap(a[i],a[j]);
		}
	}
}
void writefile(){
	FILE *f=fopen("output.txt","w");
	if(f==NULL){
		printf("Khong the mo file");
	}
	else{
		for(int i=0; i<n; i++){
			fprintf(f,"%d ",a[i]);
		}
		fclose(f);
	}
}
int main(){
	char *s="input.txt";
	readfile(s);
	Print();
	sort();
	writefile();
}
