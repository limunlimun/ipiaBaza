#ifndef _BAZA_H
#define _BAZA_H
#include "funkcije.h"

class Baza{
  private:
    vector<Student*> _studenti;
    vector<Nastavnik*> _nastavnici;
    vector<Ispit*> _ispiti;
    vector<Predmet*> _predmeti;
    vector<stProgram*> _studijskiProgrami;
    vector<Usmjerenje*> _usmjerenja;
  public:
    Baza(){
      _studenti=kreirajStudente();
      _nastavnici=kreirajNastavnike();
      _ispiti=kreirajIspite();
      _predmeti=kreirajPredmete();
      _studijskiProgrami=kreirajStPrograme();
      _usmjerenja=kreirajUsmjerenja();
    }
    ~Baza()=default;


};

#endif


