#ifndef _PREDMET_H
#define _PREDMET_H

#include <string>
#include <sstream>

class Predmet{
  private:
    std::string _skr;
    std::string _naziv;
    std::string _stProg;
    std::string _usmjerenje;
    int _semestar;
    int _satiPred;
    int _satiAV;
    int _satiLV;
    int _ects;
    int _intGrupa;//godina
  public:
    Predmet()=default;
    Predmet(std::string skr,std::string naz,std::string stP,std::string usm,int sem,int sp,int sa,int sl,int ects,int god):_skr(skr),_naziv(naz),_stProg(stP),_usmjerenje(usm),_semestar(sem),_satiPred(sp),_satiAV(sa),_satiLV(sl),_ects(ects),_intGrupa(god){};
    ~Predmet()=default;
    Predmet(Predmet & p){
      _skr=p._skr;
      _naziv=p._naziv;
      _stProg=p._stProg;
      _usmjerenje=p._usmjerenje;
      _semestar=p._semestar;
      _satiPred=p._satiPred;
      _satiAV=p._satiAV;
      _satiLV=p._satiLV;
      _ects=p._ects;
      _intGrupa=p._intGrupa;
    }
    Predmet(const Predmet &p){
      _skr=p._skr;
      _naziv=p._naziv;
      _stProg=p._stProg;
      _usmjerenje=p._usmjerenje;
      _semestar=p._semestar;
      _satiPred=p._satiPred;
      _satiAV=p._satiAV;
      _satiLV=p._satiLV;
      _ects=p._ects;
      _intGrupa=p._intGrupa;
    }

    void operator=(const Predmet & p){
      _skr=p._skr;
      _naziv=p._naziv;
      _stProg=p._stProg;
      _usmjerenje=p._usmjerenje;
      _semestar=p._semestar;
      _satiPred=p._satiPred;
      _satiAV=p._satiAV;
      _satiLV=p._satiLV;
      _ects=p._ects;
      _intGrupa=p._intGrupa;
    }
    void operator=(Predmet && p){
      _skr=p._skr;
      _naziv=p._naziv;
      _stProg=p._stProg;
      _usmjerenje=p._usmjerenje;
      _semestar=p._semestar;
      _satiPred=p._satiPred;
      _satiAV=p._satiAV;
      _satiLV=p._satiLV;
      _ects=p._ects;
      _intGrupa=p._intGrupa;
    }

    std::string getSkr(){
      return _skr;
    }
    std::string getNaziv(){
      return _naziv;
    }
    std::string getStProg(){
      return _stProg;
    }
    std::string getUsmjerenje(){
      return _usmjerenje;
    }
    int getSemestar(){
      return _semestar;
    }
    int getSatiPred(){
      return _satiPred;
    }
    int getSatiAV(){
      return _satiAV;
    }
    int getSatiLV(){
      return _satiLV;
    }
    int getEcts(){
      return _ects;
    }
    int getIntGrupa(){
      return _intGrupa;
    }

    void setSkr(std::string x){
      _skr=x;
    }
    void setNaziv(std::string x){
      _naziv=x;
    }
    void setStProg(std::string x){
      _stProg=x;
    }
    void setUsmjerenje(std::string x){
      _usmjerenje=x;
    }
    void setSemestar(int x){
      _semestar=x;
    }
    void setSatiPred(int x){
      _satiPred=x;
    }
    void setSatiAV(int x){
      _satiAV=x;
    }
    void setSatiLV(int x){
      _satiLV=x;
    }
    void setEcts(int x){
      _ects=x;
    }
    void setIntGrupa(int x){
      _intGrupa=x;
    }

    bool operator==(const Predmet & p){
      if(_skr==p._skr&&_naziv==p._naziv&&_stProg==p._stProg && _usmjerenje==p._usmjerenje&&_semestar==p._semestar&&_satiPred==p._satiPred &&_satiAV==p._satiAV && _satiLV==p._satiLV && _ects==p._ects && _intGrupa==p._intGrupa) return true;
      else return false;
    }

    std::string printPredmet(){
      std::ostringstream semestar;
      std::ostringstream sp;
      std::ostringstream sa;
      std::ostringstream sl;
      std::ostringstream ects;
      std::ostringstream intg;
      semestar<<_semestar;
      sp<<_satiPred;
      sa<<_satiAV;
      sl<<_satiLV;
      ects<<_ects;
      intg<<_intGrupa;
      return _skr+"#"+_naziv+"#"+_stProg+"#"+_usmjerenje+"#"+semestar.str()+"#"+sp.str()+"#"+sa.str()+"#"+sl.str()+"#"+ects.str()+"#"+intg.str()+"#";
    }


};

#endif
