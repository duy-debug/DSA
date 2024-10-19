//5.Tao danh sach lien ket don so nguyen. Tim so le dau tien.
#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node*next;
};
typedef struct node node;
node *makeNode(int x){
	node *newNode=(node*)malloc(sizeof(node));
	newNode->data=x;
	newNode->next=NULL;
	return newNode;
}
void Duyet(node*head){
	while(head!=NULL){
		printf("%d->", head->data);
		head=head->next;
	}
	printf("NULL");
}
void pushBack(node **head, int x){
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
void inSole(node*head){
	int k=-1;
	while(head!=NULL){
		if(head->data%2==1){
			k=head->data;
			break;
		}
		head=head->next;
	}
	if(k==-1) printf("\nKhong co so le!");
	else printf("\nSo le dau tien: %d", k);
}
int main(){
	node *head=NULL;
	int n;
	printf("Nhap n phan tu: ");
	scanf("%d", &n);
	int a[n];
	for(int i=0; i<n; i++){
		printf("Nhap phan tu thu %d: ", i+1);
		scanf("%d", &a[i]);
	}
	for(int i=0; i<n; i++){
		pushBack(&head,a[i]);
	}
	Duyet(head);
	inSole(head);
}
