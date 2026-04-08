#pragma once

#include <vector>

// scrivo una funzione template che restituisce true se il vettore è ordinato (ordine crescente), false altrimenti.

template <typename T>
bool is_sorted(const std::vector<T>& vec) {
	
	// se il vettore è vuoto 0 ha lunghezza 1, lo considero direttamente ordinato:
	if (vec.size() < 2) {
		return true;
	}
	
	for (size_t i=1; i<vec.size(); i++){
	     // dato che l'ordine deve essere crescente, se l'elemento in posizione i-1 esima è più grande di quello in posizione i
	     // allora il vettore NON è ordinato, e la funzione deve restituirmi false:
	     if (vec[i-1] > vec[i]) {
		     return false;
	     }
	}
	
	return true;   // se non entro nei due if, il vettore è ordinato.
}


// aggiungiamo una funzione template per bubble_sort:
template <typename T>
void bubble_sort(std::vector<T>& vec) {   // non ho messo const a differenza di prima, perchè impedirebbe modifiche al vettore.
	
	// come prima, se ha lunghezza 0 o 1 lo considero ordinato:
	if (vec.size() < 2) {
		return;  // esco direttamente.
	}
	
	// implemento l'algoritmo bubblesort fornito, ricordando di scalare gli indici:
	for (size_t i=0; i<vec.size()-1; i++) {
		for (size_t j=vec.size()-1; j>i; j--) {
			if (vec[j] < vec[j-1]) {  // devo scambiarli di posizione.
				T swap = vec[j-1];  // mi salvo la posizione j-1 esima in una nuova variale di tipo T, altrimenti andrebbe persa.
				vec[j-1] = vec[j];
				vec[j] = swap; 
			}
		}
	}
}


// aggiungiamo una funzione template per insertion_sort:
template <typename T>
void insertion_sort(std::vector<T>& vec) {
	
	// come al solito:
	if (vec.size() < 2) {
		return;
	}
	
	// implemento l'algoritmo scalando gli indici:
	for (size_t j=1; j<vec.size(); j++) {
		T key = vec[j];
		int i = j-1;
		while (i>-1 && vec[i]>key) {
			vec[i+1] = vec[i];
			i -= 1;
		}
		vec[i+1] = key;
	}
}


// aggiungiamo una funzione template per selection_sort: 
template <typename T>
void selection_sort(std::vector<T>& vec) {
	
	// come al solito:
	if (vec.size() < 2) {
		return;
	}
	
	// implemento l'algoritmo scalando gli indici:
	for (size_t i=0; i<vec.size()-1; i++) {   // size_t mi definisce un intero senza segno. Lo uso al posto di int
	                                          // perchè ho visto che mi dà errore nel momento in cui provo a confrontare
											  // un intero con segno con vec.size() che è senza segno.
		int min = i;
		for (size_t j=i+1; j<vec.size(); j++) {
			if(vec[j] < vec[min]) {
				min = j;
			}
		}
		T swap = vec[i];
		vec[i] = vec[min];
		vec[min] = swap;
	}
}