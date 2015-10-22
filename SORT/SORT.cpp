#include <list>
#include <iostream>
using namespace std;

int main()
{

  int numero;
  list<int> ElencoNumeri;

  cin >> numero;

  while( numero != -1 )
    {
      ElencoNumeri.push_back(numero);
      cin >> numero;
    }

  ElencoNumeri.sort();

  for( list<int>::iterator it = ElencoNumeri.begin(); it != ElencoNumeri.end(); it++ )
    cout << *it << endl;

  return 0;

}
