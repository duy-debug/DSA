// Hoan doi phan tu nho nhat dau tien voi phan tu lon nhat cuoi cung
#include <stdio.h>	
void swap(int &x, int &y){
	int tem=x;
	x=y;
	y=tem;
}
int search(int a[], int l, int r){
	if(l==r) return l;
	int mid=(l+r)/2;
	int checkleft=search(a,l,mid);
	int checkright=search(a,mid+1,r);
	return a[checkleft]<=a[checkright]?checkleft:checkright;
}
int search1(int a[], int l, int r){
	if(l==r) return l;
	int mid=(l+r)/2;
	int checkleft=search1(a,l,mid);
	int checkright=search1(a,mid+1,r);
	return a[checkright]>=a[checkleft]?checkright:checkleft;
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
	swap(a[search(a,0,n-1)],a[search1(a,0,n-1)]);
	for(int i=0; i<n; i++){
		printf("%d ", a[i]);
	}
}
