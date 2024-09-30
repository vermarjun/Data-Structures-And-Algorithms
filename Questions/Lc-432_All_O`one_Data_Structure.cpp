#include <iostream>
#include <string.h>
#include <unordered_map>
// Bhai this question took me 8 attemps and 2 hours lol. NOT BECAUSE IT HAS SOMETHING TRICKY, BUT BECAUSE IT HAS SO SO SO MANY EDGE CASES, WHICH IS HARD TO THINK ALL AT ONCE
// This question does not have anything new for you to learn but is actually a good question
using namespace std;

// CREATING A DOUBLY LINKEDLIST
class Node
{
public:
    int count;
    string key;
    Node *prev = NULL;
    Node *next = NULL;
    Node(int count, string key)
    {
        this->count = count;
        this->key = key;
    }
};

class AllOne
{
public:
    Node *head = NULL;
    Node *tail = NULL;
    unordered_map<string, int> hash;
    AllOne()
    {
    }

    void inc(string key)
    {
        if (hash.count(key) && hash[key] > 0)
        {
            // THIS KEY ALREADY EXISTS
            Node *temp = head;
            while (temp != NULL && temp->key != key)
            {
                // Iterating over the linkedlist to find the node which has same key
                temp = temp->next;
            }
            temp->count = (temp->count) + 1; // Increment the count of that node
            if (temp == head) return; // If the node was already present at head, means had maximum count, no need for normalization, even after increment it would be on correct place so just return
            if (temp == tail) {
                // This is special case which needs to be handeled explicitly
                // is case me tail ko current tail ke previous pe laga de
                if (temp->prev != NULL) {
                    tail = temp->prev;
                }
            }
            // NORMALISATION : find the new position of node after increment/decrement 
            Node *temp2 = temp->prev;
            while (temp2 != NULL && temp2->count <= temp->count)
            {
                temp2 = temp2->prev;
            }
            // Remove the node which is to be shifted 
            if (temp->prev != NULL)
            {
                temp->prev->next = temp->next;
            }
            if (temp->next != NULL)
            {
                temp->next->prev = temp->prev;
            }
            temp->prev = NULL;
            temp->next = NULL;
            // ADD THIS NODE AT IT'S APPROPRIATE POSITION
            if (temp2 == NULL)
            {
                temp->next = head;
                temp->prev = NULL;
                head->prev = temp;
            }
            else
            {
                temp->next = temp2->next;
                if (temp2->next != NULL)
                {
                    temp2->next->prev = temp;
                }
                temp2->next = temp;
                temp->prev = temp2;
            }
            // Check if head is at it's current position or not
            // Edge case: when someother node is incremented and it becomes, you gotta make it the new head
            while (head->prev != NULL)
            {
                head = head->prev;
            }
            // Tail wale element ke case me tail ke prev ko tail bana diya tha
            //  Now there is a possibility ki tail is not changed and even after increment new position of that node is same as tail only
            // in that case make that node as tail
            while (tail->next != NULL)
            {
                tail = tail->next;
            }
        }
        else
        {
            // IT DOES NOT EXIST
            hash[key]++;
            Node *newNode = new Node(1, key);
            if (head == NULL)
            {
                // This is first Node to be inserted
                head = newNode;
                tail = newNode;
            }
            else
            {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
        }
    }

    void dec(string key)
    {
        // IN question it is already conformed that dec will be called only when the element already exists so no need to check
        // THIS KEY ALREADY EXISTS
        hash[key]--; // Reducing this so that i can see while inc after counting that if it actually exists or not
        Node *temp = head;
        while (temp != NULL && temp->key!=key) {
            temp = temp->next;
        }
        // decrement
        temp->count = (temp->count) - 1;
        if (temp->count <= 0)
        {   
            // ALL CASES OF DELETING ELEMENTS IN LINKED LIST 
            if (head == tail)
            {
                // ONly single node in linked list
                head = NULL;
                tail = NULL;
            }
            else if (temp == head)
            {
                Node *temp2 = head;
                head = temp2->next;
                head->prev = NULL;
                temp2->next = NULL;
            }
            else if (temp == tail)
            {
                Node *temp2 = tail;
                tail = temp2->prev;
                tail->next = NULL;
                temp2->prev = NULL;
            }
            else
            {
                Node *p = temp->prev;
                Node *n = temp->next;
                p->next = n;
                n->prev = p;
                temp->next = NULL;
                temp->prev = NULL;
            }
            return;
        }
        if (temp == tail)
            return;
        if (temp == head)
        {
            head = temp->next;
        }
        Node *temp2 = temp->next;
        while (temp2 != NULL && temp2->count >= temp->count)
        {
            temp2 = temp2->next;
        }
        if (temp->prev != NULL)
        {
            temp->prev->next = temp->next;
        }
        if (temp->next != NULL)
        {
            temp->next->prev = temp->prev;
        }
        if (temp2 == NULL)
        {
            // tail is also smaller than temp
            tail->next = temp;
            temp->prev = tail;
            temp->next = NULL;
            ;
            tail = temp;
        }
        else
        {
            temp->next = temp2;
            temp->prev = temp2->prev;
            if (temp2->prev != NULL)
            {
                temp2->prev->next = temp;
            }
            temp2->prev = temp;
        }
        while (head->prev != NULL)
        {
            head = head->prev;
        }
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
    }

    string getMaxKey()
    {
        if (head != NULL)
        {
            return head->key;
        }
        return "";
    }

    string getMinKey()
    {
        if (tail != NULL)
        {
            return tail->key;
        }
        return "";
    }
};
int main()
{
    
}