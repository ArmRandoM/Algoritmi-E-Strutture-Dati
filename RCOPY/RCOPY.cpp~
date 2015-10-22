#include <list>
#include <string>
#include <iostream>
using namespace std;

int main()
{

  bool prima_volta = true;
  string parola;
  list<string> ElencoParole;

  cin >> parola;

  while( parola != "<END>")
    {
          ElencoParole.push_front( parola );
		cin >> parola;
    }

  for( list<string>::iterator it = ElencoParole.begin(); it != ElencoParole.end(); it++ )
    {
		if( prima_volta == true )
			{
				cout << *it ;
				prima_volta = false;
			}
		else
			cout << endl << *it;
	}
  return 0;

}
