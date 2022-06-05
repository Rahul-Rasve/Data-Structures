#include<iostream>
#include<string>
using namespace std;

#define SIZE 10

class Student;

class Node{
    int roll;
    string name;
    Node* next;
public:
    Node(){
        roll = 0;
        name = "";
        next = NULL;
    }
    Node(int roll, string name){
        this->roll = roll;
        this->name = name;
        next = NULL;
    }
    friend class Student;
};

class Student{
    Node* hashTable[SIZE];
public:
    Student(){
        for(int i=0; i<SIZE; i++){
            hashTable[i] = 0;
        }
    }

    int hashFunction(int key);
    void insert(int roll, string name);
    void search(int roll);
    void remove(int roll);
    void displayDatabase();
};

int Student :: hashFunction(int key){
    return key%SIZE;
}

void Student :: insert(int roll, string name){
    int loc = hashFunction(roll);
    Node* temp;
    Node* pnew;
    pnew = new Node(roll, name);

    if(hashTable[loc] == NULL){
        hashTable[loc] = pnew;
    }
    else{
        temp = hashTable[loc];
        //compulsoriy check the temp next only, or it will check any randome memory location
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = pnew;
    }
    cout<<"Node Inserted!"<<endl;
}

void Student :: search(int roll){
    Node* temp;
    int loc = hashFunction(roll);
    if(hashTable[loc]->roll == roll){
        cout<<"\nStudent Found ->"<<endl;
        cout<<"Roll Number : "<<hashTable[loc]->roll<<endl;
        cout<<"Name : "<<hashTable[loc]->name<<endl;
    }
    else{
        temp = hashTable[loc];
        while(temp->next != NULL){
            if(temp->roll == roll){
                cout<<"\nStudent Found ->"<<endl;
                cout<<"Roll Number : "<<temp->roll<<endl;
                cout<<"Name : "<<temp->name<<endl;
                break;
            }
            temp = temp->next;
        }
    }
}

void Student :: remove(int roll){
    Node* temp;
    Node* prev; //previous pointer
    int loc = hashFunction(roll);
    if(hashTable[loc]->roll == roll){
        temp = hashTable[loc];
        hashTable[loc] = hashTable[loc]->next;
        temp->next = NULL;
    }
    else{
        temp = hashTable[loc]->next;
        prev = hashTable[loc];
        while(true){
            if(temp->roll == roll){
                while(prev->next == temp){
                    prev = prev->next;
                }
                prev->next = temp->next;
                temp->next = NULL;
                break;
            }
            temp = temp->next;
        }
    }
}

void Student :: displayDatabase(){
    Node* temp;
    cout<<"\nStudent Database =>"<<endl;
    for(int i=0; i<SIZE; i++){
        temp = hashTable[i];
        cout<<i<<" -> ";
        while(temp != NULL){
            cout<<"[ "<<temp->roll<<" , "<<temp->name<<" ] - ";
            temp = temp->next;
        }
        cout<<endl;
    }
}

int main()
{
    Student s;

    s.insert(11, "Prerana");
    s.insert(21, "Rahul");
    s.insert(31, "Rutuja");
    s.insert(12, "Chetan");
    s.insert(22, "Sonal");
    s.insert(32, "Pranjal");

    s.displayDatabase();

    s.remove(22);

    s.displayDatabase();
    
    return 0;
}