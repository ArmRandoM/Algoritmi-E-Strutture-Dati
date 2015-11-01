#ifndef VINILE_H
#define VINILE_H

#include <iostream>
#include <string>
using namespace std;

class Vinile
{
  public:

    Vinile(); //costruttore di default per la classe vinile
    Vinile( Vinile const &v); //costruttore per copia per la classe vinile

    void setNomeArtista( string );
    void setTitolo( string );
    void setGenere( string );
    void setAnno( string );
    void ImportaDaFile( const string ) const;

    string getNomeArtista() const;
    string getTitolo() const;
    string getGenere() const;
    string getAnno() const;

    friend ostream &operator<<(ostream &, const Vinile &);
    friend istream &operator>>(istream &, Vinile &);

  private:

    string NomeArtista, Titolo, Genere, Anno;
};

#endif
