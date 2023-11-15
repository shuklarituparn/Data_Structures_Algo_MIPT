//
// Created by rituparn on 14.11.23.
//

#include <climits>
#include <iostream>
#include <queue>
#include <vector>

template <typename T>
struct Graph {
    std::vector<std::vector<T>> adj;

    explicit Graph(int n) { adj.resize(n); }

    static T ShortestRoute(int num, std::vector<T>& alpha,
                           std::vector<T>& alpha_two,
                           std::vector<T>& alpha_dist) {
        T sum = num * 2;
        for (int i = 0; i < num; ++i) {
            if ((alpha[i] + alpha_two[i] + alpha_dist[i]) < sum) {
                sum = alpha[i] + alpha_two[i] + alpha_dist[i];
            }
        }

        return sum;
    }

    void AddEdge(T from, T to) {
        adj[from].push_back(to);
        adj[to].push_back(from);
    }

    void BFS(T first, int n, std::vector<T>& before, std::vector<T>& distance) {
        std::priority_queue<std::pair<T, T>, std::vector<std::pair<T, T>>,
                std::greater<>>
                pq;
        std::vector<bool> visited(n, false);
        for (int i = 0; i < n; i++) {
            distance[i] = INT_MAX;
            before[i] = -1;
        }
        visited[first] = true;
        distance[first] = 0;
        pq.emplace(distance[first], first);
        while (!pq.empty()) {
            T u = pq.top().second;
            pq.pop();
            for (T v : adj[u]) {
                T weight = 1;
                if (!visited[v] && distance[u] + weight < distance[v]) {
                    distance[v] = distance[u] + weight;
                    before[v] = u;
                    pq.emplace(distance[v], v);
                }
            }
            visited[u] = true;
        }
    }

    T ShortestDist(T first_source, T second_source, T destination, int num) {
        std::vector<T> store_1(num, -1);
        std::vector<T> distance_1(num, INT_MAX);
        std::vector<T> store_2(num, -1);
        std::vector<T> distance_2(num, INT_MAX);
        std::vector<T> omega_1(num, -1);
        std::vector<T> omega_2(num, INT_MAX);

        BFS(first_source, num, store_1, distance_1);
        BFS(second_source, num, store_2, distance_2);
        BFS(destination, num, omega_1, omega_2);

        return ShortestRoute(num, distance_1, distance_2, omega_2);
    }
};

int main() {
    int n, m, l, matilda, leon;
    std::cin >> n >> m >> l >> matilda >> leon;

    Graph<int> city_map(n + 1);
    int i = 0, a, b;
    while (i < m) {
        std::cin >> a >> b;
        city_map.AddEdge(a, b);
        i++;
    }
    std::cout << city_map.ShortestDist(l, matilda, leon, (n + 1));
    return 0;
}