#include <stdio.h>
// tim kiem so duong dau tien trong mang
int search(int a[], int l, int r){
	if(l>r) return -1;
	int mid=(l+r)/2;
	if(a[mid]>0){
		int left=search(a,l,mid-1);
		if(left!=-1) return left;
		return mid;
	}
	return search(a,mid+1,r);
}
int main(){
	int n;
	printf("Nhap n: ");
	scanf("%d", &n);
	int a[n];
	for(int i=0; i<n; i++){
		printf("Nhap phan tu thu %d: ", i);
		scanf("%d", &a[i]);
	}
	if(search(a,0,n-1)!=-1)
		printf("Phan tu duong dau tien: %d", a[search(a,0,n-1)]);
	else printf("Khong co phan tu duong!");
}
