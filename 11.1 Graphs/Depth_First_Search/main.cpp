//
// Created by rituparn on 13.11.23.
//
// DFS algorithm in C++

#include <iostream>
#include <list>

class Graph{
private:
    int NumberOfVertices_;
    std::list<int> * adjList_; //adjacent list that is a pointer holding info for list type
    bool * Visited_; //we also a bool array that stores that if the node is visited

public:
    Graph(int NumberOfVertices);
    void addNewEdge(int source, int destination);
    void DFS(int vertex);
    ~Graph();

};

Graph::Graph(int NumberOfVertices){
    this->NumberOfVertices_ = NumberOfVertices;
    adjList_ = new std::list<int> [NumberOfVertices_];
    Visited_=new bool [NumberOfVertices_];

}
void Graph::addNewEdge(int source, int destination){
        adjList_[source].push_back(destination);
}
void Graph::DFS(int vertex){ //we are given a vertex from which we are calculating the DFS of the graph
    Visited_[vertex]= true; //marking that vertex as visited
    std::cout<<vertex<<" "; //printing the current vertex

    //now taking the help of iterator to iterate over the list

    std::list<int>::iterator it;  //list iterator

    for (it=adjList_[vertex].begin();it!=adjList_[vertex].end(); it++) {   //using the iterator to loop to the adjlist
        //std::cout<<*it;
        if (!Visited_[*it]){   //using the iterator to recursively call the function if not visited
            DFS(*it);
        }
    }



}
Graph::~Graph(){
    delete [] adjList_;
    delete [] Visited_;

}

int main(){
    Graph graph1(4);
    graph1.addNewEdge(0,1);
    graph1.addNewEdge(0,2);
    graph1.addNewEdge(1,2);
    graph1.addNewEdge(2,0);
    graph1.addNewEdge(2,3);
    graph1.addNewEdge(3,3);

    graph1.DFS(2);
    return 0;
}