//9.Tao danh sach lien ket don luu tru chuoi ky tu co do dai toi da la 20.Cho biet thu tu cua phan tu co chuoi ky tu ngan nhat.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node{
	char data[20];
	struct node *next;
};
typedef struct node node;
node *makeNode(char x[]){
	node *newNode=(node*)malloc(sizeof(node));
	strcpy(newNode->data,x); // sao chep chuoi vao data
	newNode->next=NULL;
	return newNode;
}
void Duyet(node *head){
	while(head!=NULL){
		printf("%s->", head->data);
		head=head->next;
	}
	printf("NULL");
}
void pushBack(node **head, char x[]){
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
void Shortest_String(node *head){
	int min=strlen(head->data);
	int cnt=0; // dem vi tri
	int min_index=1; // vi tri chuoi nho nhat
	node *temp=head;
	while(temp!=NULL){
		cnt++;
		int k=strlen(temp->data);
		if(k<min){
			min=k;
			min_index=cnt;
		}
		temp=temp->next;
	}
	printf("\nChuoi ki tu ngan nhat o vi tri: %d", min_index);
}
int main(){
	node *head=NULL;
	int n;
	printf("Nhap n so luong chuoi ki tu: ");
	scanf("%d", &n);
	getchar();
	for(int i=0; i<n; i++){
		char s[20];
		printf("Nhap chuoi thu %d: ", i+1);
		fgets(s,sizeof(s),stdin);
		s[strcspn(s, "\n")] = 0;
		pushBack(&head,s);
	}
	Duyet(head);
	Shortest_String(head);
}
