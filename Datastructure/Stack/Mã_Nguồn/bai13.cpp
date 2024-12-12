#include <stdio.h>
#include <stdlib.h>

// Dinh nghia node
typedef struct Node {
    char data;
    struct Node *next;
} Node;

// Dinh nghia stack
typedef struct {
    Node *top;
} Stack;

// Khoi tao stack
void initStack(Stack *s) {
    s->top = NULL;
}

// Kiem tra stack rong
int isEmpty(Stack *s) {
    return s->top == NULL;
}

// Them phan tu vao stack
void push(Stack *s, char c) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Khong du bo nho!\n");
        exit(1);
    }
    newNode->data = c;
    newNode->next = s->top;
    s->top = newNode;
}

// Lay phan tu ra khoi stack
char pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack rong!\n");
        return '\0';
    }
    Node *temp = s->top;
    char data = temp->data;
    s->top = s->top->next;
    free(temp);
    return data;
}

// Chuyen so tu co so 10 sang co so bat ky
void convertBase(int num, int base) {
    Stack s;
    initStack(&s);

    char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    if (base < 2 || base > 36) {
        printf("Co so khong hop le! (2 <= base <= 36)\n");
        return;
    }

    // Day cac phan du vao stack
    while (num > 0) {
        int remainder = num % base;
        push(&s, digits[remainder]);
        num /= base;
    }

    // Lay cac phan tu tu stack va in ra
    printf("Ket qua chuyen doi: ");
    while (!isEmpty(&s)) {
        printf("%c", pop(&s));
    }
    printf("\n");
}

int main() {
    int num, base;

    printf("Nhap so can chuyen doi: ");
    scanf("%d", &num);

    printf("Nhap co so can chuyen doi (2-36): ");
    scanf("%d", &base);

    convertBase(num, base);

    return 0;
}

