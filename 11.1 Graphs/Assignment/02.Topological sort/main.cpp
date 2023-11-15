//
// Created by rituparn on 15.11.23.
//

#include <iostream>
#include <vector>

template <typename T>
struct DirectedEdge {
    T src, dest;
};

template <typename T>
class Graph {
public:
    std::vector<std::vector<T>> adj;
    std::vector<T> degree;

    explicit Graph(T n) : adj(n), degree(n, 0) {}

    void AddEdge(const std::vector<DirectedEdge<T>>& edges) {
        for (const auto& edge : edges) {
            T src = edge.src;
            T dest = edge.dest;
            adj[src].push_back(dest);
            degree[dest]++;
        }
    }

    std::vector<T> TopologicalSort() const {
        std::vector<T> result;
        std::vector<T> temp_degree = degree;
        std::vector<T> zero_degree_vertices;

        for (u_int64_t i = 0; i < temp_degree.size(); ++i) {
            if (temp_degree[i] == 0) {
                zero_degree_vertices.push_back(i);
            }
        }

        while (!zero_degree_vertices.empty()) {
            T current_vertex = zero_degree_vertices.back();
            zero_degree_vertices.pop_back();
            result.push_back(current_vertex);

            for (T neighbor : adj[current_vertex]) {
                temp_degree[neighbor]--;
                if (temp_degree[neighbor] == 0) {
                    zero_degree_vertices.push_back(neighbor);
                }
            }
        }

        return result.size() == adj.size() ? result : std::vector<T>();
    }
};

int main() {
    int n, m, e1, e2;
    std::cin >> n >> m;

    Graph<int> graph(n);
    std::vector<DirectedEdge<int>> edges;

    for (int i = 0; i < m; ++i) {
        std::cin >> e1 >> e2;
        edges.push_back({e1, e2});
    }

    graph.AddEdge(edges);

    std::vector<int> result = graph.TopologicalSort();

    if (!result.empty()) {
        std::cout << "YES\n";
        for (int i : result) {
            std::cout << i << " ";
        }
    } else {
        std::cout << "NO";
    }

    return 0;
}