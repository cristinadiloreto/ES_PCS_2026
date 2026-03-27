#pragma once
#include <iostream>
#include <concepts>
#include <numeric>   // mi serve per utilizzare std::gcd per il MCD.

template<typename I> requires std::integral<I>
class rational {
    I num_;
    I den_;
public: 
    
	/* costruttore di default */
    rational()
	  : num_(I{0}), den_(I{1})
	{}
	
	
	void simplify() {    // faccio una funzione che semplifica nel caso in cui num e den siano multipli.
	
	   if ((den_ == 0) || (num_ == 0)){   // in questo caso chiaramente non si semplifica.
		  return;
	   }
	   
	   I mcd = std::gcd(num_, den_);   // ho trovato std::gcd che mi permette direttamente di fare il MCD 
			                           // e in questo modo posso sempre semplificare la frazione 
									   // (al massimo se non è semplificabile avrei MCD=1 e non mi cambia nulla).
	   num_ /= mcd;
	   den_ /= mcd; 
	}
	
		
	/* costruttore user-defined */
    rational(const I& n, const I& d)
	  : num_(n), den_(d)
    { simplify(); }
	
	
    /* metodi che restituiscono numeratore e denominatore */
	I num() const { return num_; }
	I den() const { return den_; }
	

    /* implementazione dell'incremento positivo*/
	rational& operator+=(const rational& other) {   // operator mi permette di fare l'overload di operatori.
	                                                // In questo caso, sto sovrascrivendo l'operazione di incremento.
        
		// se uno dei due è NaN, il risultato deve essere Nan:
		if ((num_ == 0 && den_ == 0) || (other.num_ == 0 && other.den_ == 0)) {
			num_ = 0;
			den_ = 0;
			return *this;
		}
		
		// gestione dell'Inf:
		if ((den_ == 0) || (other.den_ == 0)) {
			num_ = num_ * other.den_ + other.num_ * den_;
			den_ = 0;
			return *this;
		}
		
		// devo implementare la somma tra frazioni, cioè devo scrivere (a/b)+(c/d) = (a*d + b*c)/(b*d):
		num_ = num_ * other.den_ + other.num_ * den_;
		den_ = den_ * other.den_;
		simplify();
		return *this;
	}
	
	/* definizione operatore somma */
	rational operator+(const rational& other) const {
		rational res1 = *this;
		res1 += other;
		return res1;
	}
	
	
	/* implementazione dell'incremento negativo */
	rational& operator-=(const rational& other) {
		
		// ancora una volta tratto il caso NaN a parte:
		if ((num_ == 0 && den_ == 0) || (other.num_ == 0 && other.den_ == 0)) {
			num_ = 0;
			den_ = 0;
			return *this;
		}
		
		// caso Inf:
		if ((den_ == 0) || (other.den_ == 0)) {
			num_ = num_ * other.den_ - other.num_ * den_;
			den_ = 0;
			return *this;
		}
		
		// come per la somma, implemento la sottrazione: (a/b)-(c/d) = (a*d - b*c)/(b*d):
		num_ = num_ * other.den_ - other.num_ * den_;
		den_ = den_ * other.den_;
		simplify();
		return *this;
	}
	
	/* definizione dell'operatore sottrazione */
	rational operator-(const rational& other) const {
		rational res2 = *this;
		res2 -= other;
		return res2;
	}
	
	
	/* implementazione dell'incremento per la moltiplicazione */
	rational& operator*=(const rational& other) {
		
		// solito caso NaN:
		if ((num_ == 0 && den_ == 0) || (other.num_ == 0 && other.den_ == 0)) {
			num_ = 0;
			den_ = 0;
			return *this;
		}
		
		// caso Inf:
		if ((den_ == 0) || (other.den_ == 0)) {
			num_ = num_ * other.num_;
			den_ = 0;
			return *this;
		}
		
		// implemento la moltiplicazione: (a/b)*(c/d) = (a*c)/(b*d):
		num_ = num_ * other.num_;
		den_ = den_ * other.den_;
		simplify();
		return *this;
	}
	
	/* definizione moltiplicazione */
	rational operator*(const rational& other) const {
		rational res3 = *this;
		res3 *= other;
		return res3;
	}
	
	
	/* implementazione dell'incremento per la divisione */
	rational& operator/=(const rational& other) {
		
		// NaN:
		if ((num_ == 0 && den_ == 0) || (other.num_ == 0 && other.den_ == 0)) {
			num_ = 0;
			den_ = 0;
			return *this;
		}
		
		// caso Inf questa volta diverso, perchè si presenta anche quando il numeratore del secondo numero e = 0:
		if ((den_ == 0) || (other.num_ == 0)) {
			num_ = num_ * other.den_;
			den_ = 0;
			return *this;
		}
		
		// impemnto da divisione tra frazioni: (a/b)/(c/d)=(a*d)/(b*c):
		num_ = num_ * other.den_;
		den_ = den_ * other.num_;
		simplify();
		return *this;
	}
	
	/* definizione divisione */
	rational operator/(const rational& other) const {
		rational res4 = *this;
		res4 /= other;
		return res4;
	}
	
};


// l'operazione di stampa deve essere implementata al di fuori della classe, in modo tale da permettere la sintassi std::cout //

/* implementazione dell'operatore << per la stampa di un oggetto della classe rational */
template<typename I> requires std::integral<I>
std::ostream& operator<<(std::ostream& os, const rational<I>& r) {
	
	if (r.den() == 0) {
		if (r.num() == 0) {  // in questo caso ho la forma indeterminata e mi deve restituire NaN.
			os << "NaN";
		}
		else {
			if (r.num() > 0) {  // denominatore = 0 e numeratore positivo mi deve restituire +Inf.
				os << "+Inf";
			}
			else {  // ultimo caso in cui den = 0 e numeratore negativo mi deve restituire -Inf.
				os << "-Inf";
			}
		}
	}
	else {   // se il denominatore è uguale ad 1 stampo direttamente un intero, se è diverso da 1 stampo l'intera frazione.
		os << r.num();
		if (r.den() != 1) {
			os << "/" << r.den(); 
		}
	}
	
	return os;
}