#include <vector>
using namespace std;

vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {

    vector<int> ans[n]; //so making n vectors
    vector<vector<int>> adjList (n);
    for(int i=0; i<m; ++i){
        int u=edges[i][0]; //to take the first edge
        int v=edges[i][1]; //we got the edges now make the adjacency list and push it

        ans[u].push_back(v);
        ans[v].push_back(u);  //as the graph is undirected so we push the elements for both


    }

    for(int i=0;i<n;i++){
        adjList[i].push_back(i); //as the answer wants the original number

        for (int j=0; j<ans[i].size(); j++){
            adjList[i].push_back(ans[i][j]);
        }
    }

    return adjList;



}
//We are passed the nodes, Edges, and the Vector<vector<int>> of edges

//n and m are the number of nodes and edges respectively
//The answer is printed as the increasing order of the nodes and then their neighbors
//The edges are given as {{2,1}, {2,0}} in the format of U and V
