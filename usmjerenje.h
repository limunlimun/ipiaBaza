#ifndef _USMJERENJE_H
#define _USMJERENJE_H

#include <string>

class Usmjerenje{
  private:
    std::string _skr;
    std::string _naziv;
    std::string _stProgram;
  public:
    Usmjerenje()=default;
    Usmjerenje(std::string skr,std::string naziv,std::string prog):_skr(skr),_naziv(naziv),_stProgram(prog){};
    ~Usmjerenje()=default;
    Usmjerenje(Usmjerenje & u){
      _skr=u._skr;
      _naziv=u._naziv;
      _stProgram=u._stProgram;
    }
    Usmjerenje(const Usmjerenje &u){
      _skr=u._skr;
      _naziv=u._naziv;
      _stProgram=u._stProgram;
    }

    void operator=(const Usmjerenje & u){
      _skr=u._skr;
      _naziv=u._naziv;
      _stProgram=u._stProgram;
    }
    void operator=(Usmjerenje && u){
      _skr=u._skr;
      _naziv=u._naziv;
      _stProgram=u._stProgram;
    }

    std::string getSkr(){
      return _skr;
    }
    std::string getNaziv(){
      return _naziv;
    }
    std::string getStProg(){
      return _stProgram;
    }

    void setSkr(std::string x){
      _skr=x;
    }
    void setNaziv(std::string x){
      _naziv=x;
    }
    void setStProg(std::string x){
      _stProgram=x;
    }

    bool operator==(const Usmjerenje& u){
      if(_skr==u._skr&&_naziv==u._naziv&& _stProgram==u._stProgram)return true;
      else return false;
    }

    std::string print(){
      return _skr+"#"+_naziv+"#"+_stProgram+"#";
    }
};

#endif
