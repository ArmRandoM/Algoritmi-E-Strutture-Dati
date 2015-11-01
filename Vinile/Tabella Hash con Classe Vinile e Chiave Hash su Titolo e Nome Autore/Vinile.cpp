#include "Vinile.h"

//costruttore di default della classe
Vinile::Vinile(){};

//costruttore per copia della classe
Vinile::Vinile( Vinile const &v)
{
  NomeArtista = v.NomeArtista;
  Titolo = v.Titolo;
  Genere = v.Genere;
  Anno = v.Anno;
}

//Definizione delle funzioni set per la classe Vinile
void Vinile::setNomeArtista( string nome )
{
  NomeArtista = nome;
}

void Vinile::setTitolo( string titolo )
{
  Titolo = titolo;
}

void Vinile::setGenere( string genere )
{
  Genere = genere;
}

void Vinile::setAnno( string anno )
{
  Anno = anno;
}

//Definizione delle funzioni get per la classe Vinile
string Vinile::getNomeArtista() const
{
  return NomeArtista;
}

string Vinile::getTitolo() const
{
  return Titolo;
}

string Vinile::getGenere() const
{
  return Genere;
}

string Vinile::getAnno() const
{
  return Anno;
}

//operatore di stampa ridefinito
ostream &operator << ( ostream &out, const Vinile& v )
{
  cout << "===============================" << endl;
  out << "Nome Artista: " << v.NomeArtista << endl;
  out << "Titolo: " << v.Titolo << endl;
  out << "Genere: " << v.Genere << endl;
  out << "Anno: " << v.Anno << endl;
  cout << "===============================" << endl << endl;
  return out;
}

//operatore di inserimento ridefinito
istream &operator >> (istream &in, Vinile& v)
{
  cout << endl;
  cout << "===============================" << endl;
  cout << "Inserisci Caratteristiche Album" << endl;
  cout << "===============================" << endl;
  cout << "Nome Artista: ";
  in >> v.NomeArtista;
  cout << "Titolo: ";
  in >> v.Titolo;
  cout << "Genere: ";
  in >> v.Genere;
  cout << "Anno: ";
  in >> v.Anno;
  cout << "===============================" << endl;

  return in;
}
