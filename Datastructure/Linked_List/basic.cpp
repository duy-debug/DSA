#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next; // luu dia chi cua node tiep theo
};
typedef struct node node;
node* makeNode(int x){
    // cap phat dong 1 node
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}
void duyet(node *head){ //duyet danh sach lien ket
    while(head != NULL){
        printf("%2d", head->data);
        head = head->next;   // dich head sang node ben phai
    }
}
int Count(node *head){ // dem so luong node trong danh sach lien ket
    int cnt=0;
    while(head != NULL){
        cnt++;
        head = head->next; // dich head sang node tiep theo
    }
    return cnt;
}
void pushFront(node **head, int x){ // them phan tu vao dau node
    node* newNode = makeNode(x);
    newNode->next = (*head); // toan tu giai tham chieu
    (*head) = newNode;
}
void pushBack(node **head, int x){ // them phan tu vao cuoi node
    node* newNode = makeNode(x);
    if(*head == NULL){
        *head = newNode; 
        return;
    }
    node* tem = (*head);
    while(tem->next != NULL){
        tem = tem->next;
    }
    tem->next = newNode;
}
void isnert(node **head, int k, int x){ // chen vao vi tri k trong danh sach lien ket
    int n = Count(*head);
    if(k < 1 || k > n + 1) return;
    else if(k == 1){
        pushFront(head, x);
    }
    else{
        node* temp= (*head);
        for(int i=1; i < k - 1; i++){
            temp = temp->next;
        }
        node* newNode = makeNode(x);
        // B1: phan next cua new Node luu dia chi cua node thu k 
        newNode->next = temp->next;
        // B2: Phan next cua node thu k -1 luu dia chi cua node moi
        temp->next = newNode;
    }
}
int main(){
    node *head = NULL;
    int i=1;
    while(i!=0){
        printf("-----------------------------------\n");
        printf("1. Them vao dau: \n");
        printf("2. Them vao cuoi: \n");
        printf("3. Duyet DSLK: \n");
        printf("4. Chen vao giua: \n");
        printf("0. Thoat !\n");
        printf("-----------------------------------\n");
        printf("Nhap lua chon: ");
        int lc; scanf("%d", &lc);
        if(lc == 1) {
            printf("Nhap gia tri can them: \n");
            int x; scanf("%d", &x);
            pushFront(&head, x);
        }
        if(lc == 2) {
            printf("Nhap gia tri can them: \n");
            int x; scanf("%d", &x);
            pushBack(&head, x);
        }
        if(lc == 3) {
            duyet(head);
        }
        if(lc == 4){
            printf("Nhap vi tri chen: ");
            int k; scanf("%d", &k);
            printf("Nhap vi tri can chen: ");
            int x; scanf("%d", &x);
            isnert(&head,k,x);
        }
        if(lc == 0) {
            break;
        }
    }
}