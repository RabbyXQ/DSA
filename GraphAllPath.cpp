#include <iostream>
#include <map>
#include <vector>
using namespace std;

template <typename T>
class Graph {
private:
    map<T, vector<T>> adjList;

public:
    Graph() {}

    void addEdge(T src, T dest, bool directed) {
        if (directed) {
            this->adjList[src].push_back(dest);
        } else {
            this->adjList[src].push_back(dest);
            this->adjList[dest].push_back(src);
        }
    }

    void dfsUtil(T src, map<T, bool>& visited) {
        cout << src << " ";
        visited[src] = true;

        for (T neighbor : adjList[src]) {
            if (!visited[neighbor]) {
                dfsUtil(neighbor, visited);
            }
        }
    }

    void dfs(T src) {
        map<T, bool> visited;
        dfsUtil(src, visited);
    }

    void allPathsUtil(T src, T dest, map<T, bool>& visited, vector<T>& paths) {
        visited[src] = true;
        paths.push_back(src);

        if (src == dest) {
            for (const T& vertex : paths) {
                cout << vertex << " ";
            }
            cout << endl;
        } else {
            for (const auto& neighbor : this->adjList[src]) {
                if (!visited[neighbor]) {
                    allPathsUtil(neighbor, dest, visited, paths);
                }
            }
        }

        paths.pop_back();
        visited[src] = false;
    }

    void allPath(T src, T dest) {
        map<T, bool> visited;
        vector<T> paths;

        for (const auto& vertex : this->adjList) {
            visited[vertex.first] = false;
        }

        allPathsUtil(src, dest, visited, paths);
    }
};

Graph<string> createLocalGraph(Graph<string> g) {
    g.addEdge("Chuadanga", "Meherpur", false);
    g.addEdge("Chuadanga", "Alamdanga", false);
    g.addEdge("Alamdanga", "Kushtia", false);
    g.addEdge("Meherpur", "Kushtia", false);
    g.addEdge("Kushtia", "Pabna", false);
    g.addEdge("Pabna", "Rajshahi", false);
    g.addEdge("Chuadanga", "Jhenaidah", false);
    g.addEdge("Jhenaidah", "Kushtia", false);
    g.addEdge("Jhenaidah", "Jashore", false);
    g.addEdge("Jashore", "Khulna", false);
    return g;
}

int main() {
    Graph<string> g;
    g = createLocalGraph(g);
    g.allPath("Khulna", "Rajshahi");
    return 0;
}
