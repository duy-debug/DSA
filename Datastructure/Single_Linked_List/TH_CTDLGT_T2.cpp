#include <stdio.h>
#include <stdlib.h>

struct nut{
	int gtri;
	struct nut *tiep;
};
typedef struct nut *node;

node NewNode(int x){
	node p = new nut();
	p->gtri = x;
	p->tiep = NULL;
}
node TaoDS(node &a, int n){
	node p, q = a;
	int x, dem = 0;
	while(dem < n){
		printf("Nhap gia tri nut: ");
		scanf("%d",&x);
		p = NewNode(x);
		if(a == NULL)
			a = p;
		else
			q->tiep = p;
		q = p;
		dem++;
	}
}
void InDS(node a){
	if(a == NULL)
		return;
	else
		printf("%d ",a->gtri);
	InDS(a->tiep);
}
node InsertFirst(node &a){
	int x;
	printf("Nhap gia tri chen: ");
	scanf("%d",&x);
	node p = NewNode(x);
	if(a == NULL)
		a = p;
	else{
		p->tiep = a;
		a = p;
	}		
}
node InsertLast(node &a, int n){
	int x;
	printf("Nhap gia tri chen: ");
	scanf("%d",&x);
	node p = NewNode(x);
	node q = a;
	if(a == NULL)
		a = p;
	while(q->tiep != NULL)
		q = q->tiep;
	q->tiep = p;
}
node InsertMiddle(node &a){
	int x, pos;
	printf("Nhap gia tri chen: ");
	scanf("%d",&x);
	printf("Nhap vi tri chen: ");
	scanf("%d",&pos);
	node p = a;
	int dem = 1;
	while(dem < pos - 1 && p->tiep != NULL){
		p = p->tiep;
		dem++;
	}
	node q = NewNode(x);
	q->tiep = p->tiep;
	p->tiep = q;
}
node DeleteFirst(node &a){
	a = a->tiep;
}
node DeleteLast(node &a){
	node p = a;
	while(p->tiep->tiep != NULL)
		p = p->tiep;
	p->tiep = NULL;
}
node DeleteMiddle(node &a){
	int pos;
	printf("Nhap vi tri can xoa: ");
	scanf("%d",&pos);
	node p = a;
	int dem = 1;
	while(dem < pos - 1 && p->tiep != NULL){
		p = p->tiep;
		dem++;
	}
	node z = p->tiep;
	p->tiep = p->tiep->tiep;
	delete z;		
}
void timMin(node a){
	node p = a;
	float min = p->gtri;
	while(p->tiep != NULL){
		if(p->gtri < min && p->gtri >= 0)
			min = p->gtri;
		p = p->tiep;
	}
	if(min < 0){
		printf("Error!\n");
	}
	else
		printf("%.2f\n",min);
}
void Bai_2(node a){
	float max = 0;
	node p = a;
	if(p->gtri < 0)
		max = p->gtri;
	else{
		while(p->gtri > 0)
			p = p->tiep;
		max = p->gtri;
	}
	while(p->tiep != NULL){
		if(p->gtri > max && p->gtri < 0)
			max = p->gtri;
		p = p->tiep;
	}
	printf("%.2f\n",max);
}
int Bai_5(node a){
	if(a->gtri % 2 != 0)
		return a->gtri;
	else
		return Bai_5(a->tiep);
}
int Bai_6(node a){
	int tam;
	while(a->tiep != NULL){
		if(a->gtri % 2 == 0)
			tam = a->gtri;
		a = a->tiep;
	}
	return tam;
}

int main(){
	node a = NULL;
	int n;
	printf("Nhap so luong nut: ");
	scanf("%d",&n);
	TaoDS(a,n);
	DeleteLast(a);
	InDS(a);
}
