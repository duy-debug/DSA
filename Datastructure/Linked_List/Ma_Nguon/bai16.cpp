#include <stdio.h>
#include <stdlib.h>

// Dinh nghia node cho stack
typedef struct Node {
    int data;
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
void push(Stack *s, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Khong du bo nho!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
}

// Lay phan tu ra khoi stack
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack rong!\n");
        exit(1);
    }
    Node *temp = s->top;
    int data = temp->data;
    s->top = s->top->next;
    free(temp);
    return data;
}

// Ham kiem tra so nguyen to
int isPrime(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

// Ham phan tich so thanh cac thua so nguyen to theo thu tu lon truoc nho
void primeFactorization(int n) {
    Stack s;
    initStack(&s);

    // Tim cac thua so nguyen to
    for (int i = 2; i <= n; i++) {
        while (n % i == 0 && isPrime(i)) {
            push(&s, i); // Day thua so nguyen to vao stack
            n /= i;
        }
    }

    // In ra thua so nguyen to theo thu tu lon truoc nho
    printf("%d = ", n); // In so ban dau
    while (!isEmpty(&s)) {
        printf("%d", pop(&s));
        if (!isEmpty(&s)) {
            printf("*");
        }
    }
    printf("\n");
}

int main() {
    int n;
    printf("Nhap so n: ");
    scanf("%d", &n);

    primeFactorization(n);

    return 0;
}

