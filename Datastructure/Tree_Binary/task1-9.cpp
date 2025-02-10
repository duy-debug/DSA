#include <stdio.h>
#include <stdlib.h>
// Dinh nghia cau truc cho cay nhi phan
struct node{
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node node;
// Tao mot nut moi
node *makeNode(int x){
    node *newNode=(node*)malloc(sizeof(node));
    newNode->data=x;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
// Them mot phan tu vao cay nhi phan tim kiem
node *insert(node *root, int x){
    if(root==NULL){
        root=makeNode(x);
    }
    else if(x<root->data){
        root->left=insert(root->left,x);
    }
    else{
        root->right=insert(root->right,x);
    }
    return root;
}
// 2. Duyet cay theo thu tu giua
void LNR(node *root){
    if(root==NULL) return;
    LNR(root->left);
    printf("%3d", root->data);
    LNR(root->right);
}
// 3. Dem so nut chi co 1 nhanh cua mot cay nhi phan
int Count_Node(node *root){
    if(root==NULL) return 0;
    int cnt=0;
    if((root->left==NULL && root->right!=NULL) || (root->left!=NULL && root->right==NULL))
      cnt=1;
    return cnt+Count_Node(root->left)+Count_Node(root->right);
}
// 4. Tinh chieu cao cua cay nhi phan
int Tree_Height(node *root){
    if(root==NULL) return 0;
    int left_Height=Tree_Height(root->left);
    int right_Height=Tree_Height(root->right);
    return (left_Height>right_Height ? left_Height:right_Height) + 1;
}
// 5. Tim 1 nut co gia tri bat ky cua mot cay nhi phan. Tinh muc va so nut la cua nut vua tim duoc
node *find_Node(node *root, int value){
    if(root==NULL || root->data==value) return root;
    if(value<root->data) return find_Node(root->left,value);
    return find_Node(root->right,value);
}
int find_level(node *root, int value, int level){
    if(find_Node(root,value)==NULL) // khong tim thay nut
        return 0;
    if(root->data==value)  // tim thay nut trong cay con trai
        return level;
    // goi de quy tim cay con trai
    int leftLevel=find_level(root->left,value,level+1);
    if(leftLevel!=0) // Neu tim that cay con trai, tra ve muc cua no
        return leftLevel;
    // goi de quy tim cay con phai
    return find_level(root->right,value,level+1); 
}
// 6. Xoa 1 nut co gia tri bat ky cua mot cay nhi phan, sau do to chuc lai cay
// Tim gia tri lon nhat cay con trai
node *find_Max(node *root){
  while(root->right!=NULL){
    root=root->right;
  }
  return root;  
}
node *deleteNode(node *root, int key){
    if(root==NULL) return root;
    // tim nut can xoa
    if(key<root->data){
        root->left=deleteNode(root->left,key);
    }
    else if(key>root->data){
        root->right=deleteNode(root->right,key);
    }
    else{
        // da tim thay nut can xoa
        if(root->left==NULL){
            // truong hop nut chi co mot cay con ben trai hoac khong co con ben trai
            node *temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
          node *temp=root->left;
          free(root);
          return temp;
      }
      // Truong hop nut co 2 con: tim gia tri lon nhat cay con trai
      node *temp=find_Max(root->left);
      // Thay the gia tri cua nut can xoa bang gia tri cua nut nho nhat
      root->data=temp->data;
      // Xoa nut lon nhat cay con trai
      root->left=deleteNode(root->left,temp->data);
    }
    return root;
}
// 7. Tinh tong gia tri cua cac nut nho hon mot gia tri xac dinh truoc
int Sum(node *root, int value){
    if(root==NULL) return 0;
    int sum=0;
    if(root->data<value)
    sum+=root->data;
    return sum+Sum(root->left,value)+Sum(root->right,value);
}
// 8. Dem so luong cac nut co gia tri chan
int Count_Numbers(node *root){
  if(root==NULL) 
    return 0;   
  int cnt=0;
  if(root->data%2==0)
    cnt=1;
  return cnt+Count_Numbers(root->left)+Count_Numbers(root->right);
}
// 9. Xac dinh cay co bang khong
int Tree_AVL(node *root){
    if(root==NULL) return 1; // cay rong la can bang
    // Tinh chieu cao cua cay con trai va phai
    int left_height=Tree_Height(root->left);
    int right_height=Tree_Height(root->right);
    if(abs(left_height-right_height)<=1 && Tree_AVL(root->left) && Tree_AVL(root->right)){
        return 1;
    }
    return 0;
}
int main(){
    node *root=NULL;
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);
    int a[n];
    for(int i=0; i<n; i++){
        printf("Nhap phan tu thu %d: ", i+1);
        scanf("%d", &a[i]);
    }
    for(int i=0; i<n; i++){
        root=insert(root,a[i]);
    }
    printf("Cay nhi phan sau khi chen: \n");
    LNR(root);
    printf("\nSo nut chi co mot nhanh: %d\n", Count_Node(root));
    printf("Chieu cao cua cay nhi phan: %d\n", Tree_Height(root));
    int x;
    printf("Nhap vao gia tri x can tim: ");
    scanf("%d", &x);
    if(find_Node(root,x)!=NULL) 
    printf("Gia tri %d duoc tim thay trong cay\n", x);  
    else printf("Gia tri %d khong tim thay\n", x);
    printf("Muc cua nut vua tim duoc la: %d\n", find_level(root,x,0));
    node *maxNode = find_Max(root);
    if (maxNode != NULL) {
        printf("Gia tri lon nhat: %d\n", maxNode->data);
    } else {
        printf("Cay rong!\n");
    }
    int y;
    printf("Nhap nut can xoa: ");
    scanf("%d", &y);
    root=deleteNode(root,y);
    printf("Cay sau khi xoa: \n");
    LNR(root);
    int k;
    printf("\nNhap gia tri cho truoc: ");
    scanf("%d", &k);
    printf("Tong gia tri cua cac nut nho hon gia tri cho truoc: %d", Sum(root,k));
    printf("\nSo luong nut co gia tri chan: %d\n", Count_Numbers(root));
    if(Tree_AVL(root))
    printf("Cay da can bang!\n");
    else printf("Cay khong can bang!\n");
}
