// file dipendente.h
#include <iostream>
#include <string>

using namespace std;

typedef unsigned long int card; // tipo cardinale

class Dipendente
{	public:
	card codice;
	string nome;
	short eta;
	long salario;
};

inline bool operator== (const Dipendente& d1, const Dipendente& d2)
{	return d1.codice == d2.codice;
}

inline bool operator< (const Dipendente& d1, const Dipendente& d2)
{	return d1.codice < d2.codice;
}

inline istream& operator>> ( istream& ci, Dipendente& d )
{
	cout << "\ncodice? "; ci >> d.codice;
	if ( d.codice > 0 )
	{	cout << "nome? "; ci >> d.nome;
		cout << "eta? "; ci >> d.eta;
		cout << "salario? "; ci >> d.salario;
	}
	else
		cout << "codice non valido";
	return ci;
};

inline ostream& operator<< ( ostream& co, const Dipendente& d)
{	co << "\ncodice: " << d.codice << "\n";
	co << "nome: " << d.nome.c_str() << "\n";
	co << "eta: " << d.eta << "\n";
	co << "salario: " << d.salario << "\n";
	return co;
};
