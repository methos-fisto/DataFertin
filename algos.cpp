#include "algos.h"

bool arb_vc(Graphe* graphe, int param)
{
    if((graphe->get_nbarete()==0) && (param>=0))
    {
        return true;
    }
    if(param <=0)
    {
        return false;
    }
    int k1 = param;
    int k2 = k1;
    Graphe* G1 = new Graphe();
    Graphe* G2 = new Graphe();
    G1->copy_graphe(graphe);
    G2->copy_graphe(graphe);
    int smax = graphe->get_sommet_max();
    std::set<int> listevoisin = graphe->get_voisins(smax);
    G1->retire_sommet(smax);
    k1--;
    std::set<int>::iterator it;
    for(it = listevoisin.begin(); it != listevoisin.end(); it++)
    {
        G2->retire_sommet((*it));
        k2--;
    }
    bool br1 = arb_vc(G1, k1);
    bool br2 = arb_vc(G2, k2);
    delete G1;
    delete G2;
    return br1 || br2;
}

int test_arb(Graphe* graphe, int param)
{
    int kmax = param;
    int kmin = param/2;

    int k;
    while((kmin != kmax) && (kmax >= kmin))
    {
        k = kmin+(kmax-kmin)/2;
        if(arb_vc(graphe, k))
        {
            kmax = k;
        }else
        {
            kmin = k+1;
        }
    }

    return kmax;
}
