//7.Tao danh sach lien ket don ky tu. Dem so ky tu A.
#include <stdio.h>
#include <stdlib.h>
struct node{
	char data;
	struct node *next;
};
typedef struct node node;
node *makeNode(char x){
	node *newNode=(node*)malloc(sizeof(node));
	newNode->data=x;
	newNode->next=NULL;
	return newNode;
}
void Duyet(node *head){
	while(head!=NULL){
		printf("%c->", head->data);
		head=head->next;
	}
	printf("NULL");
}
void pushBack(node **head, char x){
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
void Count_Charater(node*head){
	int cnt=0;
	while(head!=NULL){
		if(head->data=='A'){
			cnt++;
		}
		head=head->next;
	}
	printf("\nSo ki tu 'A': %d", cnt);
}
int main(){
	node *head=NULL;
	int n;
	printf("Nhap n ki tu: ");
	scanf("%d", &n);
	getchar();
	char a[n];
	for(int i=0; i<n; i++){
		printf("Nhap ki tu thu %d: ", i+1);
		scanf("%c", &a[i]);
		getchar();
	}
	for(int i=0; i<n; i++){
		pushBack(&head,a[i]);
	}
	Duyet(head);
	Count_Charater(head);
}
