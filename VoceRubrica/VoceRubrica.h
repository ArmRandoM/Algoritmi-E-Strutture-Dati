#ifndef VOCERUBRICA_H
#define VOCERUBRICA_H

#include <iostream>
#include <string>
using namespace std;

class VoceRubrica
{
  public:

    VoceRubrica();
    VoceRubrica( VoceRubrica const &vr);

    void setNome( string );
    void setCognome( string );
    void setNumeroTelefonico( int );

    const string getNome();
    const string getCognome();
    const string getNumeroTelefonico();

    friend ostream &operator<<(ostream &, const Biblioteca &);
    friend istream &operator>>(istream &, Biblioteca &);

  private:

    string Nome, Cognome, NumeroTelefonico;
};

#endif
