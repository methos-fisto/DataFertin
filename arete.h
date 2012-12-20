#ifndef ARETE_H
#define ARETE_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>

class Arete
{
	private :
		int _sommet1;
		int _sommet2;

	public :
		Arete(int, int);
		bool contient(int) const;
		int get_sommet1() const;
		int get_sommet2() const;
		//bool operator<(Arete);
		//bool operator<=(Arete);
		//bool operator>(Arete);
		//bool operator>=(Arete);
		//bool operator==(Arete);
};

bool operator<(Arete, Arete);

#endif
