#include "algos.h"

int main(int argc, char *argv[])
{
    randomizeFixed(0.35698f);
    int i = atoi(argv[1]);
    Graphe* mongraphe1 = new Graphe(i, 3.0f / ((double) i));
    Graphe* mongraphe2 = new Graphe(i, 4.0f / ((double) i));
    Graphe* mongraphe3 = new Graphe(i, 5.0f / ((double) i));
    Graphe* mongraphe4 = new Graphe(i, 0.1f);
    Graphe* mongraphe5 = new Graphe(i, 0.2f);

    std::cout << test_arb(mongraphe1, i);
    std::cout << test_arb(mongraphe2, i);
    std::cout << test_arb(mongraphe3, i);
    std::cout << test_arb(mongraphe4, i);
    std::cout << test_arb(mongraphe5, i);
}
