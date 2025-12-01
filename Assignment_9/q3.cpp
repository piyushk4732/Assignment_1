#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct Edge {
    int u, v, weight;

    bool operator>(const Edge& other) const {
        return weight > other.weight;
    }
};

class UnionFind {
private:
    vector<int> parent, rank;
    
public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY])
                parent[rootX] = rootY;
            else if (rank[rootX] > rank[rootY])
                parent[rootY] = rootX;
            else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
    
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};

vector<Edge> kruskalMST(int vertices, vector<Edge>& edges) {
    vector<Edge> mst;

    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    });
    
    UnionFind uf(vertices);
    
    for (const Edge& edge : edges) {
        if (!uf.connected(edge.u, edge.v)) {
            uf.unite(edge.u, edge.v);
            mst.push_back(edge);

            if (mst.size() == vertices - 1)
                break;
        }
    }
    
    return mst;
}

vector<Edge> primMST(int vertices, vector<vector<pair<int, int>>>& adjList) {
    vector<Edge> mst;
    vector<bool> visited(vertices, false);
    priority_queue<Edge, vector<Edge>, greater<Edge>> minHeap;

    visited[0] = true;
    for (const auto& neighbor : adjList[0]) {
        minHeap.push({0, neighbor.first, neighbor.second});
    }
    
    while (!minHeap.empty() && mst.size() < vertices - 1) {
        Edge current = minHeap.top();
        minHeap.pop();
        
        if (visited[current.v])
            continue;
            
        visited[current.v] = true;
        mst.push_back(current);

        for (const auto& neighbor : adjList[current.v]) {
            if (!visited[neighbor.first]) {
                minHeap.push({current.v, neighbor.first, neighbor.second});
            }
        }
    }
    
    return mst;
}

void printMST(const vector<Edge>& mst) {
    int totalWeight = 0;

    for (const Edge& edge : mst) {
        cout << edge.u << " -- " << edge.v << " : " << edge.weight << "\n";
        totalWeight += edge.weight;
    }
    cout << "Total weight of MST: " << totalWeight << "\n";
}

int main() {
    int vertices = 5;
 
    vector<Edge> edges = {
        {0, 1, 2},
        {0, 3, 6},
        {1, 2, 3},
        {1, 3, 8},
        {1, 4, 5},
        {2, 4, 7},
        {3, 4, 9}
    };

    vector<vector<pair<int, int>>> adjList(vertices);
    for (const Edge& edge : edges) {
        adjList[edge.u].push_back({edge.v, edge.weight});
        adjList[edge.v].push_back({edge.u, edge.weight}); 
    }

    vector<Edge> kruskalResult = kruskalMST(vertices, edges);
    printMST(kruskalResult);

    vector<Edge> primResult = primMST(vertices, adjList);
    printMST(primResult);
    return 0;
}