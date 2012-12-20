#include "arete.h"


Arete::Arete(int a , int b){

_sommet1 = a;
_sommet2 = b;

}

bool Arete::contient(int a) const
{
    if((_sommet1 == a) || (_sommet2 == a))
    {
        return true;
    }else
    {
        return false;
    }
}

int Arete::get_sommet1() const
{
    return _sommet1;
}

int Arete::get_sommet2() const
{
    return _sommet2;
}

bool operator<(Arete t, Arete p)
{
    if(t.get_sommet1() < p.get_sommet1())
    {
        return true;
    }else
    {
        if(t.get_sommet1() == p.get_sommet1())
        {
            return t.get_sommet2() < p.get_sommet2();
        }else
        {
            return false;
        }
    }
}
/*
bool Arete::operator<=(Arete p)
{
    return (operator<(p) || operator==(p));
}

bool Arete::operator>(Arete p)
{
    if(_sommet1 > p.get_sommet1())
    {
        return true;
    }else
    {
        if(_sommet1 == p.get_sommet1())
        {
            return _sommet2 > p.get_sommet2();
        }else
        {
            return false;
        }
    }
}

bool Arete::operator>=(Arete p)
{
    return (operator>(p) || operator==(p));
}

bool Arete::operator==(Arete p)
{
    if(_sommet1 == p.get_sommet1())
    {
        return _sommet2 == p.get_sommet2();
    }else
    {
        return false;
    }
}
*/
