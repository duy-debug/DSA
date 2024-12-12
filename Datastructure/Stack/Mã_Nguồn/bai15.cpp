#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Dinh nghia node cho stack
typedef struct Node {
    char *data; // S? d?ng con tr? d?n chu?i
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
void push(Stack *s, char *value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Khong du bo nho!\n");
        exit(1);
    }
    newNode->data = (char *)malloc(strlen(value) + 1); // C?p phát b? nh? cho chu?i
    strcpy(newNode->data, value); // Sao chép chu?i vào
    newNode->next = s->top;
    s->top = newNode;
}

// Lay phan tu ra khoi stack
char *pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack rong!\n");
        exit(1);
    }
    Node *temp = s->top;
    char *data = temp->data;
    s->top = s->top->next;
    free(temp);
    return data;
}

// Lay phan tu o dinh stack
char *peek(Stack *s) {
    if (isEmpty(s)) {
        return NULL;
    }
    return s->top->data;
}

// Ham kiem tra do uu tien cua toan tu
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0; // Neu khong phai toan tu
}

// Ham kiem tra ky tu co phai la toan tu khong
int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

// Chuyen bieu thuc trung to sang hau to
void infixToPostfix(char *infix, char *postfix) {
    Stack s;
    initStack(&s);

    int i = 0, j = 0;
    while (infix[i] != '\0') {
        char token = infix[i];

        if (isalnum(token)) {
            // Neu la toan hang, them vao hau to
            postfix[j++] = token;
        } else if (token == '(') {
            // Neu la dau ngoac mo, day vao stack
            push(&s, "(");
        } else if (token == ')') {
            // Neu la dau ngoac dong, lay toan tu ra cho den khi gap ngoac mo
            while (!isEmpty(&s) && strcmp(peek(&s), "(") != 0) {
                postfix[j++] = pop(&s)[0];
            }
            pop(&s); // Loai bo ngoac mo
        } else if (isOperator(token)) {
            // Neu la toan tu
            while (!isEmpty(&s) && precedence(peek(&s)[0]) >= precedence(token)) {
                postfix[j++] = pop(&s)[0];
            }
            char str[2] = {token, '\0'};
            push(&s, str);
        }
        i++;
    }

    // Day cac toan tu con lai trong stack vao hau to
    while (!isEmpty(&s)) {
        postfix[j++] = pop(&s)[0];
    }
    postfix[j] = '\0'; // Ket thuc chuoi
}

// Chuyen bieu thuc hau to sang trung to
void postfixToInfix(char *postfix, char *infix) {
    Stack s;
    initStack(&s);

    char temp[100];
    int i = 0;

    while (postfix[i] != '\0') {
        char token = postfix[i];

        if (isalnum(token)) {
            // Neu la toan hang, day vao stack
            char str[2] = {token, '\0'};
            push(&s, str);
        } else if (isOperator(token)) {
            // Neu la toan tu, lay hai toan hang tu stack
            char *op2 = pop(&s);
            char *op1 = pop(&s);

            // Tao chuoi moi theo dang trung to
            sprintf(temp, "(%s%c%s)", op1, token, op2);
            push(&s, temp);

            // Giai phong bo nho cu
            free(op1);
            free(op2);
        }
        i++;
    }

    // Ket qua cuoi cung
    strcpy(infix, pop(&s));
}

int main() {
    char infix[100], postfix[100], result[100];

    printf("Nhap bieu thuc trung to: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Bieu thuc hau to: %s\n", postfix);

    postfixToInfix(postfix, result);
    printf("Chuyen nguoc ve trung to: %s\n", result);

    return 0;
}

