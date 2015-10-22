#include "Dipendente.h"
#include "include/TabellaHash.h"
#include "include/Vettore.h"
#include "include/Lista.h"
#include "include/Nodo.h"
#include "include/Iteratore.h"

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

// Chiave Hash di Dipendente calcolata sul nome
// definizione delle funzioni hash e equivalenti
class HashDipN : public ChiaveHash<Dipendente>
{   public:
    card hash( const Dipendente& d ) {return string2hash(d.nome);}
    bool equivalenti(const Dipendente& d1, const Dipendente& d2)
    { return ( d1.nome == d2.nome );}
};

// main di esempio: cariamento di 4 dipendenti e ricerca per nome
int main(){
    HashDipN hdNome;
    //tabella hash (length 100 ) di dipendente con l'utilizzo della chiave hash sul nome
    TabellaHash<Dipendente> tabDip1(100,hdNome);
    Dipendente d1;
    for(int i = 1; i<=4; i++){
        cin>>d1; //operatore >> ridefinito in Dipendente!!
        tabDip1.ins(d1); //inserimento nella tabella hash
    }


    Dipendente daCercare;
    cout<<endl;
    cout<<"Nome del dipendente da cercare:"<<endl;
    char buff[20]; //assumiamo lunghezza massima del nome di 20 caratteri
    cin>>buff;
    daCercare.nome=buff;
    if (tabDip1.cerca(daCercare)){ //ricerca e assegnamento del dipendente trovato nella variabile daCercare
    	cout<<"Scheda del dipendente cercato:"<<endl;
        cout<<daCercare;
    }
    else
    	cout<<"Non trovato!!!"<<endl;
}
