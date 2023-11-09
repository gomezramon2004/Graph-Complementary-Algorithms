#include "appGrafo2.hpp"

// Deep First Search - Recursive Function
void Graph::recursiveDFS(int currentNode, std::vector<bool>& visited, std::list<int>* &adj_list) {
    visited[currentNode] = true;
    std::cout << currentNode << " ";
    std::list<int>::iterator i;

    for (i = adj_list[currentNode].begin(); i != adj_list[currentNode].end(); ++i) {
        if (!visited[*i]) {
            recursiveDFS(*i, visited, adj_list);
        }
    }
}

// Constructor of graph
void Graph::loadGraph(int n, int m, std::list<int>* &adj_list) {
    int u, v;
    adj_list =  new std::list<int>[n];

    for (size_t i = 0; i < m; ++i) {
        std::cout << "Introduce the edge " << i + 1 << ": ";
        std::cin >> u >> v;
        addEdge(u, v, adj_list);
    }
}

// Add an edge to the graph, considering that the graph is directed, so U -> V
void Graph::addEdge(int u, int v, std::list<int>* &adj_list) {
    adj_list[u].push_back(v);
}

// Remove an edge to the graph, considering that the graph is directed, so U -> V
void Graph::removeEdge(int u, int v, std::list<int>* &adj_list) {
    adj_list[u].remove(v);
}

// Deep First Search - Base Functio
void Graph::DFS(int start, std::list<int>* &adj_list) {
    std::vector<bool> visited(adj_list->size(), false);
    recursiveDFS(start, visited, adj_list);
    std::cout << std::endl;
}

// Breadth First Search
void Graph::BFS(int currentNode, std::list<int>* &adj_list) {
    std::vector<bool> visited(adj_list->size(), false);
    std::queue<int> q;

    visited[currentNode] = true;
    q.push(currentNode);
    std::list<int>::iterator i;

    while (!q.empty()) {
        currentNode = q.front();
        std::cout << currentNode << " ";
        q.pop();

        for (i = adj_list[currentNode].begin(); i != adj_list[currentNode].end(); ++i) {
            if (!visited[*i]) {
                visited[*i] = true;
                q.push(*i);
            }
        }
    }

    std::cout << std::endl;
}