#include "./graph/appGrafo2.hpp"

// In this program it will be used a Graph object to load a graph using an adjacency matrix and list, based on the number of nodes and edges introduced by the input stream.
// Then, it will be used the DFS and BFS algorithms to traverse the graph, starting from a node introduced by the input stream.

int main() {
    Graph g;
    std::list<int>* adj_list;
    int n, m;

    std::cout << "Introduce the number of nodes: ";
    std::cin >> n;
    std::cout << "Introduce the number of edges: ";
    std::cin >> m;

    g.loadGraph(n, m, adj_list);

    std::cout << "Is tree: " << (g.isTree(n, m, adj_list) ? "true" : "false") << std::endl;
    std::cout << "Is bipartite: " << (g.bipartiteGraph(n, m, adj_list) ? "true" : "false") << std::endl;

    std::cout << "Topological sort: ";
    g.topologicalSort(n, m, adj_list);

    return 0;
}