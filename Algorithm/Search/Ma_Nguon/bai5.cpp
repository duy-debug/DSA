#include <stdio.h>
#include <stdlib.h>
#define MAX_VE 100000
#define MAX_KHACH 100000

// Ham so sanh de sap xep mang giam dan
int cmp_desc(const void *a, const void *b){
    return *(int*)b-*(int*)a;
}
// Ham tim kiem ve phu hop (gia lon nhat khong vuot qua gia toi da)
int timVe(int *ve, int n, int giaToiDa){
    int left=0, right=n-1, result=-1;
    while(left<=right){
        int mid=(left+right)/2;
        if(ve[mid]<=giaToiDa){
            result=mid;
            left=mid+1;
        }else{
            right=mid-1;
        }
    }
    return result;
}

int main() {
    int n, m;
    int ve[MAX_VE], khach[MAX_KHACH];
    // Nhap so ve va so khach
    scanf("%d %d", &n, &m);
    // Nhap gia ve
    for (int i=0; i<n; i++) {
        scanf("%d", &ve[i]);
    }
    // Nhap gia toi da cua tung khach
    for (int i=0; i<m; i++) {
        scanf("%d", &khach[i]);
    }
    // Sap xep mang ve giam dan
    qsort(ve,n,sizeof(int),cmp_desc);

    // Duyet qua tung khach hang
    for (int i=0; i<m; i++) {
        int giaToiDa=khach[i];
        int index=timVe(ve, n, giaToiDa);

        if (index!=-1) {
            printf("%d\n", ve[index]); // In gia ve duoc mua
            for (int j=index; j<n-1; j++) {
                ve[j] = ve[j + 1]; // Xoa ve da ban
            }
            n--; // Giam so luong ve
        } else {
            printf("-1\n"); // Khong co ve phu hop
        }
    }
    return 0;
}

