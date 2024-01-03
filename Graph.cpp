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

    void addEdge(T src, T dest, bool directed) {
        if(directed)
        {
            this->adjList[src].push_back(dest);
        }else
        {
            this->adjList[src].push_back(dest);
            this->adjList[dest].push_back(src);
        }
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

Graph<string> creatLocalGraph(Graph<string> g)
{

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
    Graph<string> g(10);
    g = creatLocalGraph(g);
    g.bfs("Khulna");
    return 0;
}
