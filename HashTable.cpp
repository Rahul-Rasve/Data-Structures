#include<iostream>
using namespace std;

class hashTable;
class hashNode{
    int key,value;
public:
    hashNode(int key, int value){
        this->key = key;
        this->value = value;
    }
    friend class hashTable;
}
class hashTable{
    int hash[10];
public:
    hashTable(){
        for(int i=0; i<10; i++){
            hash[i] = NULL;
        }
    }
    int hashFunction();
    void insert(int value);
    int search(int value);
};

int hashTable :: hashFunction(int key){
    return key % 10;
}

void hashTable :: insert(int key,int value){
    int address = hashFunction(key);
    hash[address] = value;
}

int hashTable :: search(int key){
    int address = hashFunction(key);
    while(hash[address] != NULL){
        address = hashFunction[address + 1];
    }
    return hash[address];
}

int main()
{
    
    return 0;
}