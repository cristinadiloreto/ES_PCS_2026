#pragma once

#include <vector>
#include <limits>
#include <algorithm>

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




// implementiamo l'algoritmo di merge per merge_sort:
template <typename T>
void merge(std::vector<T>& vec, int p, int q, int r) {
	
	int n1 = q-p+1;
	int n2 = r-q;
	
	// creiamo gli array L e R:
	std::vector<T> L(n1+1);
	std::vector<T> R(n2+1);
	
	for (int i = 0; i < n1; i++) {
		L[i] = vec[p+i]; 
	}
	
	for (int j = 0; j < n2; j++){
		R[j] = vec[q+j+1];  // anche qui aggiunto 1 per aggiustare gli indici
	}
	
	// poniamo ad infinito L[n1] e R[n2]:
	L[n1] = std::numeric_limits<T>::max();
	R[n2] = std::numeric_limits<T>::max();
	int i = 0;
	int j = 0;
	
	for (int k = p; k <= r; k++) {  // mi serve il <= altrimenti l'ultimo elemento non viene trascritto
		if (L[i] <= R[j]){
			vec[k] = L[i];
			i = i+1;
		}
		else {
			vec[k] = R[j];
			j = j+1;
		}
	}
}


// aggiungiamo una funzione template per merge_sort:
template <typename T>
void merge_sort(std::vector<T>& vec, int p, int r) {
	
	// implemento l'algoritmo fornito: 
	if (p < r) {
		int q = p + (r - p)/2;  // per scrivere la parte intera di (p+r)/2
		
		// chiamate ricorsive: 
		merge_sort(vec, p, q);
		merge_sort(vec, q+1, r);
		
		// unione delle parti ordinate:
		merge(vec, p, q, r);
	}
}




// implementiamo l'algoritmo di partition per quick_sort:
template <typename T>
int partition(std::vector<T>& vec, int p, int r) {   // questa volta int e non void perchè mi deve restituire i+1
	
	T x = vec[r];  // il pivot è l'ultimo elemento
	int i = p-1;
	
	for (int j = p; j < r; j++) {  
		if (vec[j] <= x) {
			i = i+1;
			std::swap(vec[i], vec[j]);
		}
	}

    // posiziono il pivot correttamente tra le due partizioni:
	std::swap(vec[i+1], vec[r]);
	return i+1;
}


// aggiungiamo una funzione template per quick_sort:
template <typename T>
void quick_sort(std::vector<T>& vec, int p, int r) {
	
	if (vec.size() < 2) {
		return;
	}
	
	if (p < r) {
		int q = partition(vec, p, r);
		
		// chiamate ricorsive:
		quick_sort(vec, p, q-1);
		quick_sort(vec, q+1, r);
	}
}