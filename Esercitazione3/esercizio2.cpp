#include <iostream>
#include "rational.hpp"

int main(void) {
	
	// provo la stampa di alcune frazioni per verificare se ho implementato correttamente tutti i caso:
	rational<int> r0(3, 6);
	rational<int> r1(-2, 7);
	std::cout << r0 << "\n";  // dovrebbe semplificare la frazione come 1/2.
	std::cout << r1 << "\n";
	
	rational<int> r2(1, 0);
	std::cout << r2 << "\n";  // dovrebbe darmi +Inf.
	
	rational<int> r3(-5, 0);
	std::cout << r3 << "\n";  // dovrebbe darmu -Inf.
	
	rational<int> r4(0, 0);
	std::cout << r4 << "\n";  // dovrebbe darmi NaN.
	
	
	// provo a fare qualche operazione, anche con i risultati "speciali":
	std::cout << "somma r0+r0: " << r0+r0 << "\n";   // dovrebbe darmi 1.
	std::cout << "somma r0+r3: " << r0+r3 << "\n";   // dovrebbe darmi -Inf.
	std::cout << "sottrazione r1-r0: " << r1-r0 << "\n";   // dovrebbe darmi (-2/7)-(1/2)=(-4-7)/(14)=-11/14.
	std::cout << "prodotto r1*r4: " << r1*r4 << "\n";   // dovrebbe darmi NaN.
	std::cout << "divisione r3/r4: " << r3/r4 << "\n";   // dovrebbe darmi NaN (qualsiasi operazione con un NaN dovrebbe
	                                                     // stamparmi NaN, anche se l'altro numero è un Inf).
	std::cout << "divisione r2/r3: " << r2/r4 << "\n";   // sarebbe +Inf/-Inf, quindi dovrebbe darmi NaN.
	return 0;
}