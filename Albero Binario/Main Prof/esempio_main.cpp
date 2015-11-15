#include <string>
#include <sstream>
#include <iostream>
#include "AlberoB.h"
using namespace std;

AlberoB<int> ricercaPerLivelli( AlberoB<int> Albero_Binario, int valore )
	{
		AlberoB<int> AB;

		cout << "sono rientrato" << endl;
		if( Albero_Binario.nullo())
			return Albero_Binario;

		cout << Albero_Binario.radice() << endl;
		if(Albero_Binario.radice() == valore)
			{
				cout << Albero_Binario.radice() << "==" << valore << endl;
				return Albero_Binario;
			}
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

void stampa( AlberoB<int> Albero_Binario )
	{
		if( !(Albero_Binario.nullo()))
			{
				cout << Albero_Binario.radice();
				cout << endl;
				if(!(Albero_Binario.foglia()))
					{
						cout << "sinistro ";
						stampa(Albero_Binario.figlio(SIN));
						cout << "destro ";
						stampa(Albero_Binario.figlio(DES));
					}
			}
		else
			cout << "Albero Vuoto" << endl;
	}

int main()
{
	string line;			// linea corrente nello stream
	int v, vp;				// valore, valore padre
	char d;					// direzione
	bool radice = true;
	AlberoB<int> A(0);
	while (getline(cin, line))
		{
			if (line == "-1")
				{
					break;
				}

			// prima riga
			if (radice)
				{
					stringstream strr(line);
					strr >> v;
					A.modRadice(v);
					radice = false;
					continue;
				}

			// righe successive
			size_t duePuntiPos = line.find(':');											// posizione :
			size_t spazioPos = line.find(' ');												// posizione " "
			istringstream str(line.substr(0, duePuntiPos));									// estrapolo il primo valore
			str >> v;
			istringstream strvp(line.substr(duePuntiPos + 1, spazioPos - duePuntiPos)); 	// estrapolo il secondo valore
			strvp >> vp;
			d = line.at(spazioPos + 1);														// estrapolo la direzione

			AlberoB<int> pTemp = ricercaPerLivelli(A, vp);
			stampa(pTemp);
			if (pTemp.nullo())
    		{
					cout << "Errore! Nodo padre inesistente" << endl;
					return 1;
				}

			AlberoB<int> pFiglio(v);
			if (d == 's')
				pTemp.insFiglio(SIN, pFiglio);
			else
				pTemp.insFiglio(DES, pFiglio);
		}

	stampa(A);

	return 0;

}
