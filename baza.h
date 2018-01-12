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


    void printOpcije(){
      cout<<endl;
      cout<<"Ponudjene opcije:"<<endl;
      cout<<" 1. Pregled postojecih podataka"<<endl;
      cout<<" 2. Unos novog podatka u bazu"<<endl;
      cout<<" 3. Izmjena postojecih podataka"<<endl;
      cout<<" 4. Brisanje postojecih podataka"<<endl;
      cout<<" 5. Izlaz"<<endl;
      cout<<endl;
    }
    void printPodOpcije(int o){
      if(o==1){
        cout<<endl;
        cout<<"Ponudjene opcije: "<<endl;
        cout<<" 1. Pregled studijskih programa"<<endl;
        cout<<" 2. Pregled predmeta"<<endl;
        cout<<" 3. Pregled nastavnika"<<endl;
        cout<<" 4. Pregled studenata"<<endl;
        cout<<" 5. Pregled ispita"<<endl;
        cout<<" 6. Pregled semestra"<<endl;
        cout<<" 7. Izlaz"<<endl;
      }else if(o==2){
        cout<<"Ponudjene opcije: "<<endl;
        cout<<" 1. Unos studijskog programa"<<endl;
        cout<<" 2. Unos predmeta"<<endl;
        cout<<" 3. Unos nastavnika"<<endl;
        cout<<" 4. Unos studenta"<<endl;
        cout<<" 5. Unos ispita"<<endl;
        cout<<" 6. Izlaz"<<endl;
      }else if(o==3){
        cout<<"Ponudjene opcije:"<<endl;
        cout<<" 1. Izmjena studijskog programa"<<endl;
        cout<<" 2. Izmjena predmeta"<<endl;
        cout<<" 3. Izmjena nastavnika"<<endl;
        cout<<" 4. Izmjena studenta"<<endl;
        cout<<" 5. Izmjena ispita"<<endl;
        cout<<" 6. Izlaz"<<endl;
      }else if(o==4){
        cout<<"Ponudjene opcije:"<<endl;
        cout<<" 1. Brisanje predmeta"<<endl;
        cout<<" 2. Brisanje nastavnika"<<endl;
        cout<<" 3. Brisanje studenta"<<endl;
        cout<<" 4. Brisanje ispita"<<endl;
        cout<<" 5. Izlaz"<<endl;
      }else{
        cout<<"Vaš unos nije validan!Pokušajte ponovo."<<endl;
      }
      cout<<endl;
    }
    
    void print(int o){
      if(o==1){
        for(int i=0;i<_studijskiProgrami.size();++i){
          cout<<(*_studijskiProgrami[i]).printStProgram()<<endl;
        }
      }else if(o==2){
        for(int i=0;i<_predmeti.size();++i){
          cout<<(*_predmeti[i]).printPredmet()<<endl;
        }
      }else if(o==3){
        for(int i=0;i<_nastavnici.size();++i){
          cout<<(*_nastavnici[i]).printNastavnik()<<endl;
        }
      }else if(o==4){
        for(int i=0;i<_studenti.size();++i){
          cout<<(*_studenti[i]).printStudent()<<endl;
        }
      }else if(o==5){
        for(int i=0;i<_ispiti.size();++i){
          cout<<(*_ispiti[i]).printIspit()<<endl;
        }
      }else if(o==6){
        cout<<"semestar"<<endl;
      }
    }

    void spremiPodatke(){}

};

#endif


