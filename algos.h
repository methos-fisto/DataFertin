#ifndef ALGOS_H
#define ALGOS_H


#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <set>
#include "graphe.h"
#include "arete.h"


bool arb_vc(Graphe*, int);
int test_arb(Graphe*, int, int);
bool kernel_vc(Graphe*, int);
int test_kernel(Graphe*, int, int);
int deuxapprox(Graphe*);
int monheur(Graphe*);
#endif
