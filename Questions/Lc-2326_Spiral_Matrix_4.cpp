#include <iostream>
#include<vector>
using namespace std;
 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
vector<vector<int>> spiralMatrix(int m, int n, ListNode *head)
{
    int rowEnd = m - 1;
    int rowStart = 0;
    int colStart = 0;
    int colEnd = n - 1;
    ListNode *temp = head;
    vector<vector<int>> matrix(m, vector<int>(n, -1));
    while (temp != NULL)
    {
        for (int i = colStart; i <= colEnd && temp != NULL; i++)
        {
            matrix[rowStart][i] = temp->val;
            temp = temp->next;
        }
        rowStart++;
        for (int i = rowStart; i <= rowEnd && temp != NULL; i++)
        {
            matrix[i][colEnd] = temp->val;
            temp = temp->next;
        }
        colEnd--;
        for (int i = colEnd; i >= colStart && temp != NULL; i--)
        {
            matrix[rowEnd][i] = temp->val;
            temp = temp->next;
        }
        rowEnd--;
        for (int i = rowEnd; i >= rowStart && temp != NULL; i--)
        {
            matrix[i][colStart] = temp->val;
            temp = temp->next;
        }
        colStart++;
    }
    return matrix;
}

int main()
{   ListNode* head = NULL;
    vector<int> ll = {3,0,2,6,8,1,7,9,4,2,5,5,0};
    ListNode* temp = NULL;
    for (int x : ll){
        ListNode* nextNode = new ListNode(x);
        if (head == NULL){
            head = nextNode;
            temp = head;
        }
        else {
            temp->next = nextNode;
            temp = temp->next;
        }
    }
    vector<vector<int>> matrix = spiralMatrix(3,5,head);
    for (vector<int> x : matrix){
        for (int y : x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
}