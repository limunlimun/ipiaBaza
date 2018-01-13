#ifndef _STPROG_H
#define _STPROG_H

#include <string>

class stProgram{
  private:
    std::string _skr;
    std::string _naziv;
  public:
    stProgram()=default;
    stProgram(std::string skr,std::string naziv):_skr(skr),_naziv(naziv){};
    ~stProgram()=default;
    stProgram(stProgram & s){
      _skr=s._skr;
      _naziv=s._naziv;
    }
    stProgram(const stProgram &s){
      _skr=s._skr;
      _naziv=s._naziv;
    }

    void operator=(const stProgram & s){
      _skr=s._skr;
      _naziv=s._naziv;
    }
    void operator=(stProgram && s){
      _skr=s._skr;
      _naziv=s._naziv;
    }

    std::string getSkr(){
      return _skr;
    }
    std::string getNaziv(){
      return _naziv;
    }

    void setSkr(std::string x){
      _skr=x;
    }
    void setNaziv(std::string x){
      _naziv=x;
    }

    bool operator==(const stProgram& s){
      if(_skr==s._skr && _naziv==s._naziv) return true;
      else return false;
    }

    std::string print(){
      return _skr+"#"+_naziv+"#";
    }
};
#endif
