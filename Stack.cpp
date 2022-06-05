#include<iostream>
using namespace std;

#define n 100

class stack
{
    int* arr;
    int top;
public:
    stack()  //constructor
    {
        arr = new int[n];
        top = -1;
    }
    
    void push(int x)  //push function to add element on the top
    {
        if(top==n-1)
        {
            cout<<"\nStack Overflow !";
            return;
        }
        top++;
        arr[top] = x;
    }

    void pop()  //pop function to remove topmost element
    {
        if(top==-1)
        {
            cout<<"\nStack Empty"<<endl;
            return;
        }
        top--;
    }

    int Top()  //top function to return the element on top
    {
        if(top==-1)
        {
            cout<<"\nNo Elements in the Stack"<<endl;
            return -1;
        }
        return arr[top];
    }

    bool empty()  //empty function to check for empty stack
    {
        return top==-1;
    }
};

int main()
{
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout<<"Top = "<<s.Top();
    //s.pop();
    //s.pop();
    //s.pop();
    //s.pop();
    s.empty();
     
    return 0;
}