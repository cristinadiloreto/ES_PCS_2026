#include "sorted.h"   // algoritmi di sort
#include "randfiller.h"   // completamento random

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>   // per includere EXIT_SUCCESS e EXIT_FAILURE


// adatto i test fatti nell'esercitazione precedente a QuickSort:

int main(void) {
	
	// creo l'oggetto per generare numeri casuali:
	randfiller rf;
	
	// testiamo su 100 vettori casuali di tipo double:
	for (int i=1; i<101; i++) {
		std::vector<double> v1(50);   // creo per esempio un vettore di double, con dimensione scelta a caso
		rf.fill(v1, -1000.0, 500.0);  // riempio il vettore v con numeri casuali 
		                         //(ho scelto un range a caso che inlcludesse sia negativi che positivi)
	    quick_sort(v1, 0, v1.size()-1);  // applico l'algoritmo di merge_sort che ho definito nell'header
	
	    if (!is_sorted(v1)) {
	    	std::cout << "ERRORE: l'algoritmo QuickSort non ha funzionato correttamente sul vettore di double." << "\n";
		    return EXIT_FAILURE; 
	    }
	}
	
	// facciamo una prova con vettori casuali di interi:
	for (int i=1; i<101; i++) {
		std::vector<int> v2(27);
		rf.fill(v2, -15, 70);
		
		quick_sort(v2, 0, v2.size()-1); 
		
		if (!is_sorted(v2)) {
	    	std::cout << "ERRORE: l'algoritmo QuickSort non ha funzionato correttamente sul vettore di interi." << "\n";
		    return EXIT_FAILURE; 
	    }
	}
	
	// facciamo un ultimo tentativo con vettori di stringhe:
	std::vector<std::string> s = {"uno", "due", "tre", "quattro", "cinque", "sei", "sette", "otto", "nove", "dieci"};
	
	quick_sort(s, 0, s.size()-1);
	
	if (!is_sorted(s)) {
	    	std::cout << "ERRORE: l'algoritmo QuickSort non ha funzionato correttamente sul vettore di stringhe." << "\n";
		    return EXIT_FAILURE; 
	    }
		
	return EXIT_SUCCESS;
}