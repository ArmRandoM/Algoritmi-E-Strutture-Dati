#include <list>
#include <string>
#include <iostream>
using namespace std;

int main()
{

  bool tappo = false;
  bool no = false;
  int pos;
  string parola;
  list<string> ElencoParole;

  while( tappo == false)
    {
      getline( cin, parola, '\n');

      if( ( parola.find( "<END>") != -1))
        {
          if( parola.size() == 5 || parola.size() == 6)
            no = true;
          pos = parola.find( "<END>");
          parola.erase( pos, (parola.size() - pos) );
          tappo = true;
        }
      if( no == false )
        ElencoParole.push_front( parola );
    }

  for( list<string>::iterator it = ElencoParole.begin(); it != ElencoParole.end(); it++ )
    cout << *it << endl;

  return 0;

}
