#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Dinh nghia node
typedef struct Node {
    char *data;
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
void push(Stack *s, char *word) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Khong du bo nho!\n");
        exit(1);
    }
    newNode->data = strdup(word); // Sao chep chuoi
    newNode->next = s->top;
    s->top = newNode;
}

// Lay phan tu ra khoi stack
char *pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack rong!\n");
        return NULL;
    }
    Node *temp = s->top;
    char *data = temp->data;
    s->top = s->top->next;
    free(temp);
    return data;
}

// Dao nguoc cac tu trong chuoi
void reverseWords(char str[]) {
    Stack s;
    initStack(&s);

    char *token = strtok(str, " ");
    while (token != NULL) {
        push(&s, token); // Dua tung tu vao stack
        token = strtok(NULL, " ");
    }

    // Lay tu tu stack de tao chuoi dao nguoc
    int first = 1;
    while (!isEmpty(&s)) {
        if (!first) printf(" ");
        printf("%s", pop(&s));
        first = 0;
    }
    printf("\n");
}

int main() {
    char str[200];
    printf("Nhap chuoi: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; // Loai bo ky tu xuong dong

    printf("Chuoi dao nguoc cac tu: ");
    reverseWords(str);

    return 0;
}

