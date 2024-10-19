#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    // 2 con tro
    struct node *left; // luu dia chi cua node ben trai
    struct node *right; // luu dia chi cua node ben phai
};
typedef struct node node;
node* makeNode(int x){
    node *newNode=(node*)malloc(sizeof(node));
    newNode->data=x;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
node *insert(node *root, int x){
    if(root==NULL){
        // Neu cay rong tao mot nut moi va tra ve nut do
        root=makeNode(x);
    }
    else if(x<root->data){
        // Neu gia tri nho hon gia tri cua nut goc, chen vao cay con ben trai
        root->left=insert(root->left,x);
    }
    else{
        // Neu gia tri lon hon hoac bang, chen vao cay con ben phai
        root->right=insert(root->right,x);
    }
    return root;
}
// Duyet cay theo thu tu truoc: NLR
void NLR(node *root){
    if(root==NULL) return;
    printf("%4d", root->data);
    NLR(root->left);
    NLR(root->right);
}
// Duyet cay theo thu tu giua: LNR
void LNR(node *root){
    if(root==NULL) return;
    LNR(root->left);
    printf("%4d", root->data);
    LNR(root->right);
}
// Duyet cay theo thu tu sau: LRN
void LRN(node *root){
    if(root==NULL) return;
    LRN(root->left);
    LRN(root->right);
    printf("%4d", root->data);
}
// Dem so nut trong cay su dung de quy
int Count_Node(node *root){
    if(root==NULL) return 0;
    return 1+Count_Node(root->left)+Count_Node(root->right);
}
// Tim gia tri x co trong cay hay khong
node *Search(node *root, int x){
    if(root==NULL || root->data == x) return root;
    if(x<root->data) return Search(root->left,x);
    return Search(root->right,x);
}
// Tim gia tri nho nhat
node *find_Min(node *root){
    while(root->left!=NULL) root=root->left;
    return root;
}
// Tim gia tri lon nhat
node *find_Max(node *root){
    while(root->right!=NULL) root=root->right;
    return root;
}
int main(){
    // TAO THU CONG
    // node *root=makeNode(1);
    // root->left=makeNode(2);
    // root->right=makeNode(3);
    // root->left->left=makeNode(4);
    // root->left->right=makeNode(5);
    // root->right->left=makeNode(6);
    // root->right->right=makeNode(7);
    node *root=NULL;
    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &a[i]);
    }
    // Chen cac phan tu vao cay
    for (int i = 0; i < n; i++) {
        root = insert(root, a[i]);
    }
    // In ra cay theo cach duyet khac nhau
    printf("\nDuyet cay theo thu tu truoc (NLR): ");
    NLR(root);
    printf("\nDuyet cay theo thu tu giua (LNR): ");
    LNR(root);
    printf("\nDuyet cay theo thu tu sau (LRN): ");
    LRN(root);
    printf("\nTong so nut trong cay: %d", Count_Node(root));
    int x;
    printf("\nNhap gia tri can tim: ");
    scanf("%d", &x);
    if(Search(root,x)!=NULL)
    printf("\nGia tri %d duoc tim thay trong cay", x);
    else printf("\nGia tri %d khong tim thay trong cay", x);
    node *minNode=find_Min(root); // tra ve dia chi
    node *maxNode=find_Max(root); // tra ve dia chi
    if(minNode!=NULL)
    printf("\nGia tri nho nhat trong cay: %d", minNode->data);
    else printf("\nCay rong!");
    if(maxNode!=NULL)
    printf("\nGia tri lon nhat trong cay: %d", maxNode->data);
    else printf("\nCay rong!");
	return 0;
}
