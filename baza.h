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

    bool izmijeniProgram(int i);
    bool izmijeniPredmet(int i);
    bool izmijeniNastavnika(int i);
    bool izmijeniStudenta(int i);
    bool izmijeniIspit(int i);
    void izmijeni(int o);

    int pronadjiProgram(string kljuc);
    int pronadjiPredmet(string kljuc);
    int pronadjiNastavnika(string kljuc);
    int pronadjiStudenta(string kljuc);
    int pronadjiIspit(string kljuc1,string kljuc2,string kljuc3);
    
    bool obrisiPredmet(int i);
    bool obrisiNastavnika(int i);
    bool obrisiStudenta(int i);
    bool obrisiIspit(int i);
    void obrisi(int o);

    vector<Student*> ucitajStudente();
    vector<Nastavnik*> ucitajNastavnike();
    vector<Ispit*> ucitajIspite();
    vector<Predmet*> ucitajPredmete();
    vector<stProgram*> ucitajPrograme();
    vector<Usmjerenje*> ucitajUsmjerenja();

};

#endif


