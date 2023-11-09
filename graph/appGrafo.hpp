#pragma once
#include <vector>
#include <list>
#include <iostream>
#include <stack>

class Graph {
    private:
        void recursiveDFS(int currentNode, std::vector<bool>& visited, std::vector<std::vector<bool>>& adj_matrix);
    public:
        void loadGraph(int n, int m, std::vector<std::vector<bool>>& adj_matrix, std::list<int>* &adj_list);
        void addEdge(int u, int v, std::vector<std::vector<bool>>& adj_matrix, std::list<int>* &adj_list);
        void removeEdge(int u, int v, std::vector<std::vector<bool>>& adj_matrix, std::list<int>* &adj_list);
        void DFS(int start, std::vector<std::vector<bool>>& adj_matrix);
        void BFS(int start,  std::list<int>* &adj_list);
};

