#include <stdio.h>

struct nut{
	int gtri;
	struct nut *tiep;
};
typedef struct nut* node;

//cap phat dong mot node moi 
node newNode(int n){
	node tam = new nut();
	tam->gtri = n;
	tam->tiep = NULL;
	return tam;
}

//kiem tra rong
bool empty(node a){
	return a == NULL;
}

//dem so luong ptu trong ds (cach 1)
int count(node a){
	int dem = 0;
	while(a != NULL){
		++dem;
		a = a->tiep;
	}
	return dem;
}

/*dem so luong ptu trong ds (cach 2)
int count(node a){
	if(a == NULL)
		return 0;
	else
		return 1 + count(a->tiep);
}
*/

//them 1 ptu vao dau ds
void insertFirst(node &a,int x){
	node tam = newNode(x);
	if(a == NULL){
		a = tam;
	}
	else{
		tam->tiep = a;
		a = tam;
	}
}

//them 1 ptu vao cuoi ds
void insertLast(node &a,int x){
	node tam = newNode(x);
	if(a == NULL){
		a = tam;
	}
	else{
		node p = a;
		while(p->tiep != NULL){
			p = p->tiep;
		}
		p->tiep = tam;
	}
}

//them 1 ptu vao giua
void insertMiddle(node &a,int x,int pos){
	int n = count(a);
	if(pos <=0 || pos > n + 1){
		printf("Error: invalid position");
	}
	if(pos == 1){
		insertFirst(a,x); 
		return; 
	}
	else if(pos == n + 1){
		insertLast(a,n);
		return;
	}
	node p = a;
	for(int i = 1; i < pos - 1; i++){
		p = p->tiep;
	}
	node tam = newNode(x);
	tam->tiep = p->tiep;
	p->tiep = tam;
}

//xoa ptu dau
void deleteFirst(node &a){
	if(a == NULL)
		return;
	a = a->tiep;
}

//xoa ptu cuoi 
void deleteLast(node &a){
	if(a == NULL)
		return;
	node p = a;
	int n = count(a);
	for(int i = 1 ; i < n - 1; i++) {
		p = p->tiep;
	}
	p->tiep = NULL;
}

//xoa ptu giua
void deleteMiddle(node &a, int pos){
	int n = count(a);
	if(pos <= 0 || pos > n)
		return;
	node truoc = NULL, sau = a;
	for(int i = 1; i < pos; i++){
		truoc = sau;
		sau = sau->tiep;
	}
	if(truoc == NULL){
		a = a->tiep;
	}
	else{
		truoc->tiep = sau->tiep;
	}
}
void print(node a){
	while(a != NULL){
		printf("%d ",a->gtri);
		a = a->tiep;
	}
}

void SortT(node &a){
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

int main(){
	node a = NULL;
	int x, pos;
	int phim=1;
	while(phim!=9){
		printf("\n");
		printf("-------------------MENU----------------------\n");
		printf("1. Dem so phan tu trong danh sach\n");
		printf("2. Chen phan tu dau\n");
		printf("3. Chen phan tu cuoi\n");
		printf("4. Chen phan tu giua\n");
		printf("5. Xoa phan tu dau\n");
		printf("6. Xoa phan tu cuoi\n");
		printf("7. Xoa phan tu giua\n");
		printf("8. In danh sach\n");
		printf("9. Ket thuc chuong trinh\n");
		printf("---------------------------------------------\n");
		printf("An phim tu 1 den 9 de thuc hien cac lenh: ");	
		scanf("%d",&phim);
		printf("\n");
		
		switch(phim){
			case 1: 
				printf("%d",count(a));
				break;
			case 2: 
				printf("Nhap gia tri can chen: ");
				scanf("%d",&x);
				insertFirst(a,x);
				break;
			case 3: 
				printf("Nhap gia tri can chen: ");
				scanf("%d",&x);
				insertLast(a,x);
				break;
			case 4: 
				printf("Nhap gia tri can chen: ");
				scanf("%d",&x);
				printf("Nhap vi tri can chen: ");
				scanf("%d",&pos);
				insertMiddle(a,x,pos);
				break;
			case 5: 
				deleteFirst(a);
				break;
			case 6:
				deleteLast(a);
				break;
			case 7:
				printf("Nhap vi tri can xoa: ");
				scanf("%d",&pos);
				deleteMiddle(a,pos);
				break;
			case 8:
				print(a);
				break;
		}	
	}	
	return 0;
}
