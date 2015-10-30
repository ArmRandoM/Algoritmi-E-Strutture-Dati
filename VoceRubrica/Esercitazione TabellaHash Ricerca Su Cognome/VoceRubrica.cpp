#include "VoceRubrica.h"

//costruttore di default della classe
VoceRubrica::VoceRubrica(){};

//costruttore per copia della classe
VoceRubrica::VoceRubrica( VoceRubrica const &vr)
{
  Nome = vr.Nome;
  Cognome = vr.Cognome;
  NumeroTelefonico = vr.NumeroTelefonico;
}

void VoceRubrica::setNome( string nome )
{
  Nome = nome;
}

void VoceRubrica::setCognome( string cognome )
{
  Cognome = cognome;
}

void VoceRubrica::setNumeroTelefonico( string numerotelefonico )
{
  numerotelefonico = numerotelefonico;
}

string VoceRubrica::getNome() const
{
  return Nome;
}

string VoceRubrica::getCognome() const
{
  return Cognome;
}

string VoceRubrica::getNumeroTelefonico() const
{
  return NumeroTelefonico;
}

//operatore di stampa ridefinito
ostream &operator << ( ostream &out, const VoceRubrica& vr )
{
  cout << "===============================" << endl;
  out << "Nome: " << vr.Nome << endl;
  out << "Cognome: " << vr.Cognome << endl;
  out << "Numero Telefonico: " << vr.NumeroTelefonico << endl;
  cout << "===============================" << endl << endl;
  return out;
}

//operatore di inserimento ridefinito
istream &operator >> (istream &in, VoceRubrica& vr)
{
  cout << endl;
  cout << "===============================" << endl;
  cout << "Inserisci Voce Rubrica" << endl;
  cout << "===============================" << endl;
  cout << "Nome: ";
  in >> vr.Nome;
  cout << "Cognome: ";
  in >> vr.Cognome;
  cout << "Numero Telefonico: ";
  in >> vr.NumeroTelefonico;
  cout << "===============================" << endl;

  return in;
}
