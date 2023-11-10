#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>

class Graph {
    private:
        void addEdge(int u, int v, std::list<int>* &adj_list);
        bool areNodesConnected(std::list<int>* &adj_list);
        void recursiveDFS(int currentNode, std::vector<bool>& visited, std::list<int>* &adj_list);
    public:
        void loadGraph(int n, int m, std::list<int>* &adj_list);
        void BFS(int start, std::list<int>* &adj_list);
        bool isTree(int n, int m, std::list<int>* &adj_list);
        bool bipartiteGraph(int n, int m, std::list<int>* &adj_list);
        void topologicalSort(int n, int m, std::list<int>* &adj_list);
};

