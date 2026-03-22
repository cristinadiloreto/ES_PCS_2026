#include <iostream>
#include <cmath>  // dalla libreria, serve per usare la funzione sqrt() e pow(). 

int main()
{
	static const int N = 5;
    double arr[N] = {1.1, 1.2, 1.3, 1.4, 1.5};
	
	// inizializzo una variabile max con cui confrontare tutti gli elementi dell'array e poi itero sugli elementi per
	// cercare il vero max.
	double max = 0.0;
	for (int i=0; i<N; i++) {
		if (arr[i]>max) {
			max = arr[i];  // non specifico di nuovo double perchè altrimenti andrei a creare una nuova variabile max 
			               // visibile solo all'interno dell'if. In questo caso, voglio soltanto aggiornare la 
						   // precedente variabile max. 
		}
	}
	
	std::cout << "Il valore massimo è: " << max << "\n";
	
	
	// faccio la stessa cosa per cercare il min, questa volta inizializzando ad una variabile double abbastanza grande.
	double min = 1000.0; 
	for (int i=0; i<N; i++) {
		if (arr[i]<min) {
			min = arr[i]; 
		}
	}
	
	std::cout << "Il valore minimo è: " << min << "\n"; 
	
	
	// preparo il calcolo della deviazione standard: 
    // 1) calcolo la media;
    // 2) calcolo lo scarto quadratico, sottraendo la media a tutti gli elementi ed elevando al quadrato;
    // 3) calcolo la varianza facendo la somma degli scarti quadratici diviso N-1;
    // 4) calcolo la dev standard facendo la radice della media.
	
	double somma = 0.0;
	for (int i=0; i<N; i++) {
		somma += arr[i];  // è come dire: somma = somma + arr[i].
	}
	
	double media = somma/N;
	
	std::cout << "La media degli elementi è: " << media << "\n";
	
	double somma_scarti = 0.0;
	for (int i=0; i<N; i++) {
		double scarti = std::pow(arr[i]-media, 2);  // ho cercato se si potesse fare l'evamento al quadrato con **2 e invece 
		                                            // ho trovato la funzione pow(..., n) che mi permette di fare 
		                                            // direttamente elevamenti a potenze n-esime.
		somma_scarti += scarti;
	}
	
	double var = somma_scarti/(N-1);
	double dev_std = std::sqrt(var);
	
	std::cout << "La deviazione standard è: " << dev_std << "\n";
	
	
	return 0;
}