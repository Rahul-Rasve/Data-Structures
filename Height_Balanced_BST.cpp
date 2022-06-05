#include<iostream>
using namespace std;

class AVL;
class Node{
    int data;
    Node* left;
    Node* right;
public:
    Node(){
        left = NULL;
        right = NULL;
        data = 0;
    }
    Node(int value){
        data = value;
        left = NULL;
        right = NULL;
    }

    friend class AVL;
};

class AVL{
    Node* root;
public:
    AVL(){
        root = NULL;
    }

    Node* leftRotate(Node* A);
    Node* rightRotate(Node* A);
    int height(Node* root);
    int balanceFactor(Node* root);
    Node* insert(int value, Node* root);
    void addElement(int value); //jockey finction of insert
    Node* remove(int value, Node* root);
    void deleteElement(int value); //jockey finction of remove
    void update(int value, Node* root);
    void changeElement(int value);  //jockey finction of update
    void inorderTraversal(Node* root);
    void display();  //jockey function of inOrderTraversal
};

Node* AVL :: leftRotate(Node* A){
    Node* B = A -> right;
    A->right = B -> left;
    B->left = A;
    return B;
}

Node* AVL :: rightRotate(Node* A){
    Node* B = A->left;
    A->left = B->right;
    B->right = A;
    return B;
}

int AVL :: height(Node* root){
    int hl=0,hr=0;
    if(root == NULL){
        return 0;
    }
    else if(root->left == NULL && root->right == NULL){
        return 1;
    }
    else{
        hl = height(root->left);
        hr = height(root->right);
        if(hl>hr){
            return hl+1;
        }
        else{
            return hr+1;
        }
    }
}

int AVL :: balanceFactor(Node* root){
    int hl = height(root->left);
    int hr = height(root->right);
    int bf = hl-hr;
    return bf;
}

Node* AVL :: insert(int value, Node* root){
    int bf;
    if (root == NULL){
        root = new Node(value);
        return root;
    }
    else if(root->data > value){
        root->left = insert(value, root->left);
        bf = balanceFactor(root);
        if(bf == 2){
            if(balanceFactor(root->left) == 1){  //LL condition
                root = rightRotate(root);
            }
            else{  //LR condition
                root->left = leftRotate(root->left);
                root = rightRotate(root);
            }
        }
        return root;
    }
    else if(root->data < value){
        root->right = insert(value, root->right);
        bf = balanceFactor(root);
        if(bf == -2){
            if(balanceFactor(root->right) == -1){ //RR condition
                root = leftRotate(root);
            }
            else{  //RL condition
                root->right = rightRotate(root->right);
                root = leftRotate(root);
            }
        }
        return root;
    }
}

void AVL :: addElement(int value){
    root = insert(value, root);
}

Node* AVL :: remove(int value, Node* root){
    Node* temp;
    int bf;
    if(root == NULL){
        return NULL;
    }
    else if(value < root->data){
        root->left = remove(value, root->left);
        bf = balanceFactor(root);
        if(bf == 2){
            if(balanceFactor(root->left) >= 0){  //LL condition
                root = rightRotate(root);
            }
            else{  //LR condition
                root->left = leftRotate(root->left);
                root = rightRotate(root);
            }
        }
    }
    else if(value > root->data){
        root->right = remove(value, root->right);
        bf = balanceFactor(root);
        if(bf == -2){
            if(balanceFactor(root->right) <= 0){ //RR condition
                root = leftRotate(root);
            }
            else{  //RL condition
                root->right = rightRotate(root->right);
                root = leftRotate(root);
            }
        }
    }
    else{  //element found
        if(root->right != NULL){
            temp = root->right; //find in-order successor
            while (temp->left != NULL){
                temp = temp->left;
            }
            //swap the in-order successor value with root
            root->data = temp->data;
            temp->right = remove(temp->data, root->right);
            if(balanceFactor(root) == 2){
                if(balanceFactor(root->left) >= 0){
                    root = rightRotate(root);
                }
                else{
                    root->left = leftRotate(root->left);
                    root = rightRotate(root);
                }
            }
        }
        else{
            return root->left;
        }
    }
    return root;
}

void AVL :: deleteElement(int value){
    root = remove(value, root);
    cout<<"Tree Values After Deletion => "<<endl;
    inorderTraversal(root);
}

void AVL :: update(int value, Node* root){
    int updatedvalue;
    if(root == NULL){
        cout<<"Value Not Found!"<<endl; 
    }
    else if(root->data > value){
        update(value, root->left);
    }
    else if(root->data < value){
        update(value, root->right);
    }
    else{ //value found
        cout<<"Enter Updated Value : ";
        cin>>updatedvalue;
        root->data = updatedvalue;
        cout<<"Tree Values After Updation => "<<endl;
        display();
    }
}

void AVL :: changeElement(int value){
    update(value, root);
}

void AVL :: inorderTraversal(Node* root){
    if(root != NULL){
        inorderTraversal(root->left);
        cout<<root->data<<" -> ";
        inorderTraversal(root->right);
    }
    else{
        return;
    }
}

void AVL :: display(){
    inorderTraversal(root);
}

int main()
{
    AVL obj;

    int choice = 0;
    int element;

    obj.addElement(1);
    obj.addElement(2);
    obj.addElement(3);
    obj.addElement(4);
    obj.addElement(8);
    obj.addElement(7);
    obj.addElement(6);
    obj.addElement(5);
    obj.addElement(11);
    obj.addElement(10);
    obj.addElement(12);

    cout<<"\nAVL Tree Created with Some Elements!"<<endl;

    while(true){
        cout<<"\n>>>>>>>>>>>AVL<<<<<<<<<<<"<<endl
            <<"1) Insert Word"<<endl
            <<"2) Update Word"<<endl
            <<"3) Delete Word"<<endl
            <<"4) Display Dictionary"<<endl
            <<"5) Exit"<<endl;
        cout<<"Enter Choice : ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter Word to Insert : ";
                cin>>element;
                obj.addElement(element);
                break;
            case 2:
                cout<<"Enter Word to Update : ";
                cin>>element;
                cout<<"Enter Updated Meaning : ";
                cin>>element;
                break;
            case 3:
                cout<<"Enter Word to Delete : ";
                cin>>element;
                obj.deleteElement(element);
                break;
            case 4:
                obj.display();
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