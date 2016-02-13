/*
 * Grafo.h
 *
 *  Created on: 9-dic-2010
 */
 #include <vector>
 #include <stdio.h>
 #include <limits.h>
 using namespace std;

 enum passaggio { SABBIA = 0, TESORO, INIZIO };

 class Coordinata
 {
   private:
     int x;
     int y;
     passaggio p;

   public:
     Coordinata()
       {
         x = 0;
         y = 0;
         p = SABBIA;
       }
     Coordinata(int i,int j, passaggio Pass)
       {
         x = i;
         y = j;
         p = Pass;
       }

     void setX( int X) { x = X;}
     void setY( int Y) { y = Y;}
     void setPassaggio(passaggio Pass ) { p = Pass;}

     int getX() const{return x;}
     int getY() const{return y;}
     int getPassaggio() const{return p;}

     void stampa()
       {
         cout << "(" << x << " , " << y << ")";
         switch(p)
           {
             case SABBIA:
                 cout << "SABBIA" << endl;
                 break;
             case TESORO:
                 cout << "TESORO" << endl;
                 break;
             case INIZIO:
                 cout << "INIZIO" << endl;
                 break;
             default:
                 break;
           }
       }
 };


#ifndef GRAFO_H_
#define GRAFO_H_

#include "Matrice.h"

class Grafo
{	protected:
	int vn, vm; // numero di nodi e numero di archi
	Matrice<int> archi; // matrice di adiacenza

	void init( int nNo ) //	inizializzazione
	{	archi.init (1,nNo,1,nNo);
		vn=nNo;
		svuota();
		vm=0;
	}

public:
//	FUNZIONI NON COSTANTI
	Grafo( int nNo )
	{
		assert(nNo>=1);
		init(nNo);
	}
//	inserisce o elimina (i,j) a secondo se b � true o false
	void operator()( int i, int j, bool b)
	{	assert ( i>=1 && i<=n() && j>=1 && j<=n() );
		bool esistearco = archi(i,j);
		if ( (!esistearco && b) || (esistearco && !b) )
		{
      archi(i,j) = 1;
			if ( b )
				vm++;
			else
				vm--;
		}
	}

//	elimina tutti gli archi
	void svuota ()
	{
		for ( int i = 1; i <= archi.n(); i++ )
			for ( int j = 1; j <= archi.n(); j++ )
				archi(i,j) = false;
		vm = 0;
	}

//	assegnamento
	Grafo& operator= ( const Grafo& GC )
	{	if ( this == &GC ) 	return *this;
		vn = GC.n();
		init( GC.n() );
		for ( int i = 1; i <= archi.n(); i++ )
			for ( int j = 1; j <= archi.n(); j++ )
				if (GC(i,j))
					archi(i,j) = true;
				else
					archi(i,j) = false;
		return *this;
	}
//	FUNZIONI COSTANTI
	int n() const {return vn;}; // restituisce il numero di nodi
	int m() const {return vm;} // restituisce il numero di archi

//	restituisce vero o falso se l'arco (i,j) � nel grafo o meno
	bool operator() ( int i, int j ) const
	{	assert ( i >=1 && i<=n() && j>=1 && j<=n() );
		return archi(i,j);
	}

  void stampa()
		{
			for( int i = 1; i <= archi.n(); i++)
				{
					for( int j = 1; j <= archi.n(); j++)
						{
							if( archi(i,j) == true )
							 	cout << i << "->" << j << endl;
						}
				}
			cout << endl << endl;

			for( int i = 1; i <= archi.n(); i++)
				{
					for( int j = 1; j <= archi.n(); j++)
						{
							if( archi(i,j) == true )
							 	cout << "1" << " ";
							else
							 	cout << "0" << " ";
						}

					cout << endl;
				}
		}

  int Distanza_Minima_Nodo( vector<int> Distanze, vector<bool> Visitati)
    {
      int PercorsoMinimo = INT_MAX;
      int MinIndex;

      for( unsigned int i = 0; i < Distanze.size(); i++ )
        {
          if( Visitati[i] == false && Distanze[i] <= PercorsoMinimo)
            {
              PercorsoMinimo = Distanze[i];
              MinIndex = i;
            }
        }

      return MinIndex;
    }

  void Dijkstra( int NodoIniziale,int z, vector<Coordinata> &c, int **CamminiCalcolati)
    {
      int indice = 0;

      vector<int> Distanze(c.size());

      vector<bool> Visitati(c.size());

      for( unsigned int i = 0; i < c.size(); i++ )
        Distanze[i] = INT_MAX;

      Distanze[NodoIniziale] = 0;

      for( unsigned int i = 0; i < c.size(); i++ )
        {
          int NodoCorrente = Distanza_Minima_Nodo(Distanze, Visitati);

          Visitati[NodoCorrente] = true;

          for( unsigned int j = 0; j < c.size(); j++)
            {
              if( !Visitati[j] && archi(NodoCorrente+1,j+1) && Distanze[NodoCorrente] != INT_MAX && Distanze[NodoCorrente] + archi(NodoCorrente+1, j+1) < Distanze[j])
                Distanze[j] = Distanze[NodoCorrente] + archi(NodoCorrente+1,j+1);
            }
        }

      for( unsigned int i = 0; i < Distanze.size(); i++ )
        {
          if( c[i].getPassaggio() == TESORO ||  c[i].getPassaggio() == INIZIO )
            {
              CamminiCalcolati[z][indice] = Distanze[i];
              indice++;
            }
        }
    }
};

#endif /* GRAFO_H_ */
