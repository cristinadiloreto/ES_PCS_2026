#include <iostream>
#include "graph.hpp"
#include "methods.hpp"
#include "graph_visit.hpp"
#include "recursive_dfs.hpp"
#include "dijkstra.hpp"


int main() {
    unidirected_graph G;
	
	// creo un grafo test:
    G.add_edges(1, 2);
    G.add_edges(1, 3);
    G.add_edges(2, 4);
    G.add_edges(3, 4);
    G.add_edges(2, 5);

    std::cout << "Grafo creato con " << G.all_nodes().size() << " nodi." << "\n";
	

    /* Effettua una visita in profondità di G, restituendo il risultato in bfsG */
    fifo<int> q;
    auto bfsG = graph_visit(G, 1, q); 
	
	// stampo per GraphViz: 
	std::cout << "graph BFS {\n";   // necessario per GraphViz
    for (const auto& edge : bfsG.all_edges()) {
        std::cout << "  " << edge.from() << " -- " << edge.to() << ";\n";    // sempre per GraphViz, è buona norma scrivere ; alla fine di ogni arco
    }
    std::cout << "}\n";
	
	

    /* Effettua una visita in profondità di G, restituendo il risultato in dfsG */
    lifo<int> s;
    auto dfsG = graph_visit(G, 1, s);
	
	// stampo per GraphViz:
	std::cout << "graph DFS {\n";    // necessario per GraphViz
    for (const auto& edge : dfsG.all_edges()) {
        std::cout << "  " << edge.from() << " -- " << edge.to() << ";\n";
    }
    std::cout << "}\n";
	
	

    /* Dijkstra */
    auto distanze = dijkstra(G, 1);
    
    for (auto const& [nodo, dist] : distanze) {
        std::cout << "Distanza dal nodo 1 al nodo " << nodo << ": " << dist << "\n";
    }

    return 0;
}