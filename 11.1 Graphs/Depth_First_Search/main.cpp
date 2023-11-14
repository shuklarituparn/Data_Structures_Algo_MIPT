//
// Created by rituparn on 13.11.23.
//
// DFS algorithm in C++

#include <iostream>
#include <list>

class Graph{
private:
    int NumberOfVertices_;
    std::list<int> adjList_; //adjacent list

public:
    Graph(int NumberOfVertices);
    void addNewEdge(int source, int destination);
    void DFS(int vertices);
    ~Graph();

};

Graph::Graph(int NumberOfVertices){
    this->NumberOfVertices_ = NumberOfVertices;
    std::list

}
void Graph::addNewEdge(int source, int destination){

}
void Graph::DFS(int vertices){

}
Graph::~Graph(){

}