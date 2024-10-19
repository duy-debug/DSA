//2.Tao danh sach lien ket don so thuc. Tim so am lon nhat.
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
void duyet(node*head){
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
		*head=newNode;
	}
	else{
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=newNode;
	}
}
void Soam_Max(node*head){
	float max=-99999999;
	float k=-1;
	while(head!=NULL){
		if(head->data<0 && head->data>max){
			max=head->data;
			k=0;
		}
		head=head->next;
	}
	if(k==-1) printf("\nKhong co so am!");
	else printf("\nSo am lon nhat: %.2f", max);
}
int main(){
	node *head=NULL;
	int n;
	printf("Nhap n phan tu: ");
	scanf("%d", &n);
	float a[n];
	for(int i=0; i<n; i++){
		printf("Nhap phan tu thu %d: ", i+1);
		scanf("%f", &a[i]);
	}
	for(int i=0; i<n; i++){
		pushBack(&head,a[i]);
	}
	duyet(head);
	Soam_Max(head);
}
