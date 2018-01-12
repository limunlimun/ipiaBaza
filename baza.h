#ifndef _BAZA_H
#define _BAZA_H
#include "student.h"
#include "nastavnik.h"
#include "ispit.h"
#include "predmet.h"
#include "stProgram.h"
#include "usmjerenje.h"
#include <vector>
#include <fstream>

using namespace std;
class Baza{
  private:
    vector<Student*> _studenti;
    vector<Nastavnik*> _nastavnici;
    vector<Ispit*> _ispiti;
    vector<Predmet*> _predmeti;
    vector<stProgram*> _studijskiProgrami;
    vector<Usmjerenje*> _usmjerenja;

    bool _izmjenastudenti=false;
    bool _izmjenanastavnici=false;
    bool _izmjenaispiti=false;
    bool _izmjenapredmeti=false;
    bool _izmjenastprogrami=false;
    bool _izmjenausmjerenja=false;

  public:
    Baza();   
    ~Baza()=default;

    void printOpcije();
    void printPodOpcije(int o); 
    void print(int o);

    void spremiPodatke();

    bool kreirajProgram();
    bool kreirajPredmet();
    bool kreirajNastavnika();
    bool kreirajStudenta(); 
    bool kreirajIspit();
    void kreiraj(int o);

    vector<Student*> ucitajStudente();
    vector<Nastavnik*> ucitajNastavnike();
    vector<Ispit*> ucitajIspite();
    vector<Predmet*> ucitajPredmete();
    vector<stProgram*> ucitajPrograme();
    vector<Usmjerenje*> ucitajUsmjerenja();

};

#endif


