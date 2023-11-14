//
// Created by rituparn on 13.11.23.
//
#include <iostream>
#include <vector>

void addEdge(std::vector<int> adj[], int i, int j ){
    adj[i].push_back(j); //in the first vector push the second, in the second vector push the first
    adj[j].push_back(i); //as it is undirected graph, so we are pushing back the elements both ways

}

void printGraph(std::vector<int> adj[], int V){  //passing the number of vertices, and the adj list (array of int vectors)
    for (int i = 0; i <V; ++i) { //going to the first node
        std::cout<<"\n Vertex "<<i<<": ";
        for(auto j:adj[i]){ //printing the numbers that it is connected to

            std::cout<<"-> ";
            std::cout<<j;

        }

    }
}

int main(){
    int V=5;
    std::vector<int> adj[V];
    addEdge(adj,0, 1);
    addEdge(adj,0, 2);
    addEdge(adj,0, 3);
    addEdge(adj,1, 2);
    printGraph(adj,V);



}