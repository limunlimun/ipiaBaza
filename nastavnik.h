#ifndef _NASTAVNIK_H
#define _NASTAVNIK_H
#include "osoba.h"

class Nastavnik : public Osoba{
  private:
    std::string _zvanje;
    std::string _predmet;
  public:
    Nastavnik()=default;
    Nastavnik(std::string ime,std::string prezime,std::string jmbg,std::string zvanje,std::string predmet):Osoba(ime,prezime,jmbg),_zvanje(zvanje),_predmet(predmet){};
    ~Nastavnik()=default;
    Nastavnik(Nastavnik &s){
      Osoba(s.getIme(),s.getPrezime(),s.getJMBG());
      _zvanje=s._zvanje;
      _predmet=s._predmet;
    }
    Nastavnik(const Nastavnik & s){
      setIme(s.getIme());
      setPrezime(s.getPrezime());
      setJMBG(s.getJMBG());
      _zvanje=s._zvanje;
      _predmet=s._predmet;
    }

    void operator=(const Nastavnik & s){
      setIme(s.getIme());
      setPrezime(s.getPrezime());
      setJMBG(s.getJMBG());
      _zvanje=s._zvanje;
      _predmet=s._predmet;
    }
    void operator=(Nastavnik && s){
      setIme(s.getIme());
      setPrezime(s.getPrezime());
      setJMBG(s.getJMBG());
      _zvanje=s._zvanje;
      _predmet=s._predmet;
    }

    std::string getZvanje(){
      return _zvanje;
    }
    std::string getPredmet(){
      return _predmet;
    }

    void setZvanje(std::string x){
      _zvanje=x;
    }
    void setPredmet(std::string x){
      _predmet=x;
    }

    bool operator==(const Nastavnik& s){
      if(getIme()==s.getIme() && getPrezime()==s.getPrezime() && getJMBG()==s.getJMBG() && _zvanje==s._zvanje && _predmet==s._predmet) return true;
      else return false;
    }

    std::string printNastavnik()const{
      return getJMBG()+"#"+getIme()+"#"+getPrezime()+"#"+_zvanje+"#"+_predmet+"#";
    }
};



#endif 
