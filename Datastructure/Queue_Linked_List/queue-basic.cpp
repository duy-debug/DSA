#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
typedef struct node node;
node *makeNode(int x){
    node *newNode=(node*)malloc(sizeof(node));
    newNode->data=x;
    newNode->next=NULL;
    return newNode;
}
void push(node **queue, int x){
    node *newNode=makeNode(x);
    if(*queue==NULL){
        *queue=newNode; return;
    }
    node *tmp=*queue;
    while(tmp->next!=NULL){
        tmp=tmp->next;
    }
    tmp->next=newNode;
}
void pop(node **queue){
    if(*queue==NULL) return;
    node *tmp=*queue;
    (*queue)=(*queue)->next;
    free(tmp);
}
int size(node *queue){
  int cnt=0;
  while(queue!=NULL){
    cnt++;
    queue=queue->next;
  }
  return cnt;
}
void duyet(node *queue){
  while(queue!=NULL){
    printf("%2d", queue->data);
    queue=queue->next;
  }
}
int main(){
  node *queue=NULL;
  while(1){
        printf("----------------------\n");
        printf("1.push\n");
        printf("2.pop\n");
        printf("3.size\n");
        printf("4.duyet\n");
        printf("0.thoat\n");
        printf("----------------------\n");
        int luachon;
        scanf("%d", &luachon);
        if(luachon==1){
            int x;
            printf("Nhap phan tu: ");
            scanf("%d", &x);
            push(&queue,x);
        }
        else if(luachon==2){
            pop(&queue);
        }
        else if(luachon==3){
            printf("So luong: %d", size(queue));
        }
        else if(luachon==4){
            duyet(queue);
        }
        else{
            break;
        }
    }
}