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

void VoceRubrica::setNome( string nome )
{
  Nome = nome;
}

void VoceRubrica::setCognome( string cognome )
{
  Cognome = cognome;
}

void VoceRubrica::setNumeroTelefonico( string numertelefonico )
{
  numertelefonico = numertelefonico;
}

const string VoceRubrica::getNome()
{
  return Nome;
}

const string VoceRubrica::getCognome()
{
  return Cognome;
}

const string VoceRubrica::getNumeroTelefonico()
{
  return numertelefonico;
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
