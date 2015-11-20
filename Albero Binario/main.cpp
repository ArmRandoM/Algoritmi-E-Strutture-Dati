#include <sstream>
#include <iostream>
#include <string>
#include <list>
#include "AlberoB.h"

using namespace std;

AlberoB<int> ricercaDFS( AlberoB<int> Albero_Binario, int &valore )
	{
		if( !Albero_Binario.nullo())
			{
				if(Albero_Binario.radice() == valore)
					return Albero_Binario;
				else
					{
						AlberoB<int> AB = ricercaDFS(Albero_Binario.figlio(SIN), valore);
						if( !AB.nullo())
							return AB;

				 		return ricercaDFS(Albero_Binario.figlio(DES), valore);
					}
			}
		return Albero_Binario;
	}

void somma_figli( AlberoB<int> Albero_Binario, int &valore)
{
	if( !Albero_Binario.nullo())
		{
				valore += Albero_Binario.radice();
				somma_figli( Albero_Binario.figlio(SIN), valore);
				somma_figli( Albero_Binario.figlio(DES), valore);
		}
}

void stampaPerLivelli( AlberoB<int> Albero_Binario )
	{
		AlberoB<int> tmp;
		int sommaFiglioDestro = 0;
		int sommaFiglioSinistro = 0;

		if( !Albero_Binario.nullo())
			{
				list<AlberoB<int> > Temp;
				Temp.push_back(Albero_Binario);

				while( !Temp.empty())
					{
						tmp = Temp.front();
						Temp.pop_front();

						if( !tmp.foglia())
							{
								somma_figli( tmp.figlio(DES), sommaFiglioDestro);
								somma_figli( tmp.figlio(SIN), sommaFiglioSinistro);
							}

						cout << tmp.radice() << " -> " << sommaFiglioDestro + sommaFiglioSinistro << endl;
						sommaFiglioDestro = 0;
						sommaFiglioSinistro = 0;

						if( !tmp.figlio(SIN).nullo())
							Temp.push_back( tmp.figlio(SIN));

						if( !tmp.figlio(DES).nullo())
							Temp.push_back( tmp.figlio(DES));
					}
			}
	}

int main()
{

	bool radice = true;
  string comando;
  int valore1;
  int valore2;
	int numero_nodi = 0;
  AlberoB<int> Albero_Binario(0);
  char Direzione;

  while(getline( cin, comando))
     {
       if( comando == "-1")
         break;
       if( radice )
        {
          stringstream cmd(comando);
					cmd >> valore1;
          Albero_Binario.modRadice(valore1);
          radice = false;
          continue;
				}

		  size_t Posizione_Due_Punti = comando.find(':');
  	  size_t Posizione_Dello_Spazio = comando.find(' ');
      istringstream figlio(comando.substr(0, Posizione_Due_Punti));	//prendo il valore del figlio
			figlio >> valore1;
	    istringstream padre(comando.substr(Posizione_Due_Punti + 1, Posizione_Dello_Spazio - Posizione_Due_Punti)); 	// prendo il valore del padre
	 		padre >> valore2;
	    Direzione = comando.at(Posizione_Dello_Spazio + 1); // prendo la direzione

	    AlberoB<int> Puntatore_Temp = ricercaDFS(Albero_Binario, valore2);

	 	  if (Puntatore_Temp.nullo())
	     {
	 		     cout << "Errore! Nodo padre inesistente" << endl;
	 		     return 1;
	 	   }


			AlberoB<int> Puntatore_Figlio(valore1);
   	  if(Direzione == 's')
				Puntatore_Temp.insFiglio(SIN, Puntatore_Figlio);
			else
				Puntatore_Temp.insFiglio(DES, Puntatore_Figlio);
    }

  stampaPerLivelli(Albero_Binario);

	return 0;
}
