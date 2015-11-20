#include <iostream>
#include <vector>

using namespace std;

int dividi_monete( vector<int> sacchetto, int somma_valori )
{
  int dividi_valore = somma_valori / 2;
  int i = 0;
  int j;
  int massimo = 0;
  int somma = 0 ;

  for( int i = 0; i < sacchetto.size(); i++)
    {
      if( sacchetto[i] == dividi_valore)
        return sacchetto[i];
      else
        {
          for( int j = 0; j < sacchetto.size(); j++ )
            {
              if( i != j)
                {
                  if( somma < dividi_valore )
                    {
                      if((sacchetto[i] + sacchetto[j] + somma) < dividi_valore)
                        {
                          somma += sacchetto[i] + sacchetto[j];
                          if( somma > massimo )
                            massimo = somma;
                        }
                      else if( sacchetto[i] + sacchetto[j] == dividi_valore )
                        return sacchetto[i] + sacchetto[j];
                    }
                  j++;
                }
            }
        }
      i++;
      somma = 0;
    }

  return massimo;
}

int main()
{
  int n, m, valore_moneta, valore_prima_persona = 0, valore_seconda_persona = 0, valore_sacchetto = 0;

  vector<int> sacchetto;
  vector<int> risultati;

  cin >> n;
  for( int i = 0; i < n; i++ )
    {
      cin >> m;
      if( m >= 1 && m <= 100 )
        {
          for ( int j = 0; j < m; j++ )
            {
              cin >> valore_moneta;
              if( valore_moneta >= 1 && valore_moneta <= 500 )
                {
                  valore_sacchetto += valore_moneta;
                  sacchetto.push_back( valore_moneta );
                }
            }
        }

        valore_prima_persona = dividi_monete( sacchetto, valore_sacchetto );
        cout << valore_prima_persona << endl;
        valore_seconda_persona = valore_sacchetto - valore_prima_persona;
        risultati.push_back( valore_seconda_persona - valore_prima_persona );
        sacchetto.clear();
    }

  for( int i = 0; i < risultati.size(); i++ )
    {
      cout << risultati[i] << endl;
    }

  return 0;
}
