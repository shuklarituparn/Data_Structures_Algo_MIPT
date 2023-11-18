

#include <iostream>
#include <list>
#include<stack>
#include <vector>

class Graph{
private:
    int Vertices_;
    std::list<int> *adjList;
public:
    void DFS(int Vertices, bool visited[]);
    Graph(int Vertices);
    ~Graph();
    void AddEdges(int source, int target);
    bool isSCC();
    Graph getTranspose(); //function returning the type Graph after transpose
};

void Graph::AddEdges(int source, int target) {
    adjList[source].push_back(target);
}

Graph::Graph(int Vertices){
    this->Vertices_=Vertices;
    adjList=new std::list<int>[Vertices];  //creating an array of the list
}

Graph::~Graph() {
    delete [] adjList;
}

void Graph::DFS(int Vertices, bool *visited) {
    visited[Vertices] = true;

    std::list<int>::iterator it;  //defining an iterator
    //iterate and call over the function on it

    for (it = adjList[Vertices].begin(); it != adjList[Vertices].end(); ++it) {
        if (!visited[*it]){
            DFS(*it, visited);
        }
    }
}

Graph Graph::getTranspose() {
    Graph graph(Vertices_); //creating a graph with a vertex

    std::list<int>::iterator it; //defining an iterator

    for (int i = 0; i < Vertices_; ++i) {

        for (it = adjList[i].begin(); it !=adjList[i].end() ; ++it) { //iterating on the list of that iterator
            graph.adjList[*it].push_back(i); //pushing back the vertex in the adjList of the element in new graph
        }
    }
    return graph; //returning our new graph
}


bool Graph::isSCC() {
    bool visited[Vertices_];
    for (int i = 0; i < Vertices_; ++i) {
        visited[i]=false;

    } //making all the value as false

    //Now d


}