 #include <stdio.h>
#include <stdlib.h>
// Dinh nghia cau truc cua mot node trong danh sach lien ket
struct node{
    int data;
    struct node *next;
};
typedef struct node node;
// Ham tao mot nut moi
node *makeNode(int x){
    node *newNode=(node*)malloc(sizeof(node));
    newNode->data=x;
    newNode->next=NULL;
    return newNode;
}
// Ham day phan tu vao ngan xep
void push(node **top, int x){
    node *newNode=makeNode(x);
    newNode->next=*top;
    *top=newNode;
}
// Ham lay phan tu ra khoi ngan xep
void pop(node **top){
    if(*top!=NULL){
        node *tmp=*top;
        (*top)=tmp->next; // Cap nhat top la phan tu tiep theo
        free(tmp); // Giai phong bo nho cua phan tu vua lay ra
    }
}
int Top(node *top){
    if(top!=NULL){
        return top->data;
    }
}
int size(node *top){
    int cnt=0;
    while(top!=NULL){
        cnt++;
        top=top->next;
    }
    return cnt;
}
int main(){
    node *st=NULL;
    while(1){
        printf("----------------------\n");
        printf("1.push\n");
        printf("2.pop\n");
        printf("3.top\n");
        printf("4.size\n");
        printf("0.thoat\n");
        printf("----------------------\n");
        int luachon;
        scanf("%d", &luachon);
        if(luachon==1){
            int x;
            printf("Nhap phan tu: ");
            scanf("%d", &x);
            push(&st,x);
        }
        else if(luachon==2){
            pop(&st);
        }
        else if(luachon==3){
            printf("%d", Top(st));
        }
        else if(luachon==4){
            printf("So luong: %d", size(st));
        }
        else{
            break;
        }
    }
}
