#include<iostream>

using namespace std;

struct node{
    int data;
    node *left;
    node *right;
};


node *insert_node(node *root,int data){
    if(root == NULL){
        root = new node();
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        return root;
    }

    if(data > root->data){
        root->right = insert_node(root->right,data);
    }else if(data < root->data){
        root->left = insert_node(root->left,data);
    }

    return root;
}

void inorder(node *root){
    if(root == NULL)
        return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(node *root){
    if(root == NULL)
        return;
    preorder(root->left);
    preorder(root->right);
    cout<<root->data<<" ";
}

void postorder(node *root){
    if(root == NULL)
        return ;
    postorder(root->right);
    postorder(root->left);
    cout<<root->data<<" ";
}

int main(){
    node *root = NULL;
    root = insert_node(root,7);
    root = insert_node(root,3);
    root = insert_node(root,4);
    root = insert_node(root,0);
    root = insert_node(root,9);
    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postorder(root);
    return 0;
}
