#include<iostream>
using namespace std;

class singlyLinkedList;
class Node{
    int data;
    Node* next;
public:
    Node(){
        data = 0;
        next = NULL;
    }
    Node(int data){
        this->data = data;
        next = NULL;
    }
    friend class singlyLinkedList;
};

class singlyLinkedList{
    Node* head;
public:
    singlyLinkedList(){
        head = NULL;
    }

    void insert(int value);
    void search(int value);
    void remove(int value);
    void display();
};

void singlyLinkedList :: insert(int value){
    int ch;
    Node* temp;
    Node* pnew;
    pnew = new Node(value);

    if(head == NULL){
        head = pnew;
        cout<<"Head Created : "<<head->data<<endl;
    }
    else{
        cout<<"Select Insert Position ->"<<endl
            <<"1) Head    2) Middle    3) End"<<endl;
        cout<<"Enter Choice : ";
        cin>>ch;
        switch(ch){
            case 1:
                pnew->next = head;
                head = pnew;
                break;
            case 2:
                int num;
                temp = head;
                cout<<"Enter Value to Insert After : ";
                cin>>num;
                while(temp->data != num){
                    temp = temp->next;
                }
                pnew->next = temp->next;
                temp->next = pnew;
                break;
            case 3:
                temp = head;
                while(temp->next != NULL){
                temp = temp->next;
                }
                temp->next = pnew;
                break;
            default:
                cout<<"\nInvalid Choice!"<<endl;
                break;
        }
        cout<<"Node Inserted!"<<endl;        
    }
}

void singlyLinkedList :: search(int value){
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

void singlyLinkedList :: remove(int value){
    Node* temp = head;
    Node* prev = head;
    if(head->data == value){
        head = head->next;
        temp->next = NULL;
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
        else{
            while(prev->next != temp){
                prev = prev->next;
            }
            prev->next = temp->next;
            temp->next = NULL;
            cout<<"\nNode Deleted!"<<endl;
        }
    }
}

void singlyLinkedList :: display(){
    Node* temp = head;
    cout<<"\nSingly Linked List ->"<<endl;
    while(temp != NULL){
        cout<<temp->data<<" -> ";
        temp = temp->next;
    }
}

int main()
{
    int n;

    singlyLinkedList s1;
    for(int i=0; i<5; i++){
        cout<<"\nEnter No. : ";
        cin>>n;
        s1.insert(n);
    }

    cout<<"\nEnter value to search : ";
    cin>>n;
    s1.remove(n);

    s1.display();

    cout<<"\nEnter value to search : ";
    cin>>n;
    s1.remove(n);
    s1.display();
    
    return 0;
}