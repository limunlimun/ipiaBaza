#ifndef _ISPIT_H
#define _ISPIT_H
#include <string>
#include <sstream>

class Ispit{
  private:
    std::string _predmet;
    std::string _jmbgProf;
    std::string _brInd;
    std::string _datum;
    int _ocjena;
  public:
    Ispit()=default;
    Ispit(std::string pred,std::string jmbg, std::string bri,std::string dat,int ocjena):_brInd(bri),_datum(dat),_predmet(pred),_jmbgProf(jmbg),_ocjena(ocjena){};
    ~Ispit()=default;
    Ispit(Ispit &i){
      _brInd=i._brInd;
      _datum=i._datum;
      _predmet=i._predmet;
      _jmbgProf=i._jmbgProf;
      _ocjena=i._ocjena;
    }
    Ispit(const Ispit &i){
      _brInd=i._brInd;
      _datum=i._datum;
      _predmet=i._predmet;
      _jmbgProf=i._jmbgProf;
      _ocjena=i._ocjena;
    }

    void operator=(const Ispit & i){
      _brInd=i._brInd;
      _datum=i._datum;
      _predmet=i._predmet;
      _jmbgProf=i._jmbgProf;
      _ocjena=i._ocjena;
    }
    void operator=(Ispit && i){
      _brInd=i._brInd;
      _datum=i._datum;
      _predmet=i._predmet;
      _jmbgProf=i._jmbgProf;
      _ocjena=i._ocjena;
    }

    std::string getBrInd(){
      return _brInd;
    }
    std::string getDatum(){
      return _datum;
    }
    std::string getPredmet(){
      return _predmet;
    }
    std::string getJmbgProf(){
      return _jmbgProf;
    }
    int getOcjena(){
      return _ocjena;
    }

    void setBrInd(std::string x){
      _brInd=x;
    }
    void setDatum(std::string x){
      _datum=x;
    }
    void setPredmet(std::string x){
      _predmet=x;
    }
    void setJmbgProf(std::string x){
      _jmbgProf=x;
    }
    void setOcjena(int x){
      _ocjena=x;
    }

    bool operator==(const Ispit& i){
      if(_brInd==i._brInd&& _datum==i._datum&& _predmet==i._predmet && _jmbgProf==i._jmbgProf && _ocjena==i._ocjena) return true;
      else return false;
    }

    std::string printIspit(){
      std::ostringstream ocj;
      ocj<<_ocjena;
      return _predmet+"#"+_jmbgProf+"#"+_brInd+"#"+_datum+"#"+ocj.str()+"#";
    }
    
};
#endif
