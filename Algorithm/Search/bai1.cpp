#include <stdio.h>
// tim kiem tuan tu
int Search(int a[], int n, int x){
	for(int i=0; i<n; i++){
		if(a[i]==x) return i;
	}
	return -1;
}
// tim kiem nhi phan
int Search_binary(int a[], int l, int r, int x){
	if(l>r) return -1;
	else {
		int mid=(l+r)/2;
		if(a[mid]==x)
			return mid;
		if(x<a[mid]) return Search_binary(a,l,mid-1,x);
		else return Search_binary(a,mid+1,r,x);
	}
}
void sort(int a[], int n){
	for(int i=0; i<n-1; i++)
		for(int j=i+1; j<n; j++){
			if(a[i]>a[j]){
				int tem=a[i];
				a[i]=a[j];
				a[j]=tem;
			}
		}
}
struct node{
	int data;
	node *next;
};
typedef struct node node;
int main(){
	int n;
	printf("Nhap n: ");
	scanf("%d", &n);
	int a[n];
	for(int i=0; i<n; i++){
		printf("Nhap phan tu thu %d: ",i);
		scanf("%d", &a[i]);
	}
	int x;
	printf("Nhap x: ");
	scanf("%d", &x);	
	if(Search(a,n,x)!=-1)
		printf("Tim thay phan tu x!\n");
	else printf("Khong tim thay x\n");
	sort(a,n);
	if(Search_binary(a,0,n-1,x)!=-1)
		printf("Tim thay phan tu x!\n");
	else printf("Khong tim thay x\n");
	
}
