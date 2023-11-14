//
// Created by rituparn on 13.11.23.
//

/*
If there is an edge from vertex i to j, mark adjMat[i][j] as 1.
If there is no edge from vertex i to j, mark adjMat[i][j] as 0.
 */

#include <iostream>


class Graph{
private:
   int  numberOfVertices_;
   bool ** adjMat_;
public:
    Graph(int numberOfVertices); //to initialize the graph
    void addEdge(int i, int j); //to add the edge
    void removeEdge(int i, int j);  //to remove the edge
    void toString(); //to print the graph
    ~Graph();
};

Graph::Graph(int numOfVertices){
    this->numberOfVertices_=numOfVertices;  //  Nodes are also called vertices
    adjMat_= new bool * [numberOfVertices_]; //creating  a boolean matrix which is numberOfVertices length (first layer) big
    //numberOfVertices = matrix *numberofVertices
    for (int i = 0; i < numberOfVertices_; ++i) {     //going in all the vertical layer and creating a new matrix -> this direction of number of vertices big
        adjMat_[i]=new bool [numberOfVertices_];          //Making the matrix
        for (int j = 0; j < numberOfVertices_; ++j) {  //Entering the second layer and traversing the matrix
            adjMat_[i][j]= false;   //denoting the layers as false meaning that not visited
        }
    }

}

void Graph::addEdge(int i,int j) {  //as the graph is undirected so both directions will be true

    adjMat_[i][j]=true;
    adjMat_[j][i]=true;
}

void Graph::removeEdge(int i,int j){

    adjMat_[i][j]=false;
    adjMat_[j][i]=false;

}

void Graph::toString() {
    //to print the graph go to the graph for the first row and print all the number

    for (int i = 0; i < numberOfVertices_; ++i) {

        std::cout<<i<<":";
        for (int j = 0; j < numberOfVertices_; ++j) {
            std::cout<<adjMat_[i][j]<<" ";  //this prints the columns
        }
        std::cout<<std::endl;
    }

}

Graph::~Graph() {
        //To destroy the graph

    for (int i = 0; i <numberOfVertices_; ++i) {
        delete[] adjMat_[i];
    }
    delete [] adjMat_;
}

int main(){
    Graph graph1(4);


    graph1.addEdge(0, 1);
    graph1.addEdge(0, 2);
    graph1.addEdge(1, 2);
    graph1.addEdge(2, 0);
    graph1.addEdge(2, 3);

    graph1.toString();

}

/*
0:0 1 1 0
1:1 0 1 0
2:1 1 0 1
3:0 0 1 0
 */