#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Dinh nghia node
typedef struct Node {
    double data;
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
void push(Stack *s, double value) {
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
double pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack rong!\n");
        exit(1);
    }
    Node *temp = s->top;
    double data = temp->data;
    s->top = s->top->next;
    free(temp);
    return data;
}

// Ham tinh toan 2 so dua tren toan tu
double calculate(double op1, double op2, char op) {
    switch (op) {
        case '+': return op1 + op2;
        case '-': return op1 - op2;
        case '*': return op1 * op2;
        case '/': 
            if (op2 == 0) {
                printf("Loi: Chia cho 0!\n");
                exit(1);
            }
            return op1 / op2;
        default:
            printf("Toan tu khong hop le: %c\n", op);
            exit(1);
    }
}

// Tinh gia tri bieu thuc hau to
double evaluatePostfix(const char *expression) {
    Stack s;
    initStack(&s);

    for (int i = 0; expression[i] != '\0'; i++) {
        char token = expression[i];

        if (isspace(token)) {
            // Bo qua khoang trang
            continue;
        } else if (isdigit(token)) {
            // Neu la so, day vao stack
            double num = token - '0';
            push(&s, num);
        } else {
            // Neu la toan tu, pop hai toan hang tu stack
            double op2 = pop(&s);
            double op1 = pop(&s);
            double result = calculate(op1, op2, token);
            push(&s, result);
        }
    }

    // Ket qua cuoi cung con lai trong stack
    return pop(&s);
}

int main() {
    char expression[100];

    printf("Nhap bieu thuc hau to: ");
    fgets(expression, sizeof(expression), stdin);

    double result = evaluatePostfix(expression);

    printf("Gia tri bieu thuc: %.2f\n", result);

    return 0;
}

