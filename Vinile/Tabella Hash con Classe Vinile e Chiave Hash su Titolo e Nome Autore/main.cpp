#include "Vinile.h"
#include "TabellaHash.h"
#include <limits>
#include <fstream>

//funzione che calcola un numero che identifica univocamente la stringa

card string2hash( const string s )
{
	long int nMax = numeric_limits<long int>::max();
	card C = 0;
	for ( card i = 1; i <= s.size(); i++ )
		C = (C + s[i]) % nMax;
	return C;
}

// Chiave Hash di VoceRubrica calcolata sul Cognome dei singoli Contatti
// definizione delle funzioni hash e equivalenti

class HashVinile1 : public ChiaveHash<Vinile>
{
  public:

    card Hash( const Vinile& v )
      {
        return string2hash( v.getTitolo() );
      }

    bool Equivalenti(const Vinile& v1, const Vinile& v2)
    {
        return ( v1.getTitolo() == v2.getTitolo() );
    }
};


class HashVinile2 : public ChiaveHash<Vinile>
{
  public:

    card Hash( const Vinile& v )
      {
        return string2hash( v.getNomeArtista() );
      }

    bool Equivalenti(const Vinile& v1, const Vinile& v2)
    {
        return ( v1.getNomeArtista() == v2.getNomeArtista() );
    }
};

// main di esempio: cariamento di 10 Voci Rubrica ( contatti ) e ricerca per Cognome
int main()
{
    HashVinile1 hTitolo;
		HashVinile2 hNomeArtista;
		Vinile VinileDaCercare;
    string TitoloDaCercare;
		string NomeArtistaDaCercare;
		string SpecificheVinile;
		string Dato;
		int i = 1;

    //tabella hash di VoceRubrica con l'utilizzo della chiave hash sul Cognome
    TabellaHash<Vinile> RaccoltaVinili1( hTitolo, 100);
		TabellaHash<Vinile> RaccoltaVinili2( hNomeArtista, 100);
		Vinile v;

		ifstream SpecificheVinili ("Testo.txt");

		if( SpecificheVinili.is_open())
			{
				while( getline(SpecificheVinili, SpecificheVinile, ';'))
					{
							if( i == 1 )
							 	v.setTitolo(SpecificheVinile );
							else if( i == 2 )
										v.setNomeArtista( SpecificheVinile );
									 else if( i == 3 )
									 				v.setAnno( SpecificheVinile );
												else if( i == 4 )
															{
																i = 0;
												  			v.setGenere( SpecificheVinile );
																RaccoltaVinili1.Ins( v );
											 				 	RaccoltaVinili2.Ins( v );
															}
						 i++;
					}
			}

    cout << endl;
		cout << "===============================" << endl;
    cout << "Titolo Vinile Da Cercare:" << endl;
    getline( cin, TitoloDaCercare );
		cout << "Nome Dell' Artista Del Vinile:" << endl;
		getline( cin, NomeArtistaDaCercare );
		cout << "===============================" << endl;
    VinileDaCercare.setTitolo( TitoloDaCercare );
		VinileDaCercare.setNomeArtista( NomeArtistaDaCercare );

    if (RaccoltaVinili1.Cerca(VinileDaCercare)) //ricerca e assegnamento del contatto trovato nella Rubrica
      	{
					cout << endl << endl;
					cout << "===============================" << endl;
					cout << "Specifiche Vinile Cercato" << endl;
					cout << VinileDaCercare;
				}
    else if(RaccoltaVinili2.Cerca(VinileDaCercare))
				{
					cout << endl << endl;
					cout << "===============================" << endl;
					cout << "Specifiche Vinile Cercato" << endl;
					cout << VinileDaCercare;

				}
			else
    		cout << endl << "Non trovato!!!" << endl << endl;

		//RaccoltaVinili2.Stampa();
		//RaccoltaVinili1.Stampa();

    return 0;
}
