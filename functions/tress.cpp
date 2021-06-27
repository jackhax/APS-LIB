#include<iostream>

using namespace std;

struct node{
    int data;
    node *left;
    node *right;
};

// template<typename T>
// T max(T a,T b){
//     return a>b?a:b;
// }

node *newNode(int data){
    node *n = new node;
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

node *insert(int data,node *n){
    if(n == NULL)
        n = newNode(data);
    if(data<n->data)
        n->left = insert(data,n->left);
    if(data>n->data)
        n->right = insert(data,n->right);
    return n;
}

void inorder(node *r){
    if(r == NULL)
        return;
    inorder(r->left);
    cout<<r->data<<' ';
    inorder(r->right);
}

void preorder(node *r){
    if(r == NULL)
        return;
    cout<<r->data<<' ';
    preorder(r->left);
    preorder(r->right);
}

void postorder(node *r){
    if(r == NULL)
        return;
    preorder(r->left);
    preorder(r->right);
    cout<<r->data<<' ';
}

int max_depth(node *root){
    if(root == NULL)
        return 0;
    
    int ldepth = max_depth(root->left);
    int rdepth = max_depth(root->right);

    return max(ldepth,rdepth) +1;
}

void mirror_tree(node *root){
    if(root == NULL)
        return;
    mirror_tree(root->left);
    mirror_tree(root->right);
    node *temp;
    temp = root->left;
    root->left = root->right;
    root->right = temp; 
}

void k_distance(node *root,int k){
    //Print nodes at k distance from root
    if(root == NULL)
        return ;
    if(k==0)
        cout<<root->data<<" ";
    k_distance(root->left,k-1);
    k_distance(root->right,k-1);
}

int main(){
    node *root = NULL;
    int keys[] = {5,1,6,2,4,9,3,8,7};
    for(int i=0;i<9;i++){
        root = insert(keys[i],root);
    }
    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    cout<<max_depth(root);
    cout<<"\nMirroring tree";
    mirror_tree(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    mirror_tree(root);
    k_distance(root,2);
    return 0;
}
