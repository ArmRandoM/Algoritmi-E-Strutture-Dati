#include <iostream>
#include <list>
using namespace std;

int main()
{
  int n, m, ValoreMoneta, dividi, coins1 = 0, coins2 = 0, somma = 0;
  unsigned int DifferenzaMinima = 0;
  list<int> valori;
  list<int> differenze;

  cin >> n;

  for( int i = 0; i < n; i++ )
    {
      cin >> m;

      for( int j = 0; j < m; j++)
        {
          cin >> ValoreMoneta;
          if( ValoreMoneta >= 1 && ValoreMoneta <= 500)
            {
              somma += ValoreMoneta;
              valori.push_back( ValoreMoneta );
            }
        }

      valori.sort();

      dividi = somma / 2;

      list<int>:: iterator it = valori.begin();

      while( coins1 < dividi )
        {
          coins1 += *it;
          cout << coins1 << endl;
          it++;
        }

      coins2 = somma - coins1;
      DifferenzaMinima = coins1 - coins2;

      cout << DifferenzaMinima << endl;
      valori.clear();

      differenze.push_back( DifferenzaMinima );

      DifferenzaMinima = 0;
      coins1 = 0;
      coins2 = 0;

    }

    for( list<int>:: iterator it = differenze.begin(); it != differenze.end(); it++ )
      cout << *it;
    return 0;
}
