#include <iostream>
#include "graph.hpp"


// scrivo un esempio di main per provare il funzionamento delle classi unidirected_edge e unidirected_graph implementate in "graph.hpp":

int main() {

    // test unidirected_edge:
    unidirected_edge edge1(1, 5);
    unidirected_edge edge2(5, 1);
    
    // verifico che l'ordine sia sempre (min, max):
    if (edge1.from() == 1 && edge1.to() == 5) {   // verifico il funzionamento dei metodi from() e to()
		std::cout << "L'arco viene costruito correttamente." << "\n";
	}
	else {
		std::cout << "Errore nei metodi from() e to(): l'arco non viene costruito correttamente." << "\n";
	}
	
    if (edge2.from() == 1 && edge2.to() == 5) {
		std::cout << "L'arco viene ordinato correttamente." << "\n";
	}
	else {
		std::cout << "Errore: l'ordine (min, max) non viene rispettato." << "\n";
	}
	
    if (edge1 == edge2) {   // verifico anche il funzionamento dell'operatore == 
		std::cout << "I due archi coincidono." << "\n";
	}
	else {
		std::cout << "I due archi non coincidono." << "\n";
	}
    
	// provo una stampa dell'arco, mi aspetto (1)--(5):
    std::cout << "Stampa arco: " << edge1 << "\n";



    // test unidirected_graph:
    unidirected_graph g1;
    g1.add_edges(1, 2);    // verifico il funzionamento del metodo add_edges()
    g1.add_edges(2, 3);
    g1.add_edges(3, 1);

    auto nodes = g1.all_nodes();    // verifico il metodo all_nodes()
	
    if (nodes.size() == 3) {
		std::cout << "Ci sono 3 nodi nel grafo. Il metodo all_nodes() ha funzionato correttamente." << "\n";
	}
	else {
		std::cout << "Errore: il metodo all_nodes() non funziona correttamente." << "\n";
	}
	
    if (g1.all_edges().size() == 3) {   // controllo se gli archi sono stati inseriti correttamente e verifico il funzionamento di all_edges()
		std::cout << "Il grafo presenta 3 archi. I metodi add_edges() e all_edges() funzionano correttamente." << "\n";
	}
	else {
		std::cout << "Errore: il metodo add_edges() e/o all_edges() non funziona correttamente." << "\n";
	}
    


    // test neighbours():
    auto vicini = g1.neighbours(2);
	
    // il nodo 2 è connesso a 1 e 3:
    if (vicini.count(1) == 1 && vicini.count(3) == 1 && vicini.count(5) == 0) {
		std::cout << "Il metodo neighbours() funziona correttamente." << "\n";
	}
	else {
		std::cout << "Errore: il metodo neighbours() non funziona correttamente." << "\n";
	}
    


    // test numerazione archi:
    unidirected_edge find_edge(2, 3);
    int indice = g1.edge_number(find_edge);
	
    if(indice != -1){
		if (g1.edge_at(indice) == find_edge) {
			std::cout << "L'arco " << find_edge << " si trova all'indice " << indice << "." << "\n";
		}
	}
    else {
		std::cout << "Non è stato trovato l'arco cercato." << "\n";
	}

    

    // test differenza (operator-):
    unidirected_graph g2;
    g2.add_edges(1, 2);   // arco in comune con g1
    g2.add_edges(4, 5);   // arco nuovo

    unidirected_graph diff = g1 - g2;
	
    // g1 ha (1,2), (2,3), (3,1). 
	// g2 ha (1,2), (4,5).
    // diff deve avere solo (2,3) e (3,1):
    auto diff_edges = diff.all_edges();
    if (diff_edges.size() == 2){
		std::cout << "Il grafo ottenuto dalla differenza ha 2 archi. L'operatore di differenza tra grafi ha funzionato correttamente." << "\n";
	}
    else {
		std::cout << "Errore: l'operatore - tra grafi non funziona correttamente." << "\n";
	}

    return 0;
}