#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;

#define size 100

class Heap{
    int array[size];
    int heapSize;
    int child, parent;
public:
    Heap(){
        heapSize = 0;
    }

    void heapUp(int child);
    void heapDown(int parent);
    void insert(int value);
    void remove(); //since it will always remove the smallest element
    void displayArray();
};

void Heap :: heapUp(int child){
    int temp;
    parent = (child-1)/2;
    while(array[child] < array[parent] && child > 0){ //check child index
        /*SWAP*/
        temp = array[parent];
        array[parent] = array[child];
        array[child] = temp;

        child = parent;  //give parent's addredd to child
        parent = (child-1)/2;
    }
}

void Heap :: heapDown(int parent){
    int smallestChild, leftChild, rightChild;
    int temp;
    leftChild = 2*parent + 1;
    rightChild = 2*parent + 2;
    if(leftChild > rightChild){
        smallestChild = rightChild;
    }
    else{
        smallestChild = leftChild;
    }
    while(array[parent] > array[rightChild] || array[parent] > array[leftChild] && leftChild < heapSize){
        // Swap
        temp = array[parent];
        array[parent] = array[smallestChild];
        array[smallestChild] = temp;

        parent = smallestChild;
        leftChild = 2*parent + 1;
        rightChild = 2*parent + 2;
    }
}

void Heap :: insert(int value){
    child = heapSize;
    heapSize += 1;
    array[child] = value;
    heapUp(child);
}

void Heap :: remove(){
    parent = 0;
    if(parent != heapSize-1){
        array[parent] = array[heapSize-1];
    }
    heapSize -= 1;  //delete the last node
    heapDown(parent); //move it to proper pos.
    cout<<"Heap Contents After Deleting Root ->"<<endl;
    displayArray();
}

void Heap :: displayArray(){
    cout<<"\n";
    int i=0;
    if(heapSize == 0){
        cout<<"Heap is Empty!"<<endl;
    }
    else{
        while(i < heapSize){
            cout<<array[i]<<" ";
            i++;
        }
    }
}

int main()
{
    Heap h1;
        
    int choice, value;
    do{
        cout<<"\n***HEAP STRUCTURE***"<<endl;
        cout<<"\n1) Insert Element"
            <<"\n2) Remove Element"
            <<"\n3) Display Heap"
            <<"\n4) Exit"<<endl;
        cout<<"Enter Choice : ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"\nEnter Value : ";
                cin>>value;
                h1.insert(value);
                cout<<"Value Inserted Succesfully!"<<endl;
                break;
            case 2:
                h1.remove();
                cout<<"\nDeletion Successfull!"<<endl;
                cout<<"Heap Contents After Deletion -> ";
                h1.displayArray();
                break;
            case 3:
                cout<<"\nHeap Contents -> ";
                h1.displayArray();
                break;
            case 4:
                exit(0);
                break;
            default:
                cout<<"\nInvalid Choice!"<<endl;
                break;   
        }
    }while(choice != 4);

    return 0;
}

// Dry Run
    // h1.insert(10);
    // h1.insert(20);
    // h1.insert(15);
    // h1.insert(12);
    // h1.insert(25);
    // h1.insert(30);
    // h1.insert(14);
    // h1.insert(2);
    // h1.insert(5);
    // h1.insert(4);
    // h1.displayArray();