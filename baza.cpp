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

bool Baza::obrisiPredmet(int i){
  int size=_predmeti.size();
  _predmeti.erase(_predmeti.begin()+i);
  if(size>_predmeti.size())return true;
  else{
    cout<<"Greska!"<<endl;
    return false;
  }
}

bool Baza::obrisiNastavnika(int i){
  int size=_nastavnici.size();
  _nastavnici.erase(_nastavnici.begin()+i);
  if(size>_nastavnici.size()) return true;
  else{
    cout<<"Greska!"<<endl;
    return false;
  }
}

bool Baza::obrisiStudenta(int i){
  int size=_studenti.size();
  _studenti.erase(_studenti.begin()+i);
  if(size>_studenti.size()) return true;
  else{
    cout<<"Greska!"<<endl;
    return false;
  }
}

bool Baza::obrisiIspit(int i){
  int size=_ispiti.size();
  _ispiti.erase(_ispiti.begin()+i);
  if(size>_ispiti.size()) return true;
  else{
    cout<<"Greska!"<<endl;
    return false;
  }
}

void Baza::obrisi(int o){
  string kljuc;
  int i;
  if(o==1){
    cout<<"Unesite kljuc (skracenica od 2 slova):";
    cin>>kljuc;
    i=pronadjiPredmet(kljuc);
    if(i!=-1)
      if(obrisiPredmet(i))
        _izmjenapredmeti=true;
  }else if(o==2){
    cout<<"Unesite kljuc (JMBG od 13 cifara):";
    cin>>kljuc;
    i=pronadjiNastavnika(kljuc);
    if(i!=-1)
      if(obrisiNastavnika(i))
        _izmjenanastavnici=true;
  }else if(o==3){
    cout<<"Unesite kljuc (br. indexa): ";
    cin>>kljuc;
    i=pronadjiStudenta(kljuc);
    if(i!=-1)
      if(obrisiStudenta(i))
        _izmjenastudenti=true;
  }else if(o==4){
    string kljuc2,kljuc3;
    cout<<"Unesite kljuc (skracenicu predmeta datum i broj indexa):"<<endl<<"NAPOMENA: skracenica mora biti duzine 2!"<<endl;
    cin>>kljuc>>kljuc2>>kljuc3;
    i=pronadjiIspit(kljuc,kljuc2,kljuc3);
    if(i!=-1)
      if(obrisiIspit(i))
        _izmjenaispiti=true;
  }else if(o!=5){
    cout<<"Unos nije validan!"<<endl;
  }
}

int Baza::pronadjiProgram(string kljuc){
  for(int i=0;i<_studijskiProgrami.size();++i)
    if((*_studijskiProgrami[i]).getSkr()==kljuc)
      return i;
  
  cout<<"Nije pronadjeno!"<<endl;
  return -1;
}

int Baza::pronadjiPredmet(string kljuc){
  for(int i=0;i<_predmeti.size();++i)
    if((*_predmeti[i]).getSkr()==kljuc)
      return i;

  cout<<"Nije pronadjeno!"<<endl;
  return -1;
}

int Baza::pronadjiNastavnika(string kljuc){
  for(int i=0;i<_nastavnici.size();++i)
    if((*_nastavnici[i]).getJMBG()==kljuc)
      return i;

  cout<<"Nije pronadjeno!"<<endl;
  return -1;
}

int Baza::pronadjiStudenta(string kljuc){
  for(int i=0;i<_studenti.size();++i)
    if((*_studenti[i]).getBrInd()==kljuc)
      return i;

  cout<<"Nije pronadjeno!"<<endl;
  return -1;
}

int Baza::pronadjiIspit(string kljuc1,string kljuc2,string kljuc3){
  for(int i=0;i<_ispiti.size();++i){
    if((*_ispiti[i]).getPredmet()==kljuc1 && (*_ispiti[i]).getDatum()==kljuc2 && (*_ispiti[i]).getBrInd()==kljuc3)
      return i;
  }

  cout<<"Nije pronadjeno!"<<endl;
  return -1;
}

bool Baza::izmijeniProgram(int i){
  cin.ignore();
  cout<<"Trenutni naziv st. programa: "<<(*_studijskiProgrami[i]).getNaziv()<<endl;
  string naziv;
  cout<<"Unesite novi naziv: "<<endl;
  getline(cin,naziv);
  (*_studijskiProgrami[i]).setNaziv(naziv);
  return true;
}

bool Baza::izmijeniPredmet(int i){
  Predmet p((*_predmeti[i]));
  cout<<"Trenutna polja predmeta: "<<endl;
  cout<<"Naziv: "<<p.getNaziv()<<endl;
  cout<<"Studijski program: "<<p.getStProg()<<endl;
  cout<<"Usmjerenje: "<<p.getUsmjerenje()<<endl;
  cout<<"Semestar: "<<p.getSemestar()<<endl;
  cout<<"Sati predavanja, AV, LV"<<p.getSatiPred()<<" "<<p.getSatiAV()<<" "<<p.getSatiLV()<<endl;
  cout<<"ECTS i interesna grupa: "<<p.getEcts()<<" "<<p.getIntGrupa()<<endl;
  cout<<"Unesite novi naziv predmeta: ";
  cin.ignore();
  string naziv;
  getline(cin,naziv);
  cout<<"Unesite semestar, sate predavanja, AV, LV, ECTS i interesnu grupu(od 1 do 4):"<<endl;
  cout<<"NAPOMENA: vrijednosti su cijeli brojevi!"<<endl;
  int sem,sp,sa,sl,ects,ig;
  cin.clear();
  cin>>sem>>sp>>sa>>sl>>ects>>ig;
  if(sem<1||sem>8||ig<1||ig>4) {
    cout<<"Pogresan unos!"<<endl;
    return false;
  }
  (*_predmeti[i]).setNaziv(naziv);
  (*_predmeti[i]).setSemestar(sem);
  (*_predmeti[i]).setSatiPred(sp);
  (*_predmeti[i]).setSatiAV(sa);
  (*_predmeti[i]).setSatiLV(sl);
  (*_predmeti[i]).setEcts(ects);
  (*_predmeti[i]).setIntGrupa(ig);
  return true;
}

bool Baza::izmijeniNastavnika(int i){
  Nastavnik n((*_nastavnici[i]));
  cout<<"Trenutno ime i prezime: "<<(*_nastavnici[i]).getIme()<<" "<<(*_nastavnici[i]).getPrezime()<<endl;
  cout<<"Trenutno zvanje i predmet: "<<n.getZvanje()<<" "<<n.getPredmet()<<endl;
  string ime,prezime,zvanje,predmet;
  cout<<"Unesite novo ime prezime zvanje i predmet: ";
  cin>>ime>>prezime>>zvanje>>predmet;
  (*_nastavnici[i]).setIme(ime);
  (*_nastavnici[i]).setPrezime(prezime);
  (*_nastavnici[i]).setZvanje(zvanje);
  (*_nastavnici[i]).setPredmet(predmet);
  return true;
}

bool Baza::izmijeniStudenta(int i){
  Student s((*_studenti[i]));
  cout<<"Trenutni podaci: ime prezime jmbg st.prog"<<endl;
  cout<<(*_studenti[i]).getIme()<<" "<<(*_studenti[i]).getPrezime()<<" "<<(*_studenti[i]).getJMBG()<<" "<<s.getStProg()<<endl;
  string ime,prezime,jmbg,stp;
  cout<<"Unesite nove podatke: ime prezime jmbg st.prog"<<endl;
  cout<<"NAPOMENA: jmbg mora sadrzavati 13 cifara, a st.prog 2 slova"<<endl;
  cin>>ime>>prezime>>jmbg>>stp;
  if(jmbg.length()!=13 || stp.length()!=2){
    cout<<"Pogresan unos jmbg ili st.prog"<<endl;
    return false;
  }
  (*_studenti[i]).setIme(ime);
  (*_studenti[i]).setPrezime(prezime);
  (*_studenti[i]).setJMBG(jmbg);
  (*_studenti[i]).setStProg(stp);
  return true;
}

bool Baza::izmijeniIspit(int i){
  Ispit is((*_ispiti[i]));
  cout<<"Trenutni ocjena: "<<is.getOcjena()<<endl;
  int ocjena;
  cout<<"Unesite novu ocjenu: ";
  cin>>ocjena;
  if(ocjena<6||ocjena>10){
    cout<<"Ocjena mora biti u rasponu od 6 do 10!"<<endl;
    return false;
  }
  (*_ispiti[i]).setOcjena(ocjena);
  return true;
}

void Baza::izmijeni(int o){
  string kljuc;
  int i;
  if(o==1){
    cout<<"Unesite kljuc (skracenicu st.prog od 2 slova):"<<endl;
    cin>>kljuc;
    i=pronadjiProgram(kljuc);
    if(i!=-1)
      if(izmijeniProgram(i))
        _izmjenastprogrami=true;
  }else if(o==2){
    cout<<"Unesite kljuc (skracenicu predmeta od 2 slova):"<<endl;
    cin>>kljuc;
    i=pronadjiPredmet(kljuc);
    if(i!=-1)
      if(izmijeniPredmet(i))
        _izmjenapredmeti=true;
  }else if(o==3){
    cout<<"Unesite kljuc (jmbg 13 cifara):"<<endl;
    cin>>kljuc;
    i=pronadjiNastavnika(kljuc);
    if(i!=-1)
      if(izmijeniNastavnika(i))
        _izmjenanastavnici=true;
  }else if(o==4){
    cout<<"Unesite kljuc (br. indexa):"<<endl;
    cin>>kljuc;
    i=pronadjiStudenta(kljuc);
    if(i!=-1)
      if(izmijeniStudenta(i))
        _izmjenastudenti=true;
  }else if(o==5){
    cout<<"Unesite kljuc(skracenicu predmeta, datum i br.indexa):"<<endl;
    string kljuc2,kljuc3;
    cin>>kljuc>>kljuc2>>kljuc3;
    i=pronadjiIspit(kljuc,kljuc2,kljuc3);
    if(i!=-1)
      if(izmijeniIspit(i))
        _izmjenaispiti=true;
  }
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
    int sem;
    int br=0;
    cout<<"Unesite semestar (od 1 do 8): ";
    cin>>sem;
    if(sem<1||sem>8){
      cout<<"Pogresan unos!"<<endl;
      return;
    }
    for(int i=0;i<_predmeti.size();++i){
      if((*_predmeti[i]).getSemestar()==sem){
        cout<<(*_predmeti[i]).printPredmet()<<endl;
        ++br;
      }
    }
    if(br==0) cout<<"Nije pronadjen nijedan predmet u trazenom semestru!"<<endl;
  }
}

void Baza::spremiPodatke(){}

bool Baza::kreirajProgram(){
  string skr,naziv;
  cout<<"Unesite skracenicu od 2 slova i puni naziv st. programa: "<<endl;
  cin>>skr;
  cin.clear();
  getline(cin,naziv);
  if(skr.length()!=2){
    cout<<"Skracenica mora biti duzine 2!"<<endl;
    return false;
  }
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
  cin>>pred>>jmbg>>brind>>dat>>ocj;
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


