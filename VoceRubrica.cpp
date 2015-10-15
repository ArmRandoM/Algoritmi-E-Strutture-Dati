#include "VoceRubrica.h"

//costruttore di default della classe
VoceRubrica::VoceRubrica();

//costruttore per copia della classe
VoceRubrica::VoceRubrica( VoceRubrica const &vr)
{
  this -> Nome = vr.Nome;
  this -> Cognome = vr.Cognome;
  this -> NumeroTelefonico = vr.NumeroTelefonico;
}

//operatore di stampa ridefinito
ostream &operator << ( ostream &out, const VoceRubrica& vr )
{
  out << "Nome: " << vr.Nome << "Cognome: " << vr.Cognome << "Numero Telefonico: " << vr.NumeroTelefonico << endl;
  return out;
}

//operatore di inserimento ridefinito
istream &operator >> (istream &in, VoceRubrica& vr)
{
  cout << "Inserisci Voce Rubrica" << endl;
  cout << "Nome: ";
  in >> vr.Nome;
  cout << " Cognome: ";
  in >> vr.Cognome;
  cout << " Numero Telefonico: ";
  in >> vr.NumeroTelefonico;

  return in;
}
