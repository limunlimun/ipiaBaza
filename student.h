#ifndef _STUDENT_H
#define _STUDENT_H
#include "osoba.h"

class Student: public Osoba{
  private:
    std::string _brInd;
    std::string _stProg;

  public:
    Student()=default;
    Student(std::string ime,std::string prezime,std::string jmbg,std::string brI,std::string stP):Osoba(ime,prezime,jmbg),_brInd(brI),_stProg(stP){};
    ~Student()=default;
    Student(Student &s){
      Osoba(s.getIme(),s.getPrezime(),s.getJMBG());
      _brInd=s._brInd;
      _stProg=s._stProg;
    }
    Student(const Student & s){
      Osoba(s.getIme(),s.getPrezime(),s.getJMBG());
      _brInd=s._brInd;
      _stProg=s._stProg;
    }

    void operator=(const Student & s){
      setIme(s.getIme());
      setPrezime(s.getPrezime());
      setJMBG(s.getJMBG());
      _brInd=s._brInd;
      _stProg=s._stProg;
    }

    void operator=(Student&& s){
      setIme(s.getIme());
      setPrezime(s.getPrezime());
      setJMBG(s.getJMBG());
      _brInd=s._brInd;
      _stProg=s._stProg;
    }

    std::string getBrInd(){
      return _brInd;
    }
    std::string getStProg(){
      return _stProg;
    }

    void setBrInd(std::string x){
      _brInd=x;
    }
    void setStProg(std::string x){
      _stProg=x;
    }

    bool operator==(const Student& x){
      if(getIme()==x.getIme()&& getPrezime()==x.getPrezime() && getJMBG()==x.getJMBG() &&_brInd==x._brInd && _stProg==x._stProg)
        return true;
      else return false;
    }
    
    std::string print(){
      return getJMBG()+"#"+getIme()+"#"+getPrezime()+"#"+_brInd+"#"+_stProg+"#";
    }

};



#endif
