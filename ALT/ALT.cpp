#include <list>
#include <string>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main()
{
  string numero;
  list <int> ElencoNumeriPositivi;
  list <int> ElencoNumeriNegativi;
  list <string> ElencoNumeriAlternati;

  cin >> numero;

  while( numero != "<END>" )
    {
      if( numero < "0" )
        ElencoNumeriNegativi.push_back( atoi(numero.c_str()) );
      else
        ElencoNumeriPositivi.push_back( atoi(numero.c_str()) );

      cin >> numero;
    }

  /*c_str() restituisce il puntatore ad un array contenente la sequenza terminata da /0 dei caratteri che compongono
    la stringa "numero" in modo da essere convertito dalla funzione atoi ( array of char to integer ) in un intero*/

  ElencoNumeriNegativi.sort();
  ElencoNumeriPositivi.sort();

  list<int>::iterator it1 = ElencoNumeriNegativi.begin();
  list<int>::iterator it2 = ElencoNumeriPositivi.begin();

  for( unsigned int i = 0; i < ElencoNumeriNegativi.size() + ElencoNumeriPositivi.size(); i++ )
    {
          if( it1 != ElencoNumeriNegativi.end())
            {
                cout << *it1 << endl;
                it1++;
            }

          if( it2 != ElencoNumeriPositivi.end())
            {
                cout << *it2 << endl;
                it2++;
            }
    }

  return 0;
}
