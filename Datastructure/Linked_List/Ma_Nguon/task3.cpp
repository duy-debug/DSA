//3.Tao danh sach lien ket don so thuc. Tinh tong so duong.
#include <stdio.h>
#include <stdlib.h>
struct node{
    float data;
    struct node *next;
};
typedef struct node node;
node *makeNode(float x){
    node *newNode=(node*)malloc(sizeof(node));
    newNode->data=x;
    newNode->next=NULL;
    return newNode;
}
void Duyet(node*head){
    while(head!=NULL){
        printf("%.2f->", head->data);
        head=head->next;
    }
    printf("NULL");
}
void pushBack(node **head, float x){
    node *newNode=makeNode(x);
    node *temp=(*head);
    if(*head==NULL){
        (*head)=newNode;
    }
    else{
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
    }
}
float Sum(node*head){
	float s=0;
	while(head!=NULL){
		if(head->data>0){
			s+=head->data;
		}
		head=head->next;
	}
	return s;
}
int main(){
    node *head=NULL;
    int n;
    printf("Nhap n phan tu:");
    scanf("%d", &n);
    float a[n];
    for(int i=0; i<n; i++){
        printf("Nhap phan tu thu %d: ", i+1);
        scanf("%f", &a[i]);
    }
    for(int i=0; i<n; i++){
        pushBack(&head,a[i]);
    }
    Duyet(head);
    printf("\nTong cac so duong: %.2f", Sum(head));
}
