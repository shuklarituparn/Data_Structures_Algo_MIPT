//
// Created by rituparn on 10.11.23.
//
#include <iostream>
#include <unordered_map>
#include <list>

template <typename T>
class Graph{
    public:
    std::unordered_map<T, std::list<T>> adj;  //adj list where we map the list with the number
    void addEdge(T u, T v, bool direction){ //u is the first edge and v is the second
        //direction=0->undirected
        //direction=1->directed

        //create an edge between u and v
        adj[u].push_back(v); //we added the v to the u
        if (!direction){
            adj[v].push_back(u); //if it's not directed then V will also be connected to U

        }

    }//Now we made the adj list we need to print it

    void PrintAdjList(){
        for (auto i:adj) {
            std::cout <<i.first << "->";  //printing the first number in the adj
            for (auto j:i.second) { //looping through the second and printing it
                std::cout<<j<<",";


            }
            std::cout<<std::endl;
        }
    }
}; //Now we have our graph and the adj list

int main(){
    int u;
    int v;
    std::cout<<"Enter the number of nodes in the graph"<<std::endl;
    std::cin>>u;

    std::cout<<"Enter the number of edges in the graph"<<std::endl;
    std::cin>>v;

    Graph<int> graph1;

    for (int i = 0; i < v; ++i) {
        int num1,num2;
        std::cin>>num1>>num2;
        graph1.addEdge(num1,num2,false); //as this is the undirected graph so the direction is 0
    }

    graph1.PrintAdjList();


}

