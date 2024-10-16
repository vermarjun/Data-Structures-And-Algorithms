#include<iostream>
#include"1_BinaryTree.h"
#include<vector>

using namespace std;

// CONDITION : AT ANY POINT, Node ki value right subtree ki sabhi values se smaller and left subtree ki sabhi values se bigger

Node* insertIntoBST(Node* root, int data){
    if (root == NULL){
        Node* newNode = new Node(data);
        return root;
    }
    if (root->value>data){
        root->right = insertIntoBST(root->right, data);
    }
    else {
        root->left = insertIntoBST(root->left, data);
    }
    return root;
}

void createBST(Node* &root){
    int data = 0;
    cout<<"Enter Data: "<<endl;
    cin>>data;
    while (data!=-1){
        insertIntoBST(root, data);
        cout<<"Enter Data: "<<endl; 
        cin>>data;
    }
}

void DeleteNodeFromBST(Node* root, int target){
    // TO DO:
}

void morrisTraversal(Node* root, int target){
    // TO DO
}

void createBstFromINORDER(vector<int> inorderTraversal){
    // TO DO
}

int main(){
    // IMPORTANT POINTS:
    // 1)INORDER TRAVERSAL in bst is SORTED!!!
    // 2))
    Node* root = NULL;
    createBST(root);
}