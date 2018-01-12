#include "baza.h"

int stringUBroj(const string &tekst){
      stringstream ss(tekst);
      int rezultat;
      return ss>>rezultat? rezultat : 0;
}

bool provjeriIspit(string jmbg,int ocj){
  if(jmbg.length()==13 && ocj>=6 && ocj<=10) return true;
  else return false;
}

bool provjeriStudenta(string jmbg,string program){
  if(jmbg.length()==13 && program.length()==2) return true;
  else return false;
}

bool provjeriNastavnika(string jmbg){
  if(jmbg.length()==13) return true;
  else return false;
}

vector<string> rastavi(string red){
  stringstream x(red);
  string novi;
  vector<string> povratni;
  while(getline(x,novi,'#'))
    povratni.push_back(novi);
  return povratni;
}

Baza::Baza(){
  _studenti=ucitajStudente();
  _nastavnici=ucitajNastavnike();
  _ispiti=ucitajIspite();
  _predmeti=ucitajPredmete();
  _studijskiProgrami=ucitajPrograme();
  _usmjerenja=ucitajUsmjerenja();
}

vector<Student*> Baza::ucitajStudente(){
  string red;
  vector<Student*> povratni;
  ifstream infile("student.dat");
  if(!infile.is_open()){
    cout<<"Greska. Student!"<<endl;
    return povratni;
  }
  getline(infile,red);
  vector<string> temp=rastavi(red);
  for(int i=0;i<temp.size()/5;++i){
    if(provjeriStudenta(temp[5*i],temp[5*i+4])){
      povratni.push_back(new Student(temp[5*i+1],temp[5*i+2],temp[5*i],temp[5*i+3],temp[5*i+4]));
    }
  }
  return povratni;
}

vector<Nastavnik*> Baza::ucitajNastavnike(){
  string red;
  vector<Nastavnik*> povratni;
  ifstream infile("nastavnik.dat");
  if(!infile.is_open()){
    cout<<"Greska. Nastavnik!"<<endl;
    return povratni;
  }
  getline(infile,red);
  vector<string> temp=rastavi(red);
  for(int i=0;i<temp.size()/5;++i){
    if(provjeriNastavnika(temp[5*i])){
      povratni.push_back(new Nastavnik(temp[5*i+1],temp[5*i+2],temp[5*i],temp[5*i+3],temp[5*i+4]));
    }
  }
  return povratni;
}

vector<Ispit*> Baza::ucitajIspite(){
  string red;
  vector<Ispit*> povratni;
  ifstream infile("ispit.dat");
  if(!infile.is_open()){
    cout<<"Greska.Ispit!"<<endl;
    return povratni;
  }
  getline(infile,red);
  vector<string> temp=rastavi(red);
  for(int i=0;i<temp.size()/5;++i){
    int ocj=stringUBroj(temp[5*i+4]);
    if(provjeriIspit(temp[5*i+1],ocj)){
      povratni.push_back(new Ispit(temp[5*i],temp[5*i+1],temp[5*i+2],temp[5*i+3],ocj));
    }
  }
  return povratni;
}

vector<Predmet*> Baza::ucitajPredmete(){
  vector<Predmet*> povratni;
  string red;
  ifstream infile("predmet.dat");
  if(!infile.is_open()){
    cout<<"Greska. Predmet!"<<endl;
    return povratni;
  }
  getline(infile,red);
  vector<string> temp=rastavi(red);
  for(int i=0;i<temp.size()/10;++i){
    povratni.push_back(new Predmet(temp[10*i],temp[10*i+1],temp[10*i+2],temp[10*i+3],stringUBroj(temp[10*i+4]),stringUBroj(temp[10*i+5]),stringUBroj(temp[10*i+6]),stringUBroj(temp[10*i+7]),stringUBroj(temp[10*i+8]),stringUBroj(temp[10*i+9])));
  }
  return povratni;
}

vector<stProgram*> Baza::ucitajPrograme(){
  vector<stProgram*> povratni;
  string red;
  ifstream infile("studijskiProgram.dat");
  if(!infile.is_open()){
    cout<<"Greska. St Program"<<endl;
    return povratni;
  }
  getline(infile,red);
  vector<string> temp=rastavi(red);
  for(int i=0;i<temp.size()/2;++i){
    povratni.push_back(new stProgram(temp[2*i],temp[2*i+1]));
  }
  return povratni;
}

vector<Usmjerenje*> Baza::ucitajUsmjerenja(){
  vector<Usmjerenje*> povratni;
  string red;
  ifstream infile("usmjerenje.dat");
  if(!infile.is_open()){
    cout<<"Greska. Usmjerenje."<<endl;
    return povratni;
  }
  getline(infile,red);
  vector<string> temp=rastavi(red);
  for(int i=0;i<temp.size()/3;++i){
    povratni.push_back(new Usmjerenje(temp[3*i],temp[3*i+1],temp[3*i+2]));
  }
  return povratni;
}

void Baza::printOpcije(){
  cout<<endl;
  cout<<"Ponudjene opcije:"<<endl;
  cout<<" 1. Pregled postojecih podataka"<<endl;
  cout<<" 2. Unos novog podatka u bazu"<<endl;
  cout<<" 3. Izmjena postojecih podataka"<<endl;
  cout<<" 4. Brisanje postojecih podataka"<<endl;
  cout<<" 5. Izlaz"<<endl;
  cout<<endl;
}
void Baza::printPodOpcije(int o){
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

void Baza::print(int o){
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

void Baza::spremiPodatke(){}

bool Baza::kreirajProgram(){
  string skr,naziv;
  cout<<"Unesite skracenicu od 2 slova:"<<endl;
  cin>>skr;
  if(skr.length()!=2){
    cout<<"Skracenica mora biti duzine 2!"<<endl;
    return false;
  }
  cout<<"Unesite naziv studijskog programa:"<<endl;
  cin.clear();
  getline(cin,naziv);
  _studijskiProgrami.push_back(new stProgram(skr,naziv));
  return false;
}

bool Baza::kreirajPredmet(){
  string skr,naziv,stProg,usmjerenje;
  int sem,sp,sa,sl,ects,intgrupa;
  cout<<"Unesite skracenicu i naziv predmeta:"<<endl;
  cout<<"NAPOMENA: skracenica mora biti duzine 2!"<<endl;
  cin>>skr;
  cin.clear();
  getline(cin,naziv);
  if(skr.length()!=2){
    cout<<"Skracenica mora biti duzine 2!"<<endl;
    return false;
  }
  cin.clear();
  cout<<"Unesite skracenicu st.programa i usmjerenja (oba moraju biti duzine 2)"<<endl;
  cin>>stProg>>usmjerenje;
  if(stProg.length()!=2 || usmjerenje.length()!=2){
    cout<<"Moraju biti duzine 2!"<<endl;
    return false;
  }
  cin.clear();
  cout<<"Unesite semestar, sate predavanja, sate AV, sate LV, ects i interesnu grupu"<<endl;
  cout<<"NAPOMENA: semestar mora biti od 1 do 8, interesna grupa mora biti od 1 do 4!"<<endl;
  cin>>sem>>sp>>sa>>sl>>ects>>intgrupa;
  if(sem<1||sem>9||intgrupa<1||intgrupa>4){
    cout<<"Pogresan unos semestra ili interesne grupe!"<<endl;
    return false;
  }
  _predmeti.push_back(new Predmet(skr,naziv,stProg,usmjerenje,sem,sp,sa,sl,ects,intgrupa));
  return true;
}

bool Baza::kreirajNastavnika(){
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

bool Baza::kreirajStudenta(){
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

bool Baza::kreirajIspit(){
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

void Baza::kreiraj(int o){
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


