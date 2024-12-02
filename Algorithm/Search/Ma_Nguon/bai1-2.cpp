#include <stdio.h>
#include <stdlib.h>
#define M 9 // Kich thuoc bang bam

// Cau truc cua bang bam
typedef struct {
    int key;   // Gia tri
    int next;  // Chi so cua phan tu tiep theo (neu co)
} HashTable;

// Khoi tao bang bam
void init(HashTable B[]) {
    for (int i = 0; i < M; i++) {
        B[i].key = 0;    // Gia tri mac dinh = 0 (chua co phan tu)
        B[i].next = -1;  // Khong lien ket voi phan tu nao
    }
}

// Them phan tu vao bang bam
void add(HashTable B[], int x) {
    int index = x % M; // Tinh chi so bam
    if (B[index].key == 0) {
        B[index].key = x; // Neu vi tri trong, luu gia tri vao
    } else {
        // Neu vi tri da co phan tu, tim vi tri trong gan cuoi
        int j = M - 1; // Bat dau tim kiem tu cuoi bang
        while (B[j].key != 0) {
            j--;
        }
        B[j].key = x; // Luu gia tri vao vi tri trong

        // Cap nhat lien ket "next" cua vi tri bam ban dau
        int i = index;
        while (B[i].next != -1) {
            i = B[i].next; // Tim den vi tri cuoi cung trong chuoi lien ket
        }
        B[i].next = j; // Lien ket vi tri cuoi voi vi tri moi
    }
}

// Tim kiem phan tu trong bang bam
int search(HashTable B[], int x) {
    int index = x % M; // Tinh chi so bam
    while (index != -1) {
        if (B[index].key == x) return 1; // Neu tim thay
        index = B[index].next;           // Di chuyen den vi tri lien ket tiep theo
    }
    return -1; // Khong tim thay
}

// Hien thi bang bam
void display(HashTable B[]) {
    printf("Chi so\tGia tri\tLien ket\n");
    for (int i = 0; i < M; i++) {
        printf("%d\t%d\t%d\n", i, B[i].key, B[i].next);
    }
}

int main() {
    HashTable hashTable[M];
    init(hashTable);

    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &x);
        add(hashTable, x); // Them gia tri vao bang bam
    }

    // Hien thi bang bam
    printf("Bang bam sau khi them cac phan tu:\n");
    display(hashTable);

    // Tim kiem mot phan tu
    int searchKey;
    printf("Nhap phan tu can tim: ");
    scanf("%d", &searchKey);
    if (search(hashTable, searchKey) == 1) {
        printf("Tim thay phan tu %d trong bang bam.\n", searchKey);
    } else {
        printf("Khong tim thay phan tu %d trong bang bam.\n", searchKey);
    }

    return 0;
}

