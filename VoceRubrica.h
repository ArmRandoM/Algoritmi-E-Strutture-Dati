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
    friend ostream &operator<<(ostream &, const Biblioteca &);
    friend istream &operator>>(istream &, Biblioteca &);
  private:
    string Nome, Cognome, NumeroTelefonico;
}
