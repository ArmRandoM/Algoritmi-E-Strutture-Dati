#include <sstream>
#include <iostream>
#include <string>
#include <queue>
#include "AlberoB.h"

using namespace std;

AlberoB<int> ricerca_per_livelli( AlberoB<int> &Albero_Binario, int &valore )
{
	if( Albero_Binario.radice() == valore)
		return Albero_Binario;
	else
		{
			AlberoB<int> tmp;
			queue<AlberoB<int> > Temp;
			Temp.push(Albero_Binario);

			while( !Temp.empty())
				{
					tmp = Temp.front();
					Temp.pop();

					if( !tmp.figlio(SIN).nullo())
						{
							if( tmp.figlio(SIN).radice() == valore )
								return tmp.figlio(SIN);

							Temp.push( tmp.figlio(SIN));
						}

					if( !tmp.figlio(DES).nullo())
						{
							if( tmp.figlio(DES).radice() == valore )
								return tmp.figlio(DES);

							Temp.push( tmp.figlio(DES));
						}
				}
		}
	return Albero_Binario;
}

void somma_figli_per_livelli( AlberoB<int> &Albero_Binario, int &valore)
{
	AlberoB<int> tmp;
	queue<AlberoB<int> > Temp;
	Temp.push(Albero_Binario);

	while( !Temp.empty())
		{
			tmp = Temp.front();
			Temp.pop();

			if( !tmp.figlio(SIN).nullo())
				{
					valore += tmp.figlio(SIN).radice();
					Temp.push( tmp.figlio(SIN));
				}

			if( !tmp.figlio(DES).nullo())
				{
					valore += tmp.figlio(DES).radice();
					Temp.push( tmp.figlio(DES));
				}
		}
}

void stampaPerLivelli( AlberoB<int> &Albero_Binario )
{
	if( !Albero_Binario.nullo())
		{
			queue<AlberoB<int> > Temp;
			Temp.push(Albero_Binario);
			AlberoB<int> tmp;
			int somma = 0;

			while( !Temp.empty())
				{
					tmp = Temp.front();
					Temp.pop();

					somma_figli_per_livelli( tmp, somma);

					cout << tmp.radice() << " -> " << somma << "\n";

					somma = 0;

					if( !tmp.figlio(SIN).nullo())
						Temp.push( tmp.figlio(SIN));

					if( !tmp.figlio(DES).nullo())
						Temp.push( tmp.figlio(DES));
				}
		}
}

int main()
{
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

			AlberoB<int> Puntatore_Temp = ricerca_per_livelli(Albero_Binario, valore2);

			if (Puntatore_Temp.nullo())
				{
					cout << "Errore! Nodo padre inesistente\n";
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
