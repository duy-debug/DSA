#include <stdio.h>
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
int partition(int low, int high) {
    int pivot=a[high];  // chon phan tu chot
    int i=(low-1);      // vi tri cua phan tu nho hon

    for (int j=low; j<high; j++) {
        if (a[j]<=pivot) {
            i++;
            // Hoan doi a[i] va a[j] 
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    // dua phan tu chot ve dung vi tri
    int temp=a[i+1];
    a[i+1]=a[high];
    a[high]=temp;
    return (i+1);
}
// Tu nho den lon
void Quick_sort(int low, int high) {
    if(low<high){
        int p=partition(low,high);  // chia mang va tra ve chi so cua pt chot

        // sap xep cac phan tu mang con
        Quick_sort(low,p-1);  // Mang con ben trai
        Quick_sort(p+1,high); // Mang con ben phai
    }
}
int partition1(int low, int high) {
    int pivot=a[high];  // chon phan tu chot
    int i=(low-1);      // vi tri cua phan tu nho hon
    for (int j=low; j<high; j++) {
        if (a[j]>=pivot) {
            i++;
            // Hoan doi a[i] va a[j] 
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    // dua phan tu chot ve dung vi tri
    int temp=a[i+1];
    a[i+1]=a[high];
    a[high]=temp;
    return (i+1);
}
// Tu lon den nho
void Quick_sort1(int low, int high) {
    if(low<high){
        int p=partition1(low,high);  // chia mang va tra ve chi so cua pt chot

        // sap xep cac phan tu mang con
        Quick_sort1(low,p-1);  // Mang con ben trai
        Quick_sort1(p+1,high); // Mang con ben phai
    }
}

// Ham heapify mot cay con co goc tai node i
void heapify(int a[], int n, int i){
    int largest=i; // Khoi tao largest la goc
    int l=2*i+1; // con trai = 2*i + 1
    int r=2*i+2; // con phai = 2*i + 2
    // Neu con trai lon hon goc
    if (l<n && a[l]>a[largest])
        largest = l;
    // Neu con phai lon hon gia tri lon nhat hien tai
    if (r<n && a[r]>a[largest])
        largest=r;
    // Neu largest khong phai la goc
    if (largest!=i){
        swap(a[i],a[largest]);
        // De quy heapify cay con bi anh huong
        heapify(a,n,largest);
    }
}
// Ham chinh de thuc hien Heap Sort
// Tu nho den lon
void Heap_sort(int a[], int n){
    // Xay dung heap (chuyen mang thanh heap)
    for (int i=n/2-1; i>=0; i--)
        heapify(a,n,i);
    // Tung buoc trich xuat phan tu tu heap
    for (int i=n-1; i>0; i--) {
        // Di chuyen goc hien tai (lon nhat) ve cuoi
        swap(a[0],a[i]);
        // Goi heapify cho heap bi giam
        heapify(a,i,0);
    }
}
// Ham heapify mot cay con co goc tai node i
void heapify1(int a[], int n, int i){
    int largest=i; // Khoi tao largest la goc
    int l=2*i+1; // con trai = 2*i + 1
    int r=2*i+2; // con phai = 2*i + 2
    // Neu con trai nho hon goc
    if (l<n && a[l]<a[largest])
        largest = l;
    // Neu con phai nho hon gia tri nho nhat hien tai
    if (r<n && a[r]<a[largest])
        largest=r;
    // Neu largest khong phai la goc
    if (largest!=i){
        swap(a[i],a[largest]);
        // De quy heapify cay con bi anh huong
        heapify1(a,n,largest);
    }
}
// Ham chinh de thuc hien Heap Sort
// Tu lon den nho
void Heap_sort1(int a[], int n){
    // Xay dung Min heap (chuyen mang thanh heap)
    for (int i=n/2-1; i>=0; i--)
        heapify1(a,n,i);
    // Tung buoc trich xuat phan tu tu heap
    for (int i=n-1; i>0; i--) {
        // Di chuyen goc hien tai (nho nhat) ve cuoi
        swap(a[0],a[i]);
        // Goi heapify cho heap bi giam
        heapify1(a,i,0);
    }
}
void Merge(int a[], int i1, int j1, int i2, int j2) {
    int temp[50];   // Mang tam dung de tron
    int i, j, k;
    i=i1; // Bat dau cua danh sach thu nhat
    j=i2; // Bat dau cua danh sach thu hai
    k=0;
    while(i<=j1 && j<=j2) { // Khi con phan tu trong ca hai danh sach
        if (a[i]<a[j])
            temp[k++]=a[i++];
        else
            temp[k++]=a[j++];
    }
    while(i<=j1) // Sao chep cac phan tu con lai cua danh sach thu nhat
        temp[k++]=a[i++];
    while (j<=j2) // Sao chep cac phan tu con lai cua danh sach thu hai
        temp[k++]=a[j++];
    // Chuyen cac phan tu tu temp[] quay lai mang a[]
    for (i = i1, j = 0; i <= j2; i++, j++)
        a[i] = temp[j];
}
//Tu nho den lon
void Merge_sort(int a[], int i, int j) {
    int mid;
    if(i<j){
        mid=(i+j)/2;
        Merge_sort(a,i,mid); // De quy ben trai
        Merge_sort(a,mid+1,j); // De quy ben phai
        Merge(a,i,mid,mid+1,j); // Tron hai mang con da duoc sap xep
    }
}
void Merge1(int a[], int i1, int j1, int i2, int j2) {
    int temp[50];   // Mang tam dung de tron
    int i, j, k;
    i=i1; // Bat dau cua danh sach thu nhat
    j=i2; // Bat dau cua danh sach thu hai
    k=0;
    while(i<=j1 && j<=j2) { // Khi con phan tu trong ca hai danh sach
        if (a[i]>a[j])
            temp[k++]=a[i++];
        else
            temp[k++]=a[j++];
    }
    while(i<=j1) // Sao chep cac phan tu con lai cua danh sach thu nhat
        temp[k++]=a[i++];
    while (j<=j2) // Sao chep cac phan tu con lai cua danh sach thu hai
        temp[k++]=a[j++];
    // Chuyen cac phan tu tu temp[] quay lai mang a[]
    for (i = i1, j = 0; i <= j2; i++, j++)
        a[i] = temp[j];
}
//Tu lon den nho
void Merge_sort1(int a[], int i, int j) {
    int mid;
    if(i<j){
        mid=(i+j)/2;
        Merge_sort1(a,i,mid); // De quy ben trai
        Merge_sort1(a,mid+1,j); // De quy ben phai
        Merge1(a,i,mid,mid+1,j); // Tron hai mang con da duoc sap xep
    }
}
int main(){
	char *s="Dayso.txt";
	readfile(s);
	Print();
	Quick_sort(0,n-1);
	Print();
	Quick_sort1(0,n-1);
	Print();
	Heap_sort(a,n);
	Print();
	Heap_sort1(a,n);
	Print();
	Merge_sort(a,0,n-1);
	Print();
	Merge_sort1(a,0,n-1);
	Print();
}
