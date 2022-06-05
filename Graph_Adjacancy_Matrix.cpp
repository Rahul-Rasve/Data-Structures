#include<iostream>
#include<queue>
using namespace std;

#define N 10

class Graph{
    int nVertex, nEdges;
    int adjMatrix[N][N];
public:
    Graph(){ //NULL Graph
        nVertex = 0;
        nEdges = 0;
        //make each index 0
        for(int i=0; i<nVertex; i++){
            for(int j=0; j<nVertex; j++){
                adjMatrix[i][j] = 0;
            }
        }
    }
    //graph with given vertices
    Graph(int nv){
        nVertex = nv;
        nEdges = 0;
        for(int i=0; i<nVertex; i++){
            for(int j=0; j<nVertex; j++){
                adjMatrix[i][j] = 0;
            }
        }
    }
    
    void createGraph(int nv, int ne); //graph with given verties and edges
    void breadthFirstTraversal(int startVertex);
    void search(int s, int d);
    void display();
};

void Graph :: createGraph(int nv, int ne){
    nVertex = nv;
    nEdges = ne;

    for(int i=0; i<nVertex; i++){
        for(int j=0; j<nVertex; j++){
            adjMatrix[i][j] = 0;
        }
    }
    //enter edges
    for(int i=0; i<nEdges; i++){
        int s,d,w;
        cout<<"Enter (S,D) : ";
        cin>>s>>d;
        cout<<"Enter Time : ";
        cin>>w;
        adjMatrix[s][d] = w;
        adjMatrix[d][s] = w;
    }
    cout<<endl;
}

void Graph :: breadthFirstTraversal(int startVertex){
    queue <int> q;
    int popVertex;
    int visited[nVertex];
    for(int i=0; i<nVertex; i++){
        visited[i] = 0;
    }
    q.push(startVertex);
    visited[startVertex] = 1;
    while(!q.empty()){
        popVertex = q.front();
        q.pop();
        cout<<popVertex<<" -> ";
        for(int i=0; i<nVertex; i++){
            //check the adjacent vertices
            if(adjMatrix[popVertex][i] > 0 && visited[i] == 0){
                q.push(i);
                visited[popVertex] = 1;
            }
        }
    }
}

void Graph :: search(int s, int d){
    if(adjMatrix[s][d] > 0){
        cout<<"There is a Edge Between "<<s<<" & "<<d<<endl;
        cout<<"Weight = "<<adjMatrix[s][d]<<endl;
    }
    else{
        cout<<"There is No Edge Between "<<s<<" & "<<d<<endl;
    }
}

void Graph :: display(){
    if(nVertex > 0){
        for(int i=0; i<nVertex; i++){
            for(int j=0; j<nVertex; j++){
                cout<<adjMatrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else{
        cout<<"NULL Graph!"<<endl;
    }
}

int main()
{
    Graph g1;

    g1.createGraph(3,3);
    cout<<endl;
    g1.display();
    cout<<endl;
    g1.breadthFirstTraversal(0);
    
    return 0;
}