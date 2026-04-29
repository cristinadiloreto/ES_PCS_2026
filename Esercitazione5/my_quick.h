#pragma once

#include <vector>
#include <algorithm>

// dalle osservazioni già fatte nel file "osservazioni.txt" abbiamo visto che l'algoritmo quadratico più veloce risulta essere
// Insertion_Sort e che questo inizia ad essere recuperato in velocità dal Quick_Sort ad una dimensione del vettore pari a circa n=20, 
// per poi essere completamente superato attorno ad n=50. Per questo motivo, propongo una soglia di mezzo tra le due (n=30) per la nuova
// implementazione del Quick_Sort che utilizza l'Insertion_Sort per l'ordinamento.



// scrivo una nuova implementazione dell'Insertion_Sort (in realtà è la stessa di sempre, ma la riporto qui per semplicità 
// con i paramentri p e r che mi servono poi nel Quick):

template <typename T>
void my_Insertion(std::vector<T>& vec, int p, int r) {
	
	// se il vettore è vuoto 0 ha lunghezza 1, lo considero direttamente ordinato:
	if (vec.size() < 2) {
		return;
	}
	
    for (int j = p + 1; j <= r; j++) {
        T key = vec[j];
        int i = j - 1;
        while (i >= p && vec[i] > key) {
            vec[i + 1] = vec[i];
            i -= 1;
        }
        vec[i + 1] = key;
    }
}



// per comodità riporto anche l'implementazione di partion già fatta in precedenza in "sorted.h":
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



// scrivo una nuova implementazione del Quick che sfrutti my_Insertion:
template <typename T>
void my_Quick(std::vector<T>& vec, int p, int r) {
	
    // definizione della soglia:
    const int soglia = 30;

    if (p < r) {
		
        // se la dimensione della partizione è piccola uso Insertion_Sort:
        if (r - p + 1 <= soglia) {
            my_Insertion(vec, p, r);
        } 
        else {
			
            // altrimenti proseguo con la logica standard del Quick_Sort
            int q = partition(vec, p, r);
            my_Quick(vec, p, q - 1);
            my_Quick(vec, q + 1, r);
        }
    }
}