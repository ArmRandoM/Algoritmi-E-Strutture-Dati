// TabellaHash.h: the TabellaHash template class.
//
//////////////////////////////////////////////////////////////////////

#ifndef TABELLAHASH_H
#define TABELLAHASH_H

#include "Vettore.h"
#include "Lista.h"
#include "Iteratore.h"

typedef unsigned long int card; // tipo cardinale

template <class T>
class ChiaveHash
{
	public:
		ChiaveHash ( ) {}
		virtual card hash ( const T& a )=0;
		virtual bool equivalenti ( const T& a1, const T& a2 )=0;
};

//NB è richiesto che sia definito correttamente l'operatore == per T
template <class T>
class TabellaHash
{
	protected:
		typedef Lista<T> listaElementi;
		Vettore<listaElementi> tabella;
		card nElementi; //numero elementi
		ChiaveHash<T>& ch;

	public:
		TabellaHash( card iMax, ChiaveHash<T>& vch): tabella(1,iMax), nElementi(0), ch(vch) {};

		~TabellaHash() {
            for ( card i = 1; i <= nCelle(); i++ )
                tabella[i].svuota();
        };

		card nCelle() const {
            return tabella.n();
        };

		bool ins( T& a ) {
            card i = (ch.hash(a) % nCelle())+1;

            if ( cerca(a)==false ) {
                tabella[i].addInCoda(a); nElementi++;
                return true;
                }
            else
                return false;
        };

		bool canc( const T& a ) {
            card i = (ch.hash(a) % nCelle())+1;
            Iteratore<T> it(tabella[i]);
            bool trovato=false;
            it.vaiInTesta();
            while (!it.isNull() && !trovato)
                if (ch.equivalenti(it.getCurrentValue(),a))
                    trovato=true;
                else
                    it.moveNext();
            if ( trovato )
            {
                it.cancellaCorrente(); nElementi--;
                return true;
            }
            else
                return false;
        };

		void svuota() {
            for ( card i = 1; i <= nCelle(); i++ )
            tabella[i].svuota();  //funzione che cancella tutti i nodi nella lista
            nElementi = 0;
        };

		card n() const { return nElementi; };

		bool cerca ( T& a ) {
            card i = (ch.hash(a) % nCelle())+1;
            Iteratore<T> it(tabella[i]);
            bool trovato=false;
            it.VaiInTesta();
            while (!it.isNull() && !trovato)
                if (ch.equivalenti(it.getCurrentValue(),a)) {
                    a=it.getCurrentValue();
                    trovato=true;
                }
                else
                    it.MoveNext();
            return trovato;
        };
};

#endif




