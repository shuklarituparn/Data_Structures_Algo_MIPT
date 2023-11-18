//Topological sort in C++

#include <iostream>
#include <list>
#include <stack>

class Graph{

private:

    int NumberOfVertices_;
    std::list<int>* adjList_;  //pointer as we want to make new list and store the data in the
    //also that is the pointer to the array containing the

    bool *Visited_;
    std::stack<int> Stack;

public:

    explicit Graph(int NumberOfVertices);
    void addEdge(int source, int destination);
    void TopologicalSort(); //vertex, the visited array, stack
    void DFS(int vertex);
    ~Graph();
};

Graph::Graph(int NumberOfVertices){
    this->NumberOfVertices_ = NumberOfVertices;  //asssigning the number of vertices
    adjList_ = new std::list<int> [NumberOfVertices_];  //creating the new array of list
    Visited_= new bool [NumberOfVertices_];

}

void Graph::addEdge(int source, int destination) {
    adjList_[source].push_back(destination);
}

void Graph::DFS(int vertex) {
    Visited_[vertex]=true;  //mar the current node as visited

    //Now the classical DFS

    std::list<int>::iterator it;

    for (it = adjList_[vertex].begin();  it!=adjList_[vertex].end() ; ++it) {
        if(!Visited_[*it]){
            DFS(*it);
        }
    }
    Stack.push(vertex);  //pushing the vertex in the stack

}

void Graph::TopologicalSort() {
    for (int i = 0; i < NumberOfVertices_; ++i) {
        if (!Visited_[i]){
            DFS(i);
        }
    }

    while(!Stack.empty()){
        std::cout<<Stack.top()<<" ";
        Stack.pop();

    }


}
Graph::~Graph(){
    delete [] Visited_;
    delete [] adjList_;
}

int main(){
    Graph graph(6);
    graph.addEdge(5,2);
    graph.addEdge(5,0);
    graph.addEdge(4,0);
    graph.addEdge(4,1);
    graph.addEdge(2,3);
    graph.addEdge(3,1);
    graph.TopologicalSort();
}

