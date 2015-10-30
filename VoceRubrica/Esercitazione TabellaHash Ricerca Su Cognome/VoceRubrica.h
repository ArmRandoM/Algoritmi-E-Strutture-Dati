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
    void setNumeroTelefonico( string );

    string getNome() const;
    string getCognome() const;
    string getNumeroTelefonico() const;

    friend ostream &operator<<(ostream &, const VoceRubrica &);
    friend istream &operator>>(istream &, VoceRubrica &);

  private:

    string Nome, Cognome, NumeroTelefonico;
};

#endif
