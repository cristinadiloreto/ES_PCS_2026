#include "sorted.h"
#include "timecounter.h" 
#include "randfiller.h"

#include <iostream>
#include <vector>
#include <algorithm>   // per il confronto con std::sort()

int main(void) {
	randfiller rf;
	timecounter tc;
	
	// come richiesto, misuriamo in particolare il tempo impiegato su vettori di lunghezze {4,8,16,...,8192} riempiti in modo casuale:
	for (int i=4; i<8193; i*=2) {
		
		// creo un vettore casuale di double di dimensione i variabile:
		std::vector<double> v(i);
		rf.fill(v, -7000.0, 3500.0);  // range casuale per includere sia negativi che positivi
		
		// creo delle copie del vettore v per ogni algoritmo. Se non lo facessi, dopo il primo tipo di sort il vettore v
		// risulterebbe già ordinato e "non avrebbe senso" usare anche gli altri algoritmi.
		std::vector<double> v1 = v;  // per Bubble_Sort
		std::vector<double> v2 = v;  // per Insertion_Sort
		std::vector<double> v3 = v;  // per Selection_Sort
		std::vector<double> v4 = v;  // per std::sort()
		
		// tempo Bubble_Sort:
		tc.tic();
		bubble_sort(v1);
		double t_bubble = tc.toc();
		
		// tempo Insertion_Sort:
		tc.tic();
		insertion_sort(v2);
		double t_insertion = tc.toc();
		
		// tempo Selection_Sort:
		tc.tic();
		selection_sort(v3);
		double t_selection = tc.toc();
		
		// tempo std::sort():
		tc.tic();
		std::sort(v4.begin(), v4.end());
		double t_sort = tc.toc();
		
		// stampo i risultati per ogni ciclo for:
		std::cout << "Lunghezza del vettore di double: " << i << "\n";
        std::cout << "Tempo di esecuzione Bubble_Sort: " << t_bubble << "\n";		
		std::cout << "Tempo di esecuzione Insertion_Sort: " << t_insertion << "\n";
		std::cout << "Tempo di esecuzione Selection_Sort: " << t_selection << "\n";
		std::cout << "Tempo di esecuzione std::sort(): " << t_sort << "\n";
	}
	
	return 0;
}