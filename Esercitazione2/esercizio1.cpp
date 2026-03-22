#include <iostream>

int main()
{
   double ad[4] = {0.0, 1.1, 2.2, 3.3};
   float af[8] = {0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
   int ai[3] = {0, 1, 2};
   
   int x = 1;
   float y = 1.1;
   
   (&y)[1] = 0;
   
   std::cout << x << "\n";   // questa riga stampa 0 e non 1 perchè il comando a riga 12 prende l'indirizzo di y e va a indice 1.
                             // Cioè fa: indirizzo_di_y + i*sizeof(y)= ...32 + 1*4 = ...36 che è esattamente l'indirizzo di x.
							 // Quindi, il comando a riga 12 prende il valore salvato all'indirizzo di x e lo pone uguale a 0.
   
   // indirizzi array per disegnare la rappresentazione in memoria:
   // std::cout << &ad[0] << "\n";
   // std::cout << &af[0] << "\n";
   // std::cout << &ai[0] << "\n";
   
   // stampiamo gli indirizzi delle variabili scalari:
   std::cout << &x << "\n";  // 0x7ffc02127550  -> in decimale: ...36
   std::cout << &y << "\n";  // 0x7ffc0212754c  -> in decimale: ...32
   
   return 0;
}