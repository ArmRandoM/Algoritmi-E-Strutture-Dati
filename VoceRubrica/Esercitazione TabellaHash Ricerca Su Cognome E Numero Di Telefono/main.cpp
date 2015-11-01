#include <iostream>
#include <vector>
#include "VoceRubrica.h"
#include "TabellaHash.h"
#include <string>
#include <limits>

using namespace std;

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

class HashVoceRubrica1 : public ChiaveHash<VoceRubrica>
{
  public:

    card Hash( const VoceRubrica& vr )
      {
        return string2hash( vr.getCognome() );
      }

    bool Equivalenti(const VoceRubrica& vr1, const VoceRubrica& vr2)
    {
        return ( vr1.getCognome() == vr2.getCognome() );
    }
};

class HashVoceRubrica2 : public ChiaveHash<VoceRubrica>
{
  public:

    card Hash( const VoceRubrica& vr )
      {
        return string2hash( vr.getNumeroTelefonico() );
      }

    bool Equivalenti(const VoceRubrica& vr1, const VoceRubrica& vr2)
    {
        return ( vr1.getNumeroTelefonico() == vr2.getNumeroTelefonico() );
    }
};

// main di esempio: cariamento di 10 Voci Rubrica ( contatti ) e ricerca per Cognome
int main()
{
    HashVoceRubrica1 hCognome;
		HashVoceRubrica2 hNumero;
		VoceRubrica ContattoDaCercare;
    string CognomeDaCercare;
		string NumeroDaCercare;

    //tabella hash di VoceRubrica con l'utilizzo della chiave hash sul Cognome
    TabellaHash<VoceRubrica> Rubrica1( hCognome, 100);
		TabellaHash<VoceRubrica> Rubrica2( hNumero, 100);
		VoceRubrica vr;

    for(int i = 1; i<= 10; i++)
      {
        cin >> vr; //operatore >> ridefinito in VoceRubrica
        Rubrica1.Ins(vr); //inserimento nella tabella hash Rubrica con hashing per cognome
				Rubrica2.Ins(vr); //inserimento nella tabella hash Rubrica con hashing per numero di telefono
      }

    cout << endl;
		cout << "===============================" << endl;
    cout << "Cognome del contatto da cercare:" << endl;
    cin >> CognomeDaCercare;
		cout << "Numero di telefono del contatto da cercare:" << endl;
		cin >> NumeroDaCercare;
		cout << "===============================" << endl;
    ContattoDaCercare.setCognome( CognomeDaCercare );
		ContattoDaCercare.setNumeroTelefonico( NumeroDaCercare );

    if (Rubrica1.Cerca(ContattoDaCercare)) //ricerca e assegnamento del contatto trovato nella Rubrica
      	{
					cout << endl << endl;
					cout << "===============================" << endl;
					cout << "Specifiche Contatto Cercato" << endl;
					cout << ContattoDaCercare;
				}
    else if(Rubrica2.Cerca( ContattoDaCercare))
				{
					cout << endl << endl;
					cout << "===============================" << endl;
					cout << "Specifiche Contatto Cercato" << endl;
					cout << ContattoDaCercare;

				}
			else
    		cout << endl << "Non trovato!!!" << endl << endl;

		//Rubrica2.Stampa();

    return 0;
}
