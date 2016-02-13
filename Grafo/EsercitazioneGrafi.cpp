#include "Grafo/Grafo.h"
#include <iostream>
using namespace std;

/*
Esercizio 1
Definire una funzione che, dato in input un grafo orientato G(V, E), restituisca true se ogni nodo
v in V ha almeno due nodi adiacenti consecutivi, false altrimenti.
Esempio: per il grafo sotto raffigurato la funzione dovrebbe restituire true perch ́e ogni nodo del
grafo ha un numero di nodi adiacenti consecutivi maggiore o uguale a due.
*/

bool CalcolaAdiacenti( Grafo Gr)
{
  int NodiAdiacenti = 0;

  for( int i = 1; i <= Gr.n(); i++)
    {
      for( int j = 1; j < Gr.n(); j++)
        {
            if( Gr(i,j))
              cout << i << "->" << j << endl;
            if(i != j && Gr(i,j) && Gr(i, j+1) && i != j+1 )
              NodiAdiacenti++;
        }
      if( NodiAdiacenti < 1)
        return false;

      NodiAdiacenti = 0;
    }
  return true;
}

int main()
{
  int NumeroArchi;
  cin >> NumeroArchi;

  int NumeroNodi;
  cin >> NumeroNodi;

  Grafo Gr(NumeroNodi);

  int NodoEntrante;
  int NodoUscente;

  for( int i = 0; i < NumeroArchi; i++)
    {
      cin >> NodoUscente >> NodoEntrante;
      Gr(NodoUscente, NodoEntrante, true);
    }

  if( CalcolaAdiacenti(Gr) )
    cout << "Almeno due adiacenti." << endl;
  else
    cout << "Non ci sono almeno due adiacenti." << endl;

  return 0;
}
