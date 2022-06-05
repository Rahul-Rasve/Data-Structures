#include<iostream>
#include<queue>
using namespace std;

#define nVertex 10

class Graph;

class edgeNode{
    int data;
    edgeNode* right;
public:
    edgeNode(){
        data = 0;
        right = NULL;
    }
    edgeNode(int data){
        this->data = data;
        right = NULL;
    }
    friend class Graph;
};

class vertexNode{
    int data;
    vertexNode* down;
    edgeNode* right;
public: 
    vertexNode(){
        data = 0;
        down = NULL;
        right = NULL;
    }
    vertexNode(int data){
        this->data = data;
        down = NULL;
        right = NULL;
    }
    friend class Graph;
};

class Graph{
    vertexNode* head;
public:
    Graph(){
        head = NULL;
    }
    void insertVertex(int value);
    void insertEdge(int valueS, int valueD);
    void displayGraph();
    void breadthFirstTraversal(int startVertex);
};

void Graph :: insertVertex(int value){
    vertexNode* temp;
    vertexNode* pnew;
    pnew = new vertexNode(value);
    temp = head;
    if(head == NULL){
        head = pnew;
    }
    else{
        while(temp->down != NULL){
            temp = temp->down;
        }
        temp->down = pnew;
    }
    cout<<"Vertex "<<pnew->data<<" Created Successfully!"<<endl;
}

void Graph :: insertEdge(int valueS, int valueD){
    vertexNode* tempV;
    edgeNode* tempE;
    edgeNode* pnew;
    pnew = new edgeNode(valueD);
    tempV = head;
    if(head != NULL){
        while(tempV != NULL){
            if(tempV->data == valueS){
                break;
            }
            tempV = tempV->down;
        }
        if(tempV == NULL){
            cout<<"Vertex Not Found!"<<endl;
        }
        else{
            tempE = tempV->right;
            if(tempE != NULL){ //check for first edge of vertex
                while(tempE->right != NULL){
                    tempE = tempE->right;
                }
                tempE->right = pnew;
            }
            else{
                tempV->right = pnew; //the first edge node
            }
        }
        cout<<"Edge Created Between "<<valueS<<" and "<<valueD<<endl;
    }
    else{
        cout<<"Vertex Linked List Not Created!"<<endl;
    }
}

void Graph :: displayGraph(){
    vertexNode* tempV;
    edgeNode* tempE;
    tempV = head;
    while(tempV != NULL){
        tempE = tempV->right;
        cout<<tempV->data<<" -> ";
        while(tempE != NULL){
            cout<<tempE->data<<" - ";
            tempE = tempE->right;
        }
        cout<<endl;
        tempV = tempV->down;
    }
    cout<<endl;
}

void Graph :: breadthFirstTraversal(int startVertex){
    int popVertex = 0;
    queue<int> q;
    vertexNode* tempV;
    edgeNode* tempE = NULL;
    int visited[nVertex];
    for (int i = 0; i<nVertex; i++){
        visited[i] = 0;  //make every node non-visited
    }
    //traversal
    q.push(startVertex);
    visited[startVertex] = 1;
    while (!q.empty()){
        popVertex = q.front();
        q.pop();
        cout<<popVertex<<"  ";
        //since SLL, make tempV point to head so that complete LL is traversed each time
        tempV = head;
        while(tempV != NULL){
            if(tempV->data == popVertex){
                break;
            }
            tempV = tempV->down;
        }
        if(tempV != NULL){
            tempE = tempV->right;
            while(tempE->right != NULL){
                if(visited[tempE->data] == 0){
                    q.push(tempE->data);
                    visited[tempE->data] = 1;
                }
                else{
                    tempE = tempE->right;
                }
            }
        }
    }
    cout<<endl;
}

int main()
{
    Graph v1;

    int numberOfVertex,numberOfEdge,vertex,edge;
    cout<<"Enter no of vertices : ";
    cin>>numberOfVertex;
    cout<<"Enter no of edges : ";
    cin>>numberOfEdge;

    for(int i=0; i<numberOfVertex; i++){
        cout<<"Enter Vertex : ";
        cin>>vertex;
        v1.insertVertex(vertex);
    }
    for(int j=0; j<numberOfEdge; j++){
        cout<<"Enter Source and Destination Vertex (S,D) : ";
        cin>>vertex>>edge;
        v1.insertEdge(vertex,edge);
        v1.insertEdge(edge,vertex);
    }

    v1.displayGraph();

    int sVertex;
    cout<<"Enter Start Vertex for BFS Traversal : ";
    cin>>sVertex;
    v1.breadthFirstTraversal(sVertex);
    
    return 0;
}

        /*Dry Run*/   
    // v1.insertVertex(0);
    // v1.insertVertex(1);
    // v1.insertVertex(2);
    // v1.insertVertex(3);
    // v1.insertVertex(4);
    // v1.insertVertex(5);
    // v1.insertEdge(0,1);
    // v1.insertEdge(0,2);
    // v1.insertEdge(0,3);
    // v1.insertEdge(1,2);
    // v1.insertEdge(1,4);
    // v1.insertEdge(2,3);
    // v1.insertEdge(2,4);
    // v1.insertEdge(2,5);
    // v1.insertEdge(3,5);
    // v1.insertEdge(4,5);