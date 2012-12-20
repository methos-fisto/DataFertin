#include "algos.h"

#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>

struct timeval start_utime, stop_utime;

void crono_start()
{
  struct rusage rusage;
  getrusage(RUSAGE_SELF, &rusage);
  start_utime = rusage.ru_utime;
}

void crono_stop()
{
  struct rusage rusage;

  getrusage(RUSAGE_SELF, &rusage);
  stop_utime = rusage.ru_utime;
}

double crono_ms()
{
  return (stop_utime.tv_sec - start_utime.tv_sec) * 1000 +
    (stop_utime.tv_usec - start_utime.tv_usec) / 1000 ;
}


/* dans le main

double temps;
crono_start();

crono_stop();
        temps = crono_ms()/1000,0;
        std::cout << "temps : " << temps << std::endl << std::endl ;

*/





int main(int argc, char *argv[])
{
    randomizeFixed(0.35698f);
    double temps;
    int i = atoi(argv[2]);
    int k, l;
    Graphe* mongraphe1 = new Graphe(i, 3.0f / ((double) i));
    Graphe* mongraphe2 = new Graphe(i, 4.0f / ((double) i));
    Graphe* mongraphe3 = new Graphe(i, 5.0f / ((double) i));
    Graphe* mongraphe4 = new Graphe(i, 0.1f);
    Graphe* mongraphe5 = new Graphe(i, 0.2f);

    switch(atoi(argv[1]))
    {
    case 0:
        std::cout << "Probleme de taille " << i << " : \n";
        std::cout << "\tProbabilite  3/" << i << " : \n";
        std::cout << "\t\tNombre d'aretes : " << mongraphe1->get_nbarete() << "\n";
        std::cout << "\t\tDegre max : " << mongraphe1->get_degre(mongraphe1->get_sommet_max()) << "\n";
        std::cout << "\t\tDegre moyen : " << mongraphe1->get_moydegre() << "\n\n";
        std::cout << "\tProbabilite  4/" << i << " : \n";
        std::cout << "\t\tNombre d'aretes : " << mongraphe2->get_nbarete() << "\n";
        std::cout << "\t\tDegre max : " << mongraphe2->get_degre(mongraphe2->get_sommet_max()) << "\n";
        std::cout << "\t\tDegre moyen : " << mongraphe2->get_moydegre() << "\n\n";
        std::cout << "\tProbabilite  5/" << i << " : \n";
        std::cout << "\t\tNombre d'aretes : " << mongraphe3->get_nbarete() << "\n";
        std::cout << "\t\tDegre max : " << mongraphe3->get_degre(mongraphe3->get_sommet_max()) << "\n";
        std::cout << "\t\tDegre moyen : " << mongraphe3->get_moydegre() << "\n\n";
        std::cout << "\tProbabilite  0.1 : \n";
        std::cout << "\t\tNombre d'aretes : " << mongraphe4->get_nbarete() << "\n";
        std::cout << "\t\tDegre max : " << mongraphe4->get_degre(mongraphe4->get_sommet_max()) << "\n";
        std::cout << "\t\tDegre moyen : " << mongraphe4->get_moydegre() << "\n\n";
        std::cout << "\tProbabilite  0.2 : \n";
        std::cout << "\t\tNombre d'aretes : " << mongraphe5->get_nbarete() << "\n";
        std::cout << "\t\tDegre max : " << mongraphe5->get_degre(mongraphe5->get_sommet_max()) << "\n";
        std::cout << "\t\tDegre moyen : " << mongraphe5->get_moydegre() << "\n\n";
        break;
    case 1:
        std::cout << "\n\n\n\nProbleme de taille " << i << " : \n";
        std::cout << "\tProbabilite  3/" << i << " : \n";
        crono_start();
        std::cout << "\t\t2approx : " << deuxapprox(mongraphe1) << "\n";
        crono_stop();
        temps = crono_ms()/1000,0;
        std::cout << "\t\t\ttemps : " << temps << std::endl << std::endl ;
        std::cout << "\tProbabilite  4/" << i << " : \n";
        crono_start();
        std::cout << "\t\t2approx : " << deuxapprox(mongraphe2) << "\n";
        crono_stop();
        temps = crono_ms()/1000,0;
        std::cout << "\t\t\ttemps : " << temps << std::endl << std::endl ;
        std::cout << "\tProbabilite  5/" << i << " : \n";
        crono_start();
        std::cout << "\t\t2approx : " << deuxapprox(mongraphe3) << "\n";
        crono_stop();
        temps = crono_ms()/1000,0;
        std::cout << "\t\t\ttemps : " << temps << std::endl << std::endl ;
        std::cout << "\tProbabilite  0.1 : \n";
        crono_start();
        std::cout << "\t\t2approx : " << deuxapprox(mongraphe4) << "\n";
        crono_stop();
        temps = crono_ms()/1000,0;
        std::cout << "\t\t\ttemps : " << temps << std::endl << std::endl ;
        std::cout << "\tProbabilite  0.2 : \n";
        crono_start();
        std::cout << "\t\t2approx : " << deuxapprox(mongraphe5) << "\n";
        crono_stop();
        temps = crono_ms()/1000,0;
        std::cout << "\t\t\ttemps : " << temps << std::endl << std::endl ;
        break;
    case 2:
        std::cout << "\n\n\n\nProbleme de taille " << i << " : \n";
        std::cout << "\tProbabilite  3/" << i << " : \n";
        k = deuxapprox(mongraphe1);
        l = monheur(mongraphe1);
        crono_start();
        std::cout << "\t\tArb-vc : " << test_arb(mongraphe1,k,l) << "\n";
        crono_stop();
        temps = crono_ms()/1000,0;
        std::cout << "\t\t\ttemps : " << temps << std::endl << std::endl ;
        std::cout << "\tProbabilite  4/" << i << " : \n";
        k = deuxapprox(mongraphe2);
        l = monheur(mongraphe2);
        crono_start();
        std::cout << "\t\tArb-vc : " << test_arb(mongraphe2,k,l) << "\n";
        crono_stop();
        temps = crono_ms()/1000,0;
        std::cout << "\t\t\ttemps : " << temps << std::endl << std::endl ;
        std::cout << "\tProbabilite  5/" << i << " : \n";
        k = deuxapprox(mongraphe3);
        l = monheur(mongraphe3);
        crono_start();
        std::cout << "\t\tArb-vc : " << test_arb(mongraphe3,k,l) << "\n";
        crono_stop();
        temps = crono_ms()/1000,0;
        std::cout << "\t\t\ttemps : " << temps << std::endl << std::endl ;
        std::cout << "\tProbabilite  0.1 : \n";
        k = deuxapprox(mongraphe4);
        l = monheur(mongraphe4);
        crono_start();
        std::cout << "\t\tArb-vc : " << test_arb(mongraphe4,k,l) << "\n";
        crono_stop();
        temps = crono_ms()/1000,0;
        std::cout << "\t\t\ttemps : " << temps << std::endl << std::endl ;
        std::cout << "\tProbabilite  0.2 : \n";
        k = deuxapprox(mongraphe5);
        l = monheur(mongraphe5);
        crono_start();
        std::cout << "\t\tArb-vc : " << test_arb(mongraphe5,k,l) << "\n";
        crono_stop();
        temps = crono_ms()/1000,0;
        std::cout << "\t\t\ttemps : " << temps << std::endl << std::endl ;
        break;
    case 3:
        std::cout << "\n\n\n\nProbleme de taille " << i << " : \n";
        std::cout << "\tProbabilite  3/" << i << " : \n";
        k = deuxapprox(mongraphe1);
        l = monheur(mongraphe1);
        crono_start();
        std::cout << "\t\tKernel-vc : " << test_kernel(mongraphe1,k,l) << "\n";
        crono_stop();
        temps = crono_ms()/1000,0;
        std::cout << "\t\t\ttemps : " << temps << std::endl << std::endl ;
        std::cout << "\tProbabilite  4/" << i << " : \n";
        k = deuxapprox(mongraphe2);
        l = monheur(mongraphe2);
        crono_start();
        std::cout << "\t\tKernel-vc : " << test_kernel(mongraphe2,k,l) << "\n";
        crono_stop();
        temps = crono_ms()/1000,0;
        std::cout << "\t\t\ttemps : " << temps << std::endl << std::endl ;
        std::cout << "\tProbabilite  5/" << i << " : \n";
        k = deuxapprox(mongraphe3);
        l = monheur(mongraphe3);
        crono_start();
        std::cout << "\t\tKernel-vc : " << test_kernel(mongraphe3,k,l) << "\n";
        crono_stop();
        temps = crono_ms()/1000,0;
        std::cout << "\t\t\ttemps : " << temps << std::endl << std::endl ;
        std::cout << "\tProbabilite  0.1 : \n";
        k = deuxapprox(mongraphe4);
        l = monheur(mongraphe4);
        crono_start();
        std::cout << "\t\tKernel-vc : " << test_kernel(mongraphe4,k,l) << "\n";
        crono_stop();
        temps = crono_ms()/1000,0;
        std::cout << "\t\t\ttemps : " << temps << std::endl << std::endl ;
        std::cout << "\tProbabilite  0.2 : \n";
        k = deuxapprox(mongraphe5);
        l = monheur(mongraphe5);
        crono_start();
        std::cout << "\t\tKernel-vc : " << test_kernel(mongraphe5,k,l) << "\n";
        crono_stop();
        temps = crono_ms()/1000,0;
        std::cout << "\t\t\ttemps : " << temps << std::endl << std::endl ;
        break;
    case 4:
        std::cout << "\n\n\n\nProbleme de taille " << i << " : \n";
        std::cout << "\tProbabilite  3/" << i << " : \n";
        crono_start();
        std::cout << "\t\tMon heuristique : " << monheur(mongraphe1) << "\n";
        crono_stop();
        temps = crono_ms()/1000,0;
        std::cout << "\t\t\ttemps : " << temps << std::endl << std::endl ;
        std::cout << "\tProbabilite  4/" << i << " : \n";
        crono_start();
        std::cout << "\t\tMon heuristique : " << monheur(mongraphe2) << "\n";
        crono_stop();
        temps = crono_ms()/1000,0;
        std::cout << "\t\t\ttemps : " << temps << std::endl << std::endl ;
        std::cout << "\tProbabilite  5/" << i << " : \n";
        crono_start();
        std::cout << "\t\tMon heuristique : " << monheur(mongraphe3) << "\n";
        crono_stop();
        temps = crono_ms()/1000,0;
        std::cout << "\t\t\ttemps : " << temps << std::endl << std::endl ;
        std::cout << "\tProbabilite  0.1 : \n";
        crono_start();
        std::cout << "\t\tMon heuristique : " << monheur(mongraphe4) << "\n";
        crono_stop();
        temps = crono_ms()/1000,0;
        std::cout << "\t\t\ttemps : " << temps << std::endl << std::endl ;
        std::cout << "\tProbabilite  0.2 : \n";
        crono_start();
        std::cout << "\t\tMon heuristique : " << monheur(mongraphe5) << "\n";
        crono_stop();
        temps = crono_ms()/1000,0;
        std::cout << "\t\t\ttemps : " << temps << std::endl << std::endl ;
        break;
    default:
        std::cout << "\n\n\nce parametre doit être entre 0 et 4\n\n\n";
    }


}
