//
// Created by rituparn on 15.11.23.
//


#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

template <typename T>
struct Graph {
    int num;
    std::vector<std::vector<T>> adjacent_vertices;
    std::vector<std::vector<T>> reversed_adjacent;

    Graph(int n) : num(n), adjacent_vertices(n), reversed_adjacent(n) {}

    void AddEdge(T from, T to) {
        adjacent_vertices[from].emplace_back(to);  //as far as I know that emplace creates that element in the back
        reversed_adjacent[to].emplace_back(from);
    }

    void DepthFirstSearch(T v, std::vector<bool>& visited, std::stack<T>& stack) {
        visited[v] = true;
        for (T w : adjacent_vertices[v]) {
            if (!visited[w]) {
                DepthFirstSearch(w, visited, stack);
            }
        }
        stack.push(v);
    }

    void Change(T v, std::vector<bool>& visited, std::vector<T>& component) {
        visited[v] = true;
        component.emplace_back(v);
        for (T w : reversed_adjacent[v]) {
            if (!visited[w]) {
                Change(w, visited, component);
            }
        }
    }

    std::vector<std::vector<T>> Algo() {
        std::stack<T> stack;
        std::vector<bool> visited(num, false);

        for (T i = 0; i < num; ++i) {
            if (!visited[i]) {
                DepthFirstSearch(i, visited, stack);
            }
        }

        visited.assign(num, false);

        std::vector<std::vector<T>> strongly_connected_component;

        while (!stack.empty()) {
            T list = stack.top();
            stack.pop();

            if (!visited[list]) {
                std::vector<T> connected_component;
                Change(list, visited, connected_component);
                strongly_connected_component.emplace_back(connected_component);
            }
        }

        return strongly_connected_component;
    }

    Graph<T> Squeeze(const std::vector<std::vector<T>>& components) {
        int new_vertices = components.size();
        Graph<T> xo(new_vertices);

        for (const auto& component : components) {
            for (T v : component) {
                for (T w : adjacent_vertices[v]) {
                    int component_index = FindIndex(components, v);
                    int neighbor_index = FindIndex(components, w);
                    if (component_index != neighbor_index) {
                        xo.AddEdge(component_index, neighbor_index);
                    }
                }
            }
        }

        return xo;
    }

    int FindIndex(const std::vector<std::vector<T>>& components, T vertex) {
        for (size_t i = 0; i < components.size(); ++i) {
            if (std::find(components[i].begin(), components[i].end(), vertex) !=
                components[i].end()) {
                return static_cast<int>(i);
            }
        }
        return -1;
    }

    std::pair<int, int> FindDegree() {
        std::vector<int> din(num, 0);
        std::vector<int> dout(num, 0);

        for (int find = 0; find < num; ++find) {
            for (T search : adjacent_vertices[find]) {
                dout[find]++;
                din[search]++;
            }
        }

        int total_degrees_in = std::count(din.begin(), din.end(), 0);
        int total_degrees_out = std::count(dout.begin(), dout.end(), 0);

        return {total_degrees_in, total_degrees_out};
    }
};

int main() {
    int n, m;
    std::cin >> n >> m;

    Graph<int> city_map(n);

    int a, b, count = 0;
    while (count < m) {
        std::cin >> a >> b;
        city_map.AddEdge(a - 1, b - 1);
        count++;
    }

    std::vector<std::vector<int>> map = city_map.Algo();

    if (map.size() == 1) {
        std::cout << 0 << std::endl;
        return 0;
    }

    if (map.empty()) {
        std::cout << 0 << std::endl;
        return 0;
    }

    Graph<int> ovo = city_map.Squeeze(map);

    std::pair<int, int> ans = ovo.FindDegree();
    std::cout << std::max(ans.first, ans.second) << std::endl;
    return 0;
}