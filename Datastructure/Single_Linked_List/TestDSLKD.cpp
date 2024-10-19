#include <iostream>
using namespace std;

struct nut{
	int gtri;
	struct nut *tiep;
};
typedef struct nut* node;

node newNode(int n){
	node tam = new nut();
	tam->gtri = n;
	tam->tiep = NULL;
	return tam;
}

void nhapDS(node &a){
	node p, q;
	int x;
	do{
		cout<<"Nhap mot so nguyen, nhap 0 de dung: ";
		cin>>x;
		if(x!=0){
			p = newNode(x);
			if(a == NULL)
				a = p;
			else
				q->tiep = p;
			q = p;
		}
	}while(x!=0);
}

void Sort(node &a){
	node p, q;
	int tam;
	p = a;
	while(p->tiep != NULL){
		q = p->tiep;
		while(q != NULL){
			if(p->gtri < q->gtri){
				tam = p->gtri;
				p->gtri = q->gtri;
				q->gtri = tam;
			}
			q = q->tiep;
		}
		p = p->tiep;
	}
}

void insertMiddleNode(node &a, int x, int pos){
	node tam = newNode(x);
	node p = a;
	for(int i = 1; i < pos-1; i++){
		p = p->tiep;
	}
	tam->tiep = p->tiep;
	p->tiep = tam;
}

void print(node a){
	while(a != NULL){
		printf("%d ",a->gtri);
		a = a->tiep;
	}
}

int count(node a){
	if(a == NULL)
		return 0;
	else
		return 1 + count(a->tiep);
}

int main(){
	node a = NULL;
	nhapDS(a);
	Sort(a);
	cout<<count(a)<<endl;
	print(a);
}

