#include <sstream>
#include <iostream>
#include <string>
#include "AlberoB.h"

using namespace std;

AlberoB<int> ricercaDFS( AlberoB<int> Albero_Binario, int valore )
	{
		AlberoB<int> AB;

		if( Albero_Binario.nullo())
			return Albero_Binario;

		if(Albero_Binario.radice() == valore)
				return Albero_Binario;
		else
			{
				AB = ricercaPerLivelli(Albero_Binario.figlio(SIN), valore);
				if( !AB.nullo())
					return AB;
				AB = ricercaPerLivelli(Albero_Binario.figlio(DES), valore);
				if( !AB.nullo())
					return AB;
			}
	}

void somma_figli( AlberoB<int> Albero_Binario, int &valore, bool &radice)
{

	if( !Albero_Binario.nullo())
		{
			if( !radice)
				{
					valore += Albero_Binario.radice();
					somma_figli( Albero_Binario.figlio(SIN), valore, radice);
					somma_figli( Albero_Binario.figlio(DES), valore, radice);
				}
			else
				{
					radice = false;
					somma_figli( Albero_Binario.figlio(SIN), valore, radice);
					somma_figli( Albero_Binario.figlio(DES), valore, radice);
				}
		}
}

// void stampaDFS( AlberoB<int> Albero_Binario )
// 	{
// 		int sommaFigli = 0;
// 		bool radice = true;
// 		if( !(Albero_Binario.nullo()))
// 			{
// 				somma_figli( Albero_Binario, sommaFigli, radice);
// 				cout << Albero_Binario.radice() << "->" << sommaFigli << endl;
// 				if(!(Albero_Binario.foglia()))
// 					{
// 						stampa(Albero_Binario.figlio(SIN));
// 						stampa(Albero_Binario.figlio(DES));
// 					}
// 			}
// 	}

void stampaPerLivelli( AlberoB<int> Albero_Binario, bool prima_volta)
	{
		int sommaFigli = 0;
		bool radice = true;

		if( !(Albero_Binario.nullo()))
			{
				if( prima_volta == true )
					{
						prima_volta = false;
						somma_figli( Albero_Binario, sommaFigli, radice);
						cout << Albero_Binario.radice() << "->" << sommaFigli << endl;
					}

				if(!(Albero_Binario.foglia()))
					{
						if( !Albero_Binario.figlio(SIN).nullo())
							{
								sommaFigli = 0;
								radice = true;
								somma_figli( Albero_Binario.figlio(SIN), sommaFigli, radice);
								cout << Albero_Binario.figlio(SIN).radice() << "->" << sommaFigli << endl;
							}
						if( !Albero_Binario.figlio(DES).nullo())
							{
								sommaFigli = 0;
								radice = true;
								somma_figli( Albero_Binario.figlio(DES), sommaFigli, radice);
								cout << Albero_Binario.figlio(DES).radice() << "->" << sommaFigli << endl;
							}

						stampa(Albero_Binario.figlio(SIN), prima_volta);
						stampa(Albero_Binario.figlio(DES), prima_volta);
					}
			}
	}

int main()
{
	bool prima_volta = true;
	bool radice = true;
  string comando;
  int valore1;
  int valore2;
  AlberoB<int> Albero_Binario(0);
  char Direzione;

  while(getline( cin, comando))
    {
      if( comando == "-1")
        break;

      //definizione del valore della radice
      if( radice )
        {
          stringstream primo_valore( comando );
          primo_valore >> valore1;
          Albero_Binario.modRadice(valore1);
          radice = false;
          continue;
        }

      //definizione del valore dei figli e delle posizioni
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
   	  if (Direzione == 's')
   	 		Puntatore_Temp.insFiglio(SIN, Puntatore_Figlio);
   	 	else
    		Puntatore_Temp.insFiglio(DES, Puntatore_Figlio);
    }

  stampaPerLivelli(Albero_Binario, prima_volta);

	return 0;
}
