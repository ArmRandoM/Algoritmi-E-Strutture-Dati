//////////////////////////////////////////////////////////////////////
// AlberoB.h: the AlberoB template class.
// Corso:	Algoritmi e Strutture Dati
// Informatica @ Università della Calabria
//////////////////////////////////////////////////////////////////////

#ifndef ALBEROB_H
#define ALBEROB_H

enum Direzione { SIN=0, DES=1 };

template <class T>
struct SNodo{
	T vinfo; // parte informativa
	SNodo *ppadre, *pfiglio[2]; // puntatori al padre e ai due figli
	SNodo( const T& inf ): vinfo(inf)
	{
		ppadre = 0;
		pfiglio[SIN] = 0;
		pfiglio[DES] = 0;
	}
	~SNodo( ) {delete pfiglio[SIN]; delete pfiglio[DES];}
};

template <class T>
class AlberoB
{
protected:
	SNodo<T>* pradice; // puntatore alla radice
public:

	//	FUNZIONI NON COSTANTI
    AlberoB () : pradice(0) {};

    AlberoB ( const T& a) {
        pradice = new SNodo<T>(a);
    };

	//	inserisce l'albero AC come figlio d = SIN/DES
    void insFiglio ( Direzione d, AlberoB& AC ) {
        if( AC.pradice != 0)
				 {
            pradice->pfiglio[d]=AC.pradice;
            AC.pradice->ppadre=pradice;
        }
    };

	// 	estrae il figlio d = SIN/DES
    AlberoB<T> estraiFiglio ( Direzione d ) {
        AlberoB<T> A = figlio(d);
        A.pradice->ppadre=0;
        pradice->pfiglio[d] = 0;
        return A;
    };

    // modifica il contenuto informativo della radice
    void modRadice ( const T& a ) {
        pradice->vinfo = a;
    };

	// svuota l'albero cancellandone tutti i nodi
    void svuota() { delete pradice; pradice = 0; };

	// svuota l'albero ma senza cancellare i nodi
    void annulla() { pradice = 0; };

    //	FUNZIONI COSTANTI
	bool nullo() const {	if( pradice == 0)
		 											return true;
												return false;};

	// restituisce una copia dell'albero
    AlberoB<T> copia () const {
        if ( nullo() ) return AlberoB<T>();
        AlberoB<T> AC(radice());
        AlberoB<T> fs = figlio(SIN).copia();
        AlberoB<T> fd = figlio(DES).copia();
        AC.insFiglio(SIN,fs);
        AC.insFiglio(DES,fd);
        return AC;
    } ;

	//	mostra l'info della radice
    const T& radice () const {
        return pradice->vinfo;
    };

	// restituisce true se la radice è nodo foglia
    bool foglia () const
			{
				if((!this -> nullo()) && this -> figlio(SIN).nullo() && this -> figlio(DES).nullo())
        	return true;
				return false;
    	};

	// restituisce il figlio d = SIN/DES
    AlberoB<T> figlio ( Direzione d ) const {
        AlberoB<T> AC;
        AC.pradice = pradice->pfiglio[d];
        return AC;
    };

	//	restituisce il padre eventualmente nullo
    AlberoB<T> padre () const {
        AlberoB<T> AC;
        AC.pradice = pradice->ppadre;
        return AC;
    };
};

#endif
