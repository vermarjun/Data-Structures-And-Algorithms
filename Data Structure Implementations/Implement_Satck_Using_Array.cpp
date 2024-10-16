#include <iostream>

using namespace std;

class CustomStack
{
public:
    int *arr;
    int size;
    int top;
    // void display(){
    //     for(int i = 0; i < size; i++){
    //         cout<<arr[i]<<" ";
    //     }
    //     cout<<endl;
    // }
    CustomStack(int maxSize)
    {
        arr = new int[maxSize];
        this->size = maxSize;
        this->top = -1;
        // display();
    }
    void push(int x)
    {
        if (top == size - 1)
        {
            cout << "overflow" << endl;
        }
        else
        {
            top++;
            arr[top] = x;
        }
        // display();
    }

    int pop()
    {
        if (top > -1)
        {
            int temp = arr[top];
            arr[top] = -1;
            top--;
            return temp;
        }
        else
        {
            cout << "underflow";
        }
        // display();
        return -1;
    }

    void increment(int k, int val)
    {
        if (k > size)
        {
            k = size;
        }
        int i = 0;
        while (i < k)
        {
            arr[i] = arr[i] + val;
            i++;
        }
        // display();
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */

int main()
{
    CustomStack* st = new CustomStack(10);
    st->push(10);
    st->push(20);
    st->pop();
    
}