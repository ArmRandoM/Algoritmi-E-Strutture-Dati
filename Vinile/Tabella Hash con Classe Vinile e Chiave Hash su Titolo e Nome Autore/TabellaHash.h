#ifndef TABELLA_HASH
#define TABELLA_HASH

#include <iostream>
#include <list>
#include <vector>

using namespace std;

typedef unsigned long int card; //tipo cardinale

//Definizione della classe astratta chiave hash

template <class T>

class ChiaveHash
{
  public:

    ChiaveHash(){} //costruttore di default per la classe ChiaveHash

    virtual card Hash( const T&  a ) = 0; // funzione hash virtuale pura

    virtual bool Equivalenti ( const T& a1, const T& a2 ) = 0; /*funzione virutale pura che controlla se due
                                                                 valori sono uguali*/
};

//Definizione della classe Tabella hash

template<class T>

class TabellaHash
{
  protected:

    typedef list<T> ListaElementi;  //Lista degli elementi che dovremo inserire nel vettore
    vector<ListaElementi> Tabella;  /* Vettore le cui celle contengono altre liste il tutto andrà a formare
                                       la nostra Tabella Hash*/
    ChiaveHash<T>& ch;               //Chiave che andrà a identificare univocamente una lista di una particolare cella

  public:

    TabellaHash();

    TabellaHash( ChiaveHash<T> & vch, int num) : ch( vch )
      {
        Tabella.resize( num );
      }  // costruttore della classe TabellaHash

    ~TabellaHash()  //Distruttore della classe TabellaHash che andrà a pulire l'intero vettore di liste
      {
          Tabella.clear();
      }

    bool Ins( T& a )  //Funzione che controlla l'inserimento di un dato valore nelle liste contenute nel vettore
      {
        card i = ( ch.Hash(a) % (Tabella.size()));

        if( Cerca(a) == false )
          {
            Tabella[i].push_back( a );
            return true;
          }
        else
          return false;

      }

    bool Canc( T& a) //Funzione che cerca un dato valore all'interno delle liste contenute nel vettore
      {
        card i = ( ch.Hash(a) % (Tabella.size()));
        typename list<T>::iterator it = Tabella[i].begin();
        bool trovato = false;

        while( it != Tabella[i].end() && !trovato)
          {
            if( ch.Equivalenti( *it, a ))
              {
                Tabella.erase(it);
                trovato = true;
              }
          }

        return trovato;
      }

    bool Cerca( T& a) //Funzione che cerca un dato valore all'interno delle liste contenute nel vettore
      {

        card i = ( ch.Hash(a) % (Tabella.size()));
        typename list<T>::iterator it = Tabella[i].begin();
        bool trovato = false;

        while( it != Tabella[i].end() && !trovato )
          {
            if( ch.Equivalenti( *it, a ))
              {
                a = *it;
                trovato = true;
              }
            else it++;
          }

        return trovato;
      }

    void Stampa()
      {
        cout << "Dimensione Tabella Hash" << endl;
        cout << Tabella.size() << endl;
        for( int i = 0; i < Tabella.size(); i++ )
          {
            cout << "Indice " << i << endl;
            for( typename list<T>::iterator it = Tabella[i].begin(); it != Tabella[i].end(); it++)
              cout << *it << endl << endl;
          }
      }
};

#endif
