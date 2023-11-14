//
// Created by rituparn on 13.11.23.
//
/*

STEPS:

1. Put the front node in the Queue
2. Then take it out, make it a frontNode, mark it as visited, and print it
3. Push all it neighbours in the queue
4. Now the front node=3
5. Take the front node from the queue, mark it as visited
6. Print it
7. Push all it neighbours in the queue
8. We can only push the neighbors in the queue if they are already not visited

 */

#include <iostream>
#include <list>


class Graph{

private:
    int numVertices_;
    std::list<int>* adjLists_;
    bool *visited;

public:
    Graph(int numVertices);
    void addEdge(int source, int destination);
    void BFS(int StartVertex);
};


Graph::Graph(int numVertices){

    numVertices_=numVertices;
    adjLists_=new std::list<int> [numVertices_];  //creating an array of the vectors
}

void Graph::addEdge(int source, int destination){
    adjLists_[source].push_back(destination);
    adjLists_[destination].push_back(source);
}

void Graph::BFS(int StartVertex) {
    visited= new bool [numVertices_];
    for (int i = 0; i < numVertices_; ++i) {
        visited[i]=false;
    }

    std::list<int> queue;

    visited[StartVertex]= true;  //marking the startvertex as visited

    queue.push_back(StartVertex); //pushing the startvertex back to the queue

    std::list<int>::iterator it;

    while (!queue.empty()) {  //in the queue
        int currVertex = queue.front();
        std::cout << "Visited " << currVertex << " ";
        queue.pop_front();
        for (it=adjLists_[StartVertex].begin(); it!=adjLists_[StartVertex].end();it++){
            int adjVertex=*it;
            std::cout << adjVertex;
            if (!visited[adjVertex]){
                    visited[adjVertex]= true;
                    queue.push_back(adjVertex);
            }

        }
    }


}

int main(){
    Graph graph(4);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 2);
    graph.addEdge(2, 0);
    graph.addEdge(2, 3);
    graph.addEdge(3, 3);

    graph.BFS(2);
    return 0;
}