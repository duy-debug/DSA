#include <stdio.h>
#include <stdlib.h>
int n, a[1000];
// doc du lieu tu file
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
	printf("%d\n",n);
	for(int i=0; i<n; i++){
		printf("%d ",a[i]);
	} 
	printf("\n");
}
void swap(int &x, int &y){
	int tem=x;
	x=y;
	y=tem;
}
// Tu nho den lon
void Selection_sort(){
	for(int i=0; i<n-1; i++){
		int min=i;
		for(int j=i+1; j<n; j++){
			if(a[min]>a[j])
			min=j;
		}
		swap(a[min],a[i]);
	}
}
// Tu lon den nho
void Selection1_sort(){
	for(int i=0; i<n-1; i++){
		int max=i;
		for(int j=i+1; j<n; j++){
			if(a[max]<a[j])
			max=j;
		}
		swap(a[max],a[i]);
	}
}
// Tu nho den lon
void Insertion_sort(){
	for(int i=1; i<n; i++){
		int x=a[i], pos=i-1;
		while(pos>=0 && x<a[pos]){
			a[pos+1]=a[pos];
			pos--;
		}
		a[pos+1]=x;
	}
}
// Tu lon den nho
void Insertion1_sort(){
	for(int i=1; i<n; i++){
		int x=a[i], pos=i-1;
		while(pos>=0 && x>a[pos]){
			a[pos+1]=a[pos];
			pos--;
		}
		a[pos+1]=x;
	}
}
// Tu nho den lon
void Bubble_sort(){
	for(int i=0; i<n-1; i++){
		for(int j=0; j<n-i-1; j++){
			if(a[j]>a[j+1]){
				swap(a[j],a[j+1]);	
			}
		}
	}
}
// Tu lon den nho
void Bubble1_sort(){
	for(int i=0; i<n-1; i++){
		for(int j=0; j<n-i-1; j++){
			if(a[j]<a[j+1])
				swap(a[j],a[j+1]);
		}
	}
}
int main(){
	char *s="Dayso.txt";
	readfile(s);
	Print();
	Selection_sort();
	Print();
	Selection1_sort();
	Print();
	Insertion_sort();
	Print();
	Insertion1_sort();
	Print();
	Bubble_sort();
	Print();
	Bubble1_sort();
	Print();
}
