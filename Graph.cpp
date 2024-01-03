#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Graph {
private:
    map<T, vector<T>> adjList;
    int V;

public:
    Graph() {}

    Graph(int V) {
        this->V = V;
    }

    void addEdge(T src, T dest) {
        this->adjList[src].push_back(dest);
    }

    void bfs(T src) {
        map<T, bool> visited;
        queue<T> q;
        q.push(src);
        visited[src] = true;

        while (!q.empty()) {
            T current = q.front();
            q.pop();

            cout << current << " ";

            for (T neighbor : adjList[current]) {
                if (!visited[neighbor]) {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
    }

    void dfsUtil(T src, map<T, bool>& visited) {
        cout << src << " ";
        visited[src] = true;

        for (T neighbour : adjList[src]) {
            if (!visited[neighbour]) {
                dfsUtil(neighbour, visited);
            }
        }
    }

    void dfs(T src) {
        map<T, bool> visited;
        dfsUtil(src, visited);
    }
};

int main() {
    int V;
    cin >> V;
    int edges;
    cin >> edges;
    Graph<int> graph(V);

    for (int i = 0; i < 2 * edges; i++) {
        int x, y;
        cin >> x >> y;
        graph.addEdge(x, y);
    }

    cout << "Traversing in BFS Method...." << endl;
    int src;
    cin >> src;
    graph.bfs(src);
    cout << endl << "Traversing in DFS Method...." << endl;

    graph.dfs(src);

    return 0;
}
