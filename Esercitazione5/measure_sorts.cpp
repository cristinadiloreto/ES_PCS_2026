#include "sorted.h"
#include "timecounter.h" 
#include "randfiller.h"

#include <iostream>
#include <vector>
#include <algorithm>   // per il confronto con std::sort()

int main(void) {
	randfiller rf;
	timecounter tc;

	// come richiesto, misuriamo in particolare il tempo impiegato su vettori di dimensione inferiore a 100 riempiti in modo casuale:
	for (int i=1; i<100; i++) {
		int num_campioni = 100; // come da testo dell'esercizio
		
		// preallocazione e riempimento casuale:
		std::vector<std::vector<double>> campioni(num_campioni, std::vector<double>(i));
		for (size_t k = 0; k < campioni.size(); k++) {
             std::vector<double>& v = campioni[k]; 
             rf.fill(v, -7000.0, 3500.0);   // range casuale per usare sia numeri negativi che positivi
        }
		
		// creo delle copie dell'intero set di vettori per ogni algoritmo. Se non lo facessi, dopo il primo tipo di sort il vettore v
		// risulterebbe già ordinato e "non avrebbe senso" usare anche gli altri algoritmi.
		std::vector<std::vector<double>> v1 = campioni;  // per Bubble_Sort
		std::vector<std::vector<double>> v2 = campioni;  // per Insertion_Sort
		std::vector<std::vector<double>> v3 = campioni;  // per Selection_Sort
		std::vector<std::vector<double>> v4 = campioni;  // per MergeSort
		std::vector<std::vector<double>> v5 = campioni;  // per QuickSort
		std::vector<std::vector<double>> v6 = campioni;  // per std::sort()
		
		// tempo Bubble_Sort:
		tc.tic();
		for (int j = 0; j < num_campioni; j++){
		     bubble_sort(v1[j]);
		}
		double t_bubble = tc.toc()/num_campioni;
		
		// tempo Insertion_Sort:
		tc.tic();
		for (int j = 0; j < num_campioni; j++){
		     insertion_sort(v2[j]);
	    }
		double t_insertion = tc.toc()/num_campioni;
		
		// tempo Selection_Sort:
		tc.tic();
		for (int j = 0; j < num_campioni; j++){
		     selection_sort(v3[j]);
		}
		double t_selection = tc.toc()/num_campioni;
		
		// tempo Merge_Sort:
		tc.tic();
		for (int j = 0; j < num_campioni; j++){
		     merge_sort(v4[j], 0, i-1);  // posso scrivere i-1 per indicare la fine del vettore perchè in questo caso i rappresenta esattamente
			                             // la dimensione che abbiamo dato ai vettori quando li abbiamo creati con std::vector<double>(i).
		}
		double t_merge = tc.toc()/num_campioni;
		
		// tempo Quick_Sort:
		tc.tic();
		for (int j = 0; j < num_campioni; j++){
		     quick_sort(v5[j], 0, i-1);
		}
		double t_quick = tc.toc()/num_campioni;
		
		// tempo std::sort():
		tc.tic();
		for (int j = 0; j < num_campioni; j++){
		std::sort(v6[j].begin(), v6[j].end());
	    }
		double t_sort = tc.toc()/num_campioni;
		
		// stampo i risultati per ogni ciclo for:
		std::cout << "Lunghezza del vettore di double: " << i << "\n";
        std::cout << "Tempo di esecuzione Bubble_Sort: " << t_bubble << "\n";		
		std::cout << "Tempo di esecuzione Insertion_Sort: " << t_insertion << "\n";
		std::cout << "Tempo di esecuzione Selection_Sort: " << t_selection << "\n";
		std::cout << "Tempo di esecuzione Merge_Sort: " << t_merge << "\n";
		std::cout << "Tempo di esecuzione Quick_Sort: " << t_quick << "\n";
		std::cout << "Tempo di esecuzione std::sort(): " << t_sort << "\n";
		std::cout << " \n";
	}
	
	return 0;
}