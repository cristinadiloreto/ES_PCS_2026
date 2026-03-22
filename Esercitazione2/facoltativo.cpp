#include <iostream>

int main() {
	
	// prendo l'array dell'eserciizio precedente (ho spostato gli elemnti in ordine casuale per verificare che il programma funzionasse):
	static const int N = 5;
    double arr[N] = {1.5, 1.2, 1.3, 1.1, 1.4};
	
	bool flag = false;  // non ho ancora fatto scambi.
	
	do {
		flag = false;  // all'inizio di ogni giro ipotizzo di non aver fatto ancora scambi.
	
	    for (int i=0; i<N-1; i++) {
	     	if (arr[i]>arr[i+1]) {
		       double scambio = arr[i];  // mi salvo arr[i] in una nuova variabile scambio, perchè altrimenti lo perderei alla riga 
			                             // successiva quando vado a sostituirlo con arr[i+1].
			   arr[i] = arr[i+1]; 
			   arr[i+1] = scambio;
			   
			   flag = true;  // ho fatto uno scambio. 
		     }
	    }
	} while (flag == true);  // se ho fatto scambi, ricomincio il giro.
	
	
	// stampo per verificare di aver riordinato l'array:
	std::cout << "Elementi ordinati: " << "\n";
	for (int i=0; i<N; i++) {
		std::cout << arr[i] << " "; 
	}
		
	return 0;
}
