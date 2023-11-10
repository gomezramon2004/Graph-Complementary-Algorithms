#include "appGrafo2.hpp"

// Add an edge to the graph, considering that the graph is directed, so U -> V
void Graph::addEdge(int u, int v, std::list<int>* &adj_list) {
    adj_list[u].push_back(v);
}

// Check if a par of nodes are connected at the same path; from the first node to the second one, and vice versa
bool Graph::areNodesConnected(std::list<int>* &adj_list) {
    std::vector<bool> visited(adj_list->size(), false);
    recursiveDFS(0, visited, adj_list);

    for (size_t i = 0; i < visited.size(); ++i) {
        if (!visited[i]) {
            return false;
        }
    }

    return true;
}

// Deep First Search - Recursive Function 
void Graph::recursiveDFS(int currentNode, std::vector<bool>& visited, std::list<int>* &adj_list) {
    visited[currentNode] = true;
    std::list<int>::iterator i;

    for (i = adj_list[currentNode].begin(); i != adj_list[currentNode].end(); ++i) {
        if (!visited[*i]) {
            recursiveDFS(*i, visited, adj_list);
        }
    }
}

// Deep First Search - Recursive Function without print
void Graph::recursiveDFSForTopological(int currentNode, std::vector<bool>& visited, std::list<int>* &adj_list, std::stack<int>& s) {
    visited[currentNode] = true;
    std::list<int>::iterator i;

    for (i = adj_list[currentNode].begin(); i != adj_list[currentNode].end(); ++i) {
        if (!visited[*i]) {
            recursiveDFSForTopological(*i, visited, adj_list, s);
        }
    }

    s.push(currentNode);
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

    std::cout << '\n';
}

// Check if the graph is a tree
bool Graph::isTree(int n, int m, std::list<int>* &adj_list) {
    return n == m + 1 && areNodesConnected(adj_list);
 }

 // Check if the graph is bipartite
 bool Graph::bipartiteGraph(int n, int m, std::list<int>* &adj_list) {
    int currentNode, currentColor;
    std::vector<int> color(n, -1);
    std::queue<std::pair<int,int>> q;
    std::list<int>::iterator i;

     for (int u = 0; u < n; ++u) {
        if (color[u] == -1) {
            q.push(std::make_pair(u, 0));
            color[u] = 0;

            while (!q.empty()) {
                currentNode = q.front().first;
                currentColor = q.front().second;
                q.pop();

                for (i = adj_list[currentNode].begin(); i != adj_list[currentNode].end(); ++i) {
                    if (color[*i] == -1) {
                        color[*i] = 1 - currentColor;
                        q.push(std::make_pair(*i, 1 - currentColor));
                    } else if (color[*i] == currentColor) {
                        return false;
                    }
                }
            }
        }
    }

    return true;
}

// Topological Sort
void Graph::topologicalSort(int n, int m, std::list<int>* &adj_list) {
    std::stack<int> s;
    std::vector<bool> visited(adj_list->size(), false);

    for (size_t i = 0; i < n; ++i) {
        if (!visited[i]) {
            recursiveDFS(i, visited, adj_list);
        }
    }
    
    while (!s.empty()) {
        std::cout << s.top() << " ";
        s.pop();
    }

    std::cout << '\n';
}