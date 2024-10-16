#include<iostream>
#include"1_BinaryTree.h"
#include<queue>
using namespace std;


// RECURSIVE METHODS: 

// 1) Pre Order Traversal => NLR
void nlr(Node* head){
    if (head == NULL) return;
    // process current node
    cout<<head->value;
    // go left
    nlr(head->left);
    // go right
    nlr(head->right);
}
// 2) In Order Traversal => LNR
void lnr(Node* head){
    if (head == NULL) return;
    // go left
    nlr(head->left);
    // process current node
    cout<<head->value;
    // go right
    nlr(head->right);
}
// 3) Post Order Traversal => LRN
void lrn(Node* head){
    if (head == NULL) return;
    // go left
    nlr(head->left);
    // go right
    nlr(head->right);
    // process current node
    cout<<head->value;
}

// ALL THREE METHODS -> ITERATIVE APPROACH:



// -----Level Order Traversal-----
// USING QUEUE
void lot(Node* head){
    queue<Node*> q;
    q.push(head);
    q.push(NULL);
    while (!q.empty()){
        Node* front = q.front();
        q.pop();
        if (front == NULL){
            if (!q.empty()){
                q.push(NULL);
            }
        }
        else {
            if (front->left != NULL){
                q.push(front->left);
            }
            if (front->right != NULL){
                q.push(front->right);
            }
        }
    }
}


int main(){

}