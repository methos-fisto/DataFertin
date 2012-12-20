#ifndef GRAPHE_H
#define GRAPHE_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>

#include "arete.h"
//#include "rnd.c"
void advance_random();
void warmup_random(float random_seed);
void randomize();
void randomizeFixed(float randomseed);
float randomperc();
int rnd(int low,int high);
float rndreal(float lo , float hi);

class Arete;

class Graphe
{
	private :
		std::set<int>      _sommets;
		std::set<Arete> _aretes;
		int	  			   _nbarete;
		int				   _mindegre;
		double			   _moydegre;

	public :
		Graphe(int, double);
		Graphe();
		void retire_sommet(int);
		std::set<int> get_sommets();
		std::set<Arete> get_aretes();
		int                get_nbsommets();
		int	  			   get_nbarete();
		int				   get_mindegre();
		double			   get_moydegre();
		int                get_degre(int);
		int                get_sommet_max();
		std::set<int>      get_voisins(int);
		std::set<Arete> get_arcs(int);
		void 			   copy_graphe(Graphe* );
};

#endif
