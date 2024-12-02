#include <stdio.h>
#include <stdlib.h>
#define M 6 // Kich thuoc bang bam

// Dinh nghia cau truc Node cho bang bam
struct Node {
    int key;
    struct Node *next;
};

typedef struct Node Node;

// Khoi tao bang bam
void init(Node *B[]) {
    for (int i = 0; i < M; i++) {
        B[i] = NULL; // Tat ca vi tri deu NULL ban dau
    }
}

// Them phan tu vao bang bam
void add(Node *B[], int x) {
    int index = x % M; // Tinh chi so bam
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->key = x;  // Gan gia tri cho Node moi
    newNode->next = NULL;

    if (B[index] == NULL) {
        B[index] = newNode; // Neu vi tri trong, gan Node moi vao
    } else {
        Node *temp = B[index];
        while (temp->next != NULL) { // Duyet den cuoi danh sach lien ket
            temp = temp->next;
        }
        temp->next = newNode; // Them Node moi vao cuoi danh sach
    }
}

// Tim kiem trong bang bam
int search(Node *B[], int x) {
    int index = x % M; // Tinh chi so bam
    Node *temp = B[index];
    while (temp != NULL) {
        if (temp->key == x) return 1; // Neu tim thay, tra ve 1
        temp = temp->next; // Duyet den Node tiep theo
    }
    return -1; // Khong tim thay
}

// Hien thi bang bam
void display(Node *B[]) {
    for (int i = 0; i < M; i++) {
        printf("Vi tri %d: ", i);
        Node *temp = B[i];
        while (temp != NULL) {
            printf("%d -> ", temp->key); // In gia tri cua Node
            temp = temp->next;
        }
        printf("NULL\n"); // Ket thuc danh sach lien ket
    }
}

int main() {
	// ket noi truc tiep (ket noi ngoai)
    Node *hashTable[M];
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

