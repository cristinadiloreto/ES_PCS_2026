#pragma once

#include "graph.hpp"
#include "methods.hpp"

#include <queue>
#include <vector>
#include <map>
#include <limits>


// implemento l’algoritmo di Dijkstra utilizzando la struttura dati grafo dell’esercitazione precedente:
std::map<int, int> dijkstra(const unidirected_graph& G, int sorgente) {
	
    // inizializzo una mappa delle distanze (distanza minima dalla sorgente):
    std::map<int, int> distanze;
    
    // inizializziamo tutte le distanze a infinito:
    for (int nodo : G.all_nodes()) {
        distanze[nodo] = std::numeric_limits<int>::max();
    }
    
    // la distanza della sorgente da se stessa è 0:
    distanze[sorgente] = 0;

    // scrivo una coda con priorità "min-priority queue" per estrarre sempre il nodo con distanza minore.
	// per prima cosa mi creo una coppia (distanza, nodo) che mi serve come struttura nella coda:
	using NodoDist = std::pair<int, int>;   // using per creare un alias
	
    // std::greater permette di avere il valore più piccolo in cima:
    std::priority_queue<NodoDist, std::vector<NodoDist>, std::greater<NodoDist>> pq;
    pq.push({0, sorgente});


    while (!pq.empty()) {
		
		// fare pq.top() mi restituisce l'elemento in cima, che è un pair, quindi devo "dividerlo":
        int d = pq.top().first;     // .first accede al primo elemento della coppia di tipo pair (in questo caso "distanza")
        int u = pq.top().second;    // .second accede al secondo elemento della coppia di tipo pair (in questo caso "nodo")
        pq.pop();

        // se abbiamo già trovato un cammino più breve per u, andiamo avanti:
        if (d > distanze[u]) continue;

        // esploriamo i vicini usando il metodo neighbours() implementato nella vecchia esercitazione:
        for (int v : G.neighbours(u)) {
			
            // Ora tecnicamente l'algoritmo Dijkstra usa gli archi pesati, ma nell'implementazione di unidirected_edge e unidirected_graph 
			// nella scorsa esercitazione non abbiamo considerato i pesi. Quindi per semplicità, qui prendi 1 come peso predefinito:
            int weight = 1; 
            
            if (distanze[u] + weight < distanze[v]) {
                distanze[v] = distanze[u] + weight;
                pq.push({distanze[v], v});
            }
        }
    }

    return distanze;  // ritorna la mappa con le distanze minime
}