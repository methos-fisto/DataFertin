#include "graphe.h"

Graphe::Graphe(int n, double proba)
{
    int i, j;
    _nbarete = 0;
    for(i = 0; i < n ; i++)
    {
        _sommets.insert(i);
    }

    for(i = 0; i < n-1 ; i++)
    {
        for(j = i+1; j < n; j++ )
        {
            if(rndreal(0,1) <= proba)
            {
                _aretes.insert(Arete(i,j));
                _nbarete++;
            }
        }
    }
    _mindegre= _nbarete;
    _moydegre= 0;
    for(i = 0; i < n ; i++)
    {
        j = get_degre(i);
        _moydegre += j;
        if(_mindegre > j)
        {
            _mindegre = j;
        }
    }
    _moydegre = _moydegre/n;
}

void Graphe::retire_sommet(int a)
{
    _sommets.erase(a);

    std::set<Arete>::iterator it;
    std::set<Arete>::iterator it2;
    it = _aretes.begin();
    while(it != _aretes.end())
    {
        if((*it).contient(a))
        {
            _aretes.erase(it);

            it = _aretes.begin();
        }else
        {
            it++;
        }


    }

}

std::set<int> Graphe::get_sommets()
{
    return _sommets;
}

std::set<Arete> Graphe::get_aretes()
{
    return _aretes;
}

int Graphe::get_nbsommets()
{
    return _sommets.size();
}

int Graphe::get_nbarete()
{
    return _aretes.size();
}

int Graphe::get_mindegre()
{
    return _mindegre;
}

double Graphe::get_moydegre()
{
    return _moydegre;
}

int Graphe::get_degre(int a)
{
    std::set<Arete>::iterator it;
    int deg = 0;
    for(it = _aretes.begin(); it != _aretes.end(); it++)
    {
        if((*it).contient(a))
        {
            deg++;
        }
    }
    return deg;
}

std::set<Arete> Graphe::get_arcs(int a)
{
    std::set<Arete> sol;
    std::set<Arete>::iterator it;
    for(it = _aretes.begin(); it != _aretes.end(); it++)
    {
        if((*it).contient(a))
        {
            sol.insert(Arete((*it).get_sommet1(),(*it).get_sommet2()));
        }
    }
    return sol;
}

void Graphe::copy_graphe(Graphe* gacopier)
{
    _sommets = gacopier->get_sommets();
    _aretes = gacopier->get_aretes();
	_nbarete = get_nbarete();
	_mindegre = gacopier->get_mindegre();
	_moydegre = gacopier->get_moydegre();
}

int main()
{
    randomizeFixed(0.35698f);
    Graphe* mongraphe = new Graphe(30, 0.1);

    std::cout << mongraphe->get_nbsommets() << "\n";
    std::cout << mongraphe->get_nbarete()<< "\n";
    std::cout << mongraphe->get_mindegre()<< "\n";
    std::cout << mongraphe->get_moydegre()<< "\n";
    std::cout << mongraphe->get_degre(2)<< "\n";
    mongraphe->retire_sommet(2);
    std::cout << mongraphe->get_nbsommets() << "\n";
    std::cout << mongraphe->get_nbarete()<< "\n";
    Graphe* gr2 = new Graphe(1,0);
    gr2->copy_graphe(mongraphe);
    mongraphe->retire_sommet(3);
    std::cout << mongraphe->get_nbsommets() << "\n";
    std::cout << mongraphe->get_nbarete()<< "\n";
    std::cout << gr2->get_nbsommets() << "\n";
    std::cout << gr2->get_nbarete()<< "\n";
    return 1;
}
