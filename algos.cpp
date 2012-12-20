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

int test_arb(Graphe* graphe, int param1, int param2)
{
    int kmax;
    if(param1> param2)
    {
        kmax = param2;
    }else
    {
        kmax = param1;
    }
    int kmin = param1/2;

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

int deuxapprox(Graphe* mongraphe)
{   std::set<Arete> mesaretes;
    int k;
    int i;
    int a, b;
    int sol = 0;
    std::set<Arete>::iterator it;
    Graphe* graphe = new Graphe();
    graphe->copy_graphe(mongraphe);

    while(graphe->get_nbarete() > 0)
    {
        k = rnd(1,graphe->get_nbarete());
        mesaretes= graphe->get_aretes();
        it = mesaretes.begin();
        i=1;
        while(i < k)
        {
            i++;
            it++;
        }
        a = (*it).get_sommet1();
        b = (*it).get_sommet2();
        graphe->retire_sommet(a);
        graphe->retire_sommet(b);
        sol = sol+2;
        mesaretes.clear();
    }
    delete graphe;
    return sol;
}

bool kernel_vc(Graphe* mongraphe, int param)
{
    Graphe* graphe = new Graphe();
    int k = param;
    graphe->copy_graphe(mongraphe);
    std::set<int> messommets;
    std::set<int>::iterator it;
    int d;

    messommets = graphe->get_sommets();
    it = messommets.begin();

    while((k>0) && (it != messommets.end())){
    d = graphe->get_degre((*it));
    if(d== 1)
    {
        messommets = graphe->get_voisins((*it));
        it = messommets.begin();
        graphe->retire_sommet((*it));
        messommets = graphe->get_sommets();
        it = messommets.begin();
        k--;

    }else
    {
        if(d>k)
        {
            graphe->retire_sommet((*it));
            messommets = graphe->get_sommets();
            it = messommets.begin();
            k--;
        }else
        {
            it++;
        }
    }
    }
    if(graphe->get_nbarete()>0)
    {
        if(k==0){
            return false;
        }else
        {
            return arb_vc(graphe,k);
        }
    }else
    {
        return true;
    }
}

int test_kernel(Graphe* graphe, int param1, int param2)
{
    int kmax;
    if(param1> param2)
    {
        kmax = param2;
    }else
    {
        kmax = param1;
    }
    int kmin = param1/2;

    int k;
    while((kmin != kmax) && (kmax >= kmin))
    {
        k = kmin+(kmax-kmin)/2;
        if(kernel_vc(graphe, k))
        {
            kmax = k;
        }else
        {
            kmin = k+1;
        }
    }

    return kmax;
}

int monheur(Graphe* mongraphe)
{
    Graphe* graphe = new Graphe();
    graphe->copy_graphe(mongraphe);
    int smax;
    int k = 0;
    while(graphe->get_nbarete() > 0){
        smax = graphe->get_sommet_max();
        graphe->retire_sommet(smax);
        k++;
    }
    return k;
}
