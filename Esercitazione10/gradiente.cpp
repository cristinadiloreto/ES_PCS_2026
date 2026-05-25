#include <iostream>
#include "gradiente_coniugato.hpp"

int main() {
	
	// definisco una generica matrice 3x3 simmetrica definita positiva:
	Eigen::MatrixXd A(3, 3);
	A << 4, 1, 0,
	     1, 3, 1,
		 0, 1, 2;
		 
	// definisco un vettore di termini noti di dimensione 3:
	Eigen::VectorXd b(3);
    b << 3, 2, 1;

    // inizializzo un vettore x0 ad esempio con tutti zeri:
    Eigen::VectorXd x0 = Eigen::VectorXd::Zero(3);

    // definisco una tolleranza e un numero massimo di iterazioni:
    double tol = 1.0e-10;
    int max_iter = 100;  

    // trovo la soluzione con il metodo gradiente_coniugato:
    Eigen::VectorXd x_sol = gradiente_coniugato(A, b, x0, tol, max_iter);

    std::cout << "La soluzione trovata applicando il metodo del gradiente coniugato è data dal vettore: " << "\n";
    std::cout << x_sol << "\n";
	
    return 0;  	
}