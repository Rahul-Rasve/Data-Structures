#include<iostream>
using namespace std;

class doublyLinkedList;
class Node{
    int data;
    Node* prev;
    Node* next;
public:
    Node(){
        data = 0;
        prev = next = NULL;
    }
    Node(int data){
        this->data = data;
        prev = next = NULL;
    }
    friend class doublyLinkedList;
};

class doublyLinkedList{
    Node* head;
public:
    doublyLinkedList(){
        head = NULL;
    }

    void insert(int value);
    void search(int value);
    void remove(int value);
    void display();
};

void doublyLinkedList :: insert(int value){
    int ch,num;
    Node* temp = head;
    Node* pnew;
    pnew = new Node(value);
    if(head == NULL){
        head = pnew;
        cout<<"Head Created  : "<<head->data;
    }
    else{
        cout<<"Select Insert Position ->"<<endl
            <<"1) Head    2) Middle    3) End"<<endl;
        cout<<"Enter Choice : ";
        cin>>ch;
        switch(ch){
            case 1:
                pnew->next = head;
                head->prev = pnew;
                head = pnew;
                break;
            case 2:
                cout<<"Enter Value to Insert After : ";
                cin>>num;
                while(temp->data != num){
                    temp = temp->next;
                }
                pnew->next = temp->next;
                temp->next->prev = pnew;
                temp->next = pnew;
                pnew->prev = temp;
                break;
            case 3:
                while(temp->next != NULL){
                    temp = temp->next;
                }
                temp->next = pnew;
                pnew->prev = temp;
                break;
            default:
                cout<<"\nInvalid Choice!"<<endl;
                break;
        }
        cout<<"Value Inserted!"<<endl;
    }
}

void doublyLinkedList :: search(int value){
    Node* temp = head;
    bool found = false;
    while(temp != NULL){
        if(temp->data == value){
            found = true;
            cout<<"\nValue Found : "<<temp->data<<endl;
            break;
        }
        temp = temp->next;
    }
    if(!found){
        cout<<"\nValue Not Found!"<<endl;
    }
}

void doublyLinkedList :: remove(int value){
    Node* temp = head;
    Node* predecessor = NULL;
    if(head->data == value){                //head node
        temp = head->next;
        head->next = NULL;
        temp->prev = NULL;
        head = temp;
        cout<<"\nNode Deleted!"<<endl;
    }
    else{
        while(temp != NULL){
            if(temp->data == value){
                break;
            }
            temp = temp->next;
        }
        if(temp == NULL){
            cout<<"\nValue Not Found!"<<endl;
        }
        else if(temp->next == NULL){        //last node
            predecessor = temp->prev;
            predecessor->next = NULL;
            temp->prev = NULL;
            cout<<"\nNode Deleted!"<<endl;
        }
        else{                               //middle node
            predecessor = temp->prev;
            predecessor->next = temp->next;
            temp->next->prev = predecessor;
            temp->next = NULL;
            temp->prev = NULL;
            cout<<"\nNode Deleted!"<<endl;
        }
    }
}

void doublyLinkedList :: display(){
    Node* temp = head;
    cout<<"\nDoubly Linked List -> "<<endl;
    while(temp != NULL){
        cout<<temp->data<<" <=> ";
        temp = temp->next;
    }
}

int main()
{
    doublyLinkedList d1;
    int n, dch=0, choice=0;

    for(int i=0; i<5; i++){
        cout<<"\nEnter No. : ";
        cin>>n;
        d1.insert(n);
    }

    while(true){
        cout<<"\n1) Insert"<<endl
            <<"2) Search"<<endl
            <<"3) Delete"<<endl
            <<"4) Display"<<endl
            <<"5) Exit"<<endl;
        cout<<"Enter Choice : ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter Number : ";
                cin>>n;
                d1.insert(n);
                break;
            case 2:
                cout<<"Enter Number to Search : ";
                cin>>n;
                d1.search(n);
                break;
            case 3:
                cout<<"Enter Number to Delete : ";
                cin>>n;
                d1.remove(n);
                break;
            case 4:
                cout<<"\nHow to Display ->"<<endl
                    <<"\t1) From Head"<<endl
                    <<"\t2) From Tail"<<endl;
                cout<<"Enter Choice : ";
                cin>>dch;
                if(dch == 1){
                    d1.displayFromHead();
                }
                else if(dch == 2){
                    d1.displayFromTail();
                }
                else{
                    cout<<"\nInvalid Choice!"<<endl;
                }
                break;
            case 5:
                exit(0);
                break;
            default:
                cout<<"\nInvalid Choice!"<<endl;
                break;
        }
    }

    return 0;
}
