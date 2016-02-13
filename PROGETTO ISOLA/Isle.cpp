#include <iostream>
#include <vector>
#include "Grafo.h"

using namespace std;

void InitIsle( char **Isle, Coordinata &Inizio, int n, int m)
{
  char simbolo;

  for( int i = 0; i < n; ++i )
    {
      for( int j = 0; j < m; ++j )
        {
          cin >> simbolo;

          if( simbolo == 'S')
            {
              Inizio.setX(i);
              Inizio.setY(j);
            }

          Isle[i][j] = simbolo;
        }
    }
}

bool nessuna_torre_vicina( char **Isle, int i, int j, int n, int m)
{
  if( j+1 < m)
    {
      if(Isle[i][j+1] == '!')
        return false;
    }

  if( i+1 < n)
    {
      if(Isle[i+1][j] == '!')
        return false;
    }

  if( i > 0)
    {
      if(Isle[i-1][j] == '!')
        return false;
    }

  if( j > 0)
    {
      if(Isle[i][j-1] == '!')
        return false;
    }

  if( i+1 < n && j+1 < m)
    {
      if(Isle[i+1][j+1] == '!')
        return false;
    }

  if( i+1 < n && j > 0)
    {
      if(Isle[i+1][j-1] == '!')
        return false;
    }

  if( i > 0 && j+1 < m)
    {
      if(Isle[i-1][j+1] == '!')
        return false;
    }
  if( i > 0 && j > 0)
    {
      if(Isle[i-1][j-1] == '!')
        return false;
    }

  return true;
}

void InitCoordinateETesori( char **Isle, vector<Coordinata>& c, vector<int>& TesoroInizio, int n, int m)
{
  for( int i = 0; i < n; ++i)
    {
      for( int j = 0; j < m; ++j)
        {
          if( Isle[i][j] == '.' && nessuna_torre_vicina(Isle,i,j,n,m))
            {
              Coordinata passo(i,j,SABBIA);
              c.push_back( passo);
            }
          if( Isle[i][j] == '$')
            {
              Coordinata passo(i,j,TESORO);
              c.push_back( passo);
              TesoroInizio.push_back(c.size());
            }
        }
    }
}

void CreaGrafo( Grafo& Gr, vector<Coordinata>& c)
{
  for( unsigned int i = 0; i < c.size(); ++i)
    {
      for( unsigned int j = 0; j < c.size(); ++j)
        {
          if( c[j].getX() == c[i].getX() && ( c[j].getY() == (c[i].getY()+1)))
              Gr(i+1,j+1,true);
          if( c[j].getX() == c[i].getX() && ( c[j].getY() == (c[i].getY()-1)))
              Gr(i+1,j+1,true);
          if( c[j].getY() == c[i].getY() && ( c[j].getX() == (c[i].getX()+1)))
              Gr(i+1,j+1,true);
          if( c[j].getY() == c[i].getY() && ( c[j].getX() == (c[i].getX()-1)))
              Gr(i+1,j+1,true);
        }
    }
}

bool Trovato_Tutti_I_Tesori( vector<bool> &TesoriTrovati)
{
  for( unsigned int i = 0; i < TesoriTrovati.size(); ++i)
    {
      if( TesoriTrovati[i] == false)
        return false;
    }

  return true;
}

int Trova_Cammino_Minimo_Ottimo(int **CamminiCalcolati, int dim, int IndiceTesoroCorrente, int SommaParziale, int &CamminoOttimo, vector<bool> TesoriTrovati)
{
  if( SommaParziale >= CamminoOttimo)
    return 0;

  vector<bool> CopiaTesoriTrovati(TesoriTrovati.size());
  int CopiaSP;

  TesoriTrovati[IndiceTesoroCorrente] = true;

  for( unsigned int i = 0; i < TesoriTrovati.size(); ++i )
    CopiaTesoriTrovati[i] = TesoriTrovati[i];

  if( Trovato_Tutti_I_Tesori(TesoriTrovati) == false)
    {
       for( int i = 0; i < dim; ++i)
          {
            if( TesoriTrovati[i] == false && IndiceTesoroCorrente != i)
              {
                CopiaSP = SommaParziale + CamminiCalcolati[IndiceTesoroCorrente][i];
                TesoriTrovati[i] = true;
                Trova_Cammino_Minimo_Ottimo(CamminiCalcolati, dim, i, CopiaSP, CamminoOttimo, CopiaTesoriTrovati);
              }
          }
    }
  else
    {
      SommaParziale += CamminiCalcolati[0][IndiceTesoroCorrente];
      if(SommaParziale < CamminoOttimo)
        CamminoOttimo = SommaParziale;
    }

  return 0;
}

int main()
{
  string comando;
  vector<int> camminiOttimi;

  cin >> comando;
  if( comando != "-1")
    cin >> comando;

  while(comando != "-1")
   {
    int n, m;
    cin >> n >> m;

    int righe = n;
    int colonne = m;

    char **Isle = new char *[righe];
    for( int i = 0; i < righe; i++)
      Isle[i] = new char [colonne];

    vector<Coordinata> coordinate;
    vector<int> TesoroInizio;
    int CamminoMinimoOttimo = INT_MAX;
    int SommaParziale = 0;

    Coordinata Inizio(0,0,INIZIO);

    InitIsle(Isle, Inizio, righe, colonne);

    coordinate.push_back(Inizio);
    TesoroInizio.push_back(coordinate.size());

    InitCoordinateETesori( Isle, coordinate, TesoroInizio, righe, colonne);
    vector<bool> TesoriTrovati(TesoroInizio.size());

    Grafo Gr( coordinate.size());
    CreaGrafo( Gr, coordinate);

    int **cammini = new int *[TesoroInizio.size()];
    for( unsigned int i = 0; i < TesoroInizio.size(); ++i)
      cammini[i] = new int [TesoroInizio.size()];

    for(unsigned int i = 0; i < TesoroInizio.size(); ++i)
      Gr.Dijkstra( TesoroInizio[i]-1, i, coordinate, cammini);

    Trova_Cammino_Minimo_Ottimo(cammini, TesoroInizio.size(), 0, SommaParziale, CamminoMinimoOttimo, TesoriTrovati);
    camminiOttimi.push_back(CamminoMinimoOttimo);

    for( unsigned int i = 0; i < TesoroInizio.size(); ++i)
      delete[] cammini[i];
    delete[] cammini;

    for( int i = 0; i < righe; ++i)
      delete[] Isle[i];
    delete[] Isle;

    cin >> comando;
    if( comando != "-1")
      cin >> comando;

   }

  for(unsigned int i = 0; i < camminiOttimi.size(); ++i)
    {
      cout << "result " << i+1 << "\n";
      cout << camminiOttimi[i] << "\n";
    }

  return 0;
}
