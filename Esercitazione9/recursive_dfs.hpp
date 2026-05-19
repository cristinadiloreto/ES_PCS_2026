#pragma once

#include "methods.hpp"
#include "graph.hpp"
#include "graph_visit.hpp"

//  implemento una funzione recursive_dfs() che:
// • Prende in input due parametri, il grafo da visitare ed il nodo sorgente
// • Restituisce un oggetto di tipo grafo contenente l’albero risultante dalla visita
// e che usa la versione ricorsiva della DFS per visitare il grafo.


// per semplicità, scrivo prima una funzione per la ricorsione:
void recursive(const unidirected_graph& G, int u, std::set<int>& visited, unidirected_graph& tree) {
	
    // inserisco il nodo corrente tra i visitati:
    visited.insert(u);

    // esploro i vicini usando il tuo metodo neighbours() implementato nell'esercitazione precedente:
    for (int v : G.neighbours(u)) {
		
        // se il vicino v non è ancora stato visitato, lo esploriamo:
        if (visited.find(v) == visited.end()) {
            tree.add_edges(u, v);   // aggiungo l'arco tra i due nodi per creare l'albero
            
			// cgiamata ricorsiva sul vicino: 
            recursive(G, v, visited, tree);
        }
    }
}


// ora posso implementare recursive_dfs() nello specifico:
unidirected_graph recursive_dfs(const unidirected_graph& G, int node) {
    unidirected_graph tree;      // inizializzo un grafo che conterrà l'albero risultante 
    std::set<int> visited;       // inizializzo un insieme per tenere traccia dei nodi visitati

    // iniziamo la ricorsione a partire dal nodo sorgente:
    recursive(G, node, visited, tree);

    return tree;
}