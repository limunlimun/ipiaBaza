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

    bool _izmjenastudenti=false;
    bool _izmjenanastavnici=false;
    bool _izmjenaispiti=false;
    bool _izmjenapredmeti=false;
    bool _izmjenastprogrami=false;
    bool _izmjenausmjerenja=false;

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

    bool kreirajProgram(){
      string skr,naziv;
      cout<<"Unesite skracenicu od 2 slova:"<<endl;
      cin>>skr;
      if(skr.length()!=2){
        cout<<"Skracenica mora biti duzine 2!"<<endl;
        return false;
      }
      cout<<"Unesite naziv studijskog programa:"<<endl;
      cin.clear();
      cin>>naziv;
      _studijskiProgrami.push_back(new stProgram(skr,naziv));
      return false;
    }

    bool kreirajPredmet(){
      string skr,naziv,stProg,usmjerenje;
      int sem,sp,sa,sl,ects,intgrupa;
      cout<<"Unesite skracenicu od 2 slova:"<<endl;
      cin>>skr;
      if(skr.length()!=2){
        cout<<"Skracenica mora biti duzine 2!"<<endl;
        return false;
      }
      cin.clear();
      cout<<"Unesite puni naziv predmeta:"<<endl;
      cin>>naziv;
      cout<<"Unesite skracenicu st.programa i usmjerenja (oba moraju biti duzine 2)"<<endl;
      cin>>stProg>>usmjerenje;
      if(stProg.length()!=2 || usmjerenje.length()!=2){
        cout<<"Moraju biti duzine 2!"<<endl;
        return false;
      }
      cin.clear();
      cout<<"Unesite semestar, sate predavanja, sate AV, sate LV, ects i interesnu grupu(grupa oznacena brojem od 1 do 4)"<<endl;
      cin>>sem>>sp>>sa>>sl>>ects>>intgrupa;
      _predmeti.push_back(new Predmet(skr,naziv,stProg,usmjerenje,sem,sp,sa,sl,ects,intgrupa));
      return true;
    }

    bool kreirajNastavnika(){
      string ime,prezime,jmbg,zvanje,predmet;
      cout<<"Unesite ime,prezime,jmbg(13 cifara),zvanje i predmet"<<endl;
      cin>>ime>>prezime>>jmbg>>zvanje>>predmet;
      if(jmbg.length()!=13){
        cout<<"Pogresan unos JMBG"<<endl;
        return false;
      }
      _nastavnici.push_back(new Nastavnik(ime,prezime,jmbg,zvanje,predmet));
      return true;
    }

    bool kreirajStudenta(){
      string ime,prezime,jmbg,brind,stprog;
      cout<<"Unesite ime, prezime, jmbg(13 cifara), br. indexa i studijski program(mora biti duzine 2)"<<endl;
      cin>>ime>>prezime>>jmbg>>brind>>stprog;
      if(jmbg.length()!=13 || stprog.length()!=2){
        cout<<"JMBG ili st. prog. pogresno uneseni!"<<endl;
        return false;
      }
      _studenti.push_back(new Student(ime,prezime,jmbg,brind,stprog));
      return true;
    }
    
    bool kreirajIspit(){
      string pred,jmbg,brind,dat;
      int ocj;
      cout<<"Unesite predmet(skracenica od 2 slova),jmbg profesora(13 cifara),broj indexa studenta, datum i ocjenu"<<endl;
      cin>>pred>>jmbg>>brind>>dat;
      if(pred.length()!=2 || jmbg.length()!=13){
        cout<<"Skracenica predmeta ili JMBG pogresno uneseni!"<<endl;
        return false;
      }
      if(ocj<6 || ocj>10){
        cout<<"Ocjena mora biti u rasponu od 6 do 10!"<<endl;
        return false;
      }
      _ispiti.push_back(new Ispit(pred,jmbg,brind,dat,ocj));
      return true;
    }

    void kreiraj(int o){
      if(o==1){
        if(kreirajProgram())
          _izmjenastprogrami=true;
      }else if(o==2){
        if(kreirajPredmet())
          _izmjenapredmeti=true;
      }else if(o==3){
        if(kreirajNastavnika())
          _izmjenanastavnici=true;
      }else if(o==4){
        if(kreirajStudenta())
          _izmjenastudenti=true;
      }else if(o==5){
        if(kreirajIspit())
          _izmjenaispiti=true;
      }
    }

};

#endif


