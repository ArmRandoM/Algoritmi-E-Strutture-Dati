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

class HashVoceRubrica : public ChiaveHash<VoceRubrica>
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

// main di esempio: cariamento di 10 Voci Rubrica ( contatti ) e ricerca per Cognome
int main()
{
    HashVoceRubrica hCognome;
		VoceRubrica ContattoDaCercare;
    string CognomeDaCercare;

    //tabella hash di VoceRubrica con l'utilizzo della chiave hash sul Cognome
    TabellaHash<VoceRubrica> Rubrica( hCognome, 100);
    VoceRubrica vr;

    for(int i = 1; i<=4; i++)
      {
        cin >> vr; //operatore >> ridefinito in VoceRubrica
        Rubrica.Ins(vr); //inserimento nella tabella hash
      }

    cout << endl;
    cout << "Cognome del contatto da cercare:" << endl;
    cin >> CognomeDaCercare;
    ContattoDaCercare.setCognome( CognomeDaCercare );

    if ( Rubrica.Cerca(ContattoDaCercare) )//ricerca e assegnamento del contatto trovato nella variabile Rubrica
      	{
					cout << endl << endl;
					cout << "===============================" << endl;
					cout << "Specifiche Contatto Cercato" << endl;
					cout << ContattoDaCercare;
				}
    else
    	cout << endl << "Non trovato!!!" << endl << endl;

		//Rubrica.Stampa();

    return 0;
}
