#include<iostream>

using namespace std;

class Node{
public:
    int value;
    Node* left = NULL;
    Node* right = NULL;
    Node(int value){
        this->value = value;
    }
};
Node* createTree(){
    int data = 0;
    cout<<"Enter Node Value: "<<endl;
    cin>>data;
    if (data == -1){
        return NULL;
    }
    Node* newNode = new Node(data);
    newNode->left = createTree();
    newNode->right = createTree();
    return newNode;
}
int main(){
    // Node* node1 = new Node(10);
    // Node* node2 = new Node(20);
    // Node* node3 = new Node(30);
    // Node* node4 = new Node(40);
    // Node* node5 = new Node(50);
    // Node* node6 = new Node(60);
    // Node* node7 = new Node(70);
    // node1->left = node2;
    // node1->right = node3;
    // node2->left = node4;
    // node2->right = node5;
    // node3->left = node6;
    // node3->right = node7;
}