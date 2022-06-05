#include<iostream>
#include<stdlib.h>
using namespace std;

unsigned max(int num1, int num2){
    if(num1 >= num2){
        return num1;
    }
    else{
        return num2;
    }
}

class btSearchTree;
class Node{
    int data;
    Node* left;
    Node* right;
public:
    Node(){
        data = 0;
        left = NULL;
        right = NULL;
    }
    Node(int value){
        data = value;
        left = NULL;
        right = NULL;
    }
    friend class btSearchTree;
};

class btSearchTree{
private:
    Node* root;
public:    
    btSearchTree(){
        root = NULL;
        cout<<"Empty Search Tree Created!"<<endl;
    }
    
    void insert(int value);
    Node* searchbt(Node* root, int key);
    bool Search(int key); //jockey function
    int smallestValue();
    int largestValue();
    int height(Node* root);
    int longestPath();
    void swap(Node* root);
    void mirror();
    void inOrder(Node* root);
    void inOrderDisplay();
    Node* deleteNode(Node* root , int keyValue);
    void deletion(int keyValue); //jockey function
};

Node* btSearchTree :: deleteNode(Node* root , int keyValue){
    if(root == NULL){ //empty tree
        cout<<"\nElement Not Found!"<<endl;
        return root;
    }
    if(keyValue < root->data){ //left sub-tree
        cout<<"\nSearching value in Left Sub-Tree of : "<<root->data<<endl;
        root->left = deleteNode(root->left , keyValue);
    }
    else if(keyValue > root->data){ //right sub-tree
        cout<<"\nSearching value in Right Sub-Tree of : "<<root->data<<endl;
        root->right = deleteNode(root->right , keyValue);
    }
    else{ //value found
        if(root->right == NULL){  //single child
            return root->left;
        }
        else{ //both child
            Node* ptr; //this ptr will point to in-oder successor 
            ptr = root->right;
            while(ptr != NULL){
                ptr = ptr->left;  //find in-order successor [io-order = left root right]
            }
            root->data = ptr->data; //replace root with in-oder successor
            root->right = deleteNode(root->right , ptr->data); //delete in-order successor
        }
    }
    return root;
}

void btSearchTree :: deletion(int keyValue){
    root = deleteNode(root , keyValue);
}

void btSearchTree :: inOrder(Node* root){
    if(root != NULL){
        inOrder(root->left);
        cout<<root->data<<" - ";
        inOrder(root->right);
    }
}

void btSearchTree :: inOrderDisplay(){
    return inOrder(root);
}

void btSearchTree :: insert(int value){
    Node* pNew;
    pNew = new Node(value);
    if(root == NULL){
        root = pNew;
        cout<<"\nRoot Created = "<<root->data<<endl;
    }
    else{
        Node* temp;
        temp = root;
        do{
            if(value < temp->data){  //compare value of inserted node with root for direction decision
                if(temp->left == NULL){
                    temp->left = pNew;
                    cout<<"\nNode Inserted to left of : "<<temp->data<<endl;
                    break;
                }
                else{
                    temp = temp->left;
                }
            }
            else if(value > temp->data){
                if(temp->right == NULL){
                    temp->right = pNew;
                    cout<<"\nNode Inserted to right of : "<<temp->data<<endl;
                    break;
                }
                else{
                    temp = temp->right;
                }
                
            }
            else{
                cout<<"Duplicate value found!"<<endl;
                break;
            }
        }while(temp != NULL);
    }
}

Node* btSearchTree :: searchbt(Node* root , int key){  //recursive
    if(root == NULL){
        return NULL;
    }
    if(key < root->data){ //if key value is less than root, search on left sub tree
        return searchbt(root->left , key);
    }
    else if(key > root->data){  //if key value is greater than root, search on right sub tree
        return searchbt(root->right , key);
    }
    else{
        return root;
    }
}

bool btSearchTree :: Search(int key){
    Node* temp;
    temp = searchbt(root , key);
    if(temp == NULL){
        cout<<"\nElement not Found!"<<endl;
        return false;
    }
    else{
        cout<<"\nElement "<<key<<" Found!"<<endl;
        return true;
    }
}

int btSearchTree :: smallestValue(){
    Node* temp = root;
    while(temp->left != NULL){
        temp = temp->left;
    }
    if(temp->left == NULL){
        return temp->data;
    }
}

int btSearchTree :: largestValue(){
    Node* temp = root;
    while(temp->right != NULL){
        temp = temp->right;
    }
    if(temp->right == NULL){
        return temp->data;
    }
}

int btSearchTree :: height(Node* root){
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL && root->right == NULL){
        return 1;
    }
    else{
        int heightLeft = height(root->left);
        int heightRight = height(root->right);
        int result;
        result = 1 + max(heightLeft, heightRight);
        return result;
    }
}

int btSearchTree :: longestPath(){
    return height(root);
}

void btSearchTree :: swap(Node* root){
    Node* temp;
    if(root->left != NULL){
        swap(root->left);
    }
    if(root->right != NULL){
        swap(root->right);
    }
    temp = root->left;
    root->left = root->right;
    root->right = temp;
}

void btSearchTree :: mirror(){
    return swap(root);
}

int main()
{
    btSearchTree bst1; //class object
    
    /*DRY RUN
    //treee nodes
    bst1.insert(10);  //root
    bst1.insert(5);  //left
    bst1.insert(20);  //right
    bst1.insert(15);  //left
    bst1.insert(7);  //right
    bst1.insert(25);  //right
    bst1.insert(9);  //right
    bst1.insert(12);  //left
    bst1.insert(14);  //right

    //search element
    // bool result;
    // result = bst1.successfulSearch(21);
    // cout<<"\nIn-Order Traversal Before Deletion : "<<endl;
    // bst1.inOrderDisplay();
    // bst1.deletion(9);
    // cout<<"\nIn-Order Traversal After Deletion : "<<endl;
    // bst1.inOrderDisplay();
    */
    
    
    int choice;
    int value;
    int element;
    bool result;

    do{
        cout<<"\n\tBINARY SEARCH TREE";
        cout<<"\n1 => Insert Node \n2 => Search Element \n3 => Smallest Element \n4 => Lagest Element \n5 => Height of Tree \n6 => Mirror Tree \n7 => Delete Node \n8 => Exit";
        cout<<"\nEnter your Choice : ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"\nEnter Value to be Inserted : ";
                cin>>value;
                bst1.insert(value);
                break;
            case 2:
                cout<<"\nEnter Element to Search : ";
                cin>>element;
                result = bst1.Search(element);
                break;
            case 3:
                cout<<"\nSmallest Element : "<<bst1.smallestValue()<<endl;
                break;
            case 4:
                cout<<"\nlargest Element : "<<bst1.largestValue()<<endl;
                break;
            case 5:
                cout<<"\nHeight of Tree is : "<<bst1.longestPath()<<endl;
                break;
            case 6:
                bst1.mirror();
                break;
            case 7:
                cout<<"Enter Element to be Deleted : ";
                cin>>element;
                cout<<"\nIn-Order Traversal Before Deletion : "<<endl;
                bst1.inOrderDisplay();
                bst1.deletion(element);
                cout<<"\nIn-Order Traversal After Deletion : "<<endl;
                bst1.inOrderDisplay();
                break;
            case 8:
                exit(0);
                break;
            default:
                cout<<"\nInvalid Input!"<<endl;
                break;
        }
    }while(choice != 8);
    
    return 0;
}