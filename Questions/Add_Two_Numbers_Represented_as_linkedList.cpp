#include<iostream>
#include<vector>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* solve(Node* num1, Node* num2, int len1, int len2){
    vector<int> hash;
    Node* temp1 = num1;
    Node* temp2 = num2;
    while(len1>len2){
        hash.push_back(num1->data);
        temp1=temp1->next;
        len1--;
    }
    while(temp2!=NULL){
        int sum = temp1->data+temp2->data;
        hash.push_back(sum);
        temp1=temp1->next;
        temp2=temp2->next;
    }
    int carry = 0;
    for (int i = len1; i>=0; i--){
        int sum = hash[i]+carry;
        hash[i] = sum%10;
        carry = sum/10;
    }
    temp1 = num1;
    for (int x : hash){
        temp1->data = x;
        temp1 = temp1->next;
    }
    if (carry!=0){
        Node* newNode = new Node(carry);
        newNode->next = num1;
        num1 = newNode;
    }
    
    return num1;
}

Node* addTwoLists(Node* num1, Node* num2) {
    // code here
    int len1 = 0;
    int len2 = 0;
    Node* temp1 = num1;
    Node* temp2 = num2;
    while(temp1!=NULL){
        temp1 = temp1->next;
        len1++;
    }
    while(temp2!=NULL){
        temp2 = temp2->next;
        len2++;
    }
    if (len1>=len2){
        return solve(num1, num2, len1, len2);
    }
    else {
        return solve(num2, num1, len2, len1);
    }
    return NULL;
}

int main(){
// 
}