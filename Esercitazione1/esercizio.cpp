#include <iostream>
#include <fstream>
#include <string>

int main(int argc, const char *argv[]) {
	if (argc<2) { // bisogna avere 2 argomenti: nome programma + nome file;
	              // quindi se argc<2 vuol dire che non ho il nome del file come parametro.
		std::cerr << "Errore: non è stato specificato alcun file.\n"; 
		return 1; // chiaramente non uso "return 0", che invece indicherebbe "successo".
	}
	
	std::ifstream filename(argv[1]); 
	if (!filename.is_open()) { //voglio stpare un messaggio di errore quando il file n on viene aperto correttamente.
	    std::cerr << "Errore: si è verificato un problema durante l'apertura del file.\n";
	    return 1;
	}
		
    // ometto di fare di nuovo un check sulla corretta apertura del file perchè ho già v erificato sopra se non si apre.
	
	while ( !filename.eof() ) { // itero fin quando non finisce il file.
	    std::string location; // mi salvo le città del file nella variabile location
		double t00, t06, t12, t18; // mi salvo le temperature come tipo double. 
		                           // t00 sta per "temperatura registrata alle ore 00:00", e via dicendo.
								   
		filename >> location >> t00 >> t06 >> t12 >> t18;
		
		// ora devo calcolare la media aritmetica della temperatura in ogni città.
		double media = (t00 + t06 + t12 + t18)/4.0; 
		std::cout << location << " " << media << "\n" << std::endl;
	}
	
	return 0;
}
		
	