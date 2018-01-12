#ifndef _FUNKCIJE_H
#define _FUNKCIJE_H
#include "student.h"
#include "nastavnik.h"
#include "ispit.h"
#include "predmet.h"
#include "stProgram.h"
#include "usmjerenje.h"
#include <memory>
#include <vector>
#include <sstream>
#include <iostream>
#include <fstream>
using namespace std;

int stringUBroj(const string &tekst){
  stringstream ss(tekst);
  int rezultat;
  return ss >> rezultat ? rezultat : 0;
}

bool provjeriIspit(string jmbg,int ocj){
  if(jmbg.length()==13 && ocj>=6 && ocj<=10) return true;
  else return false;
}

bool provjeriStudenta(string jmbg,string program){
  if(jmbg.length()==13 && program.length()==2) return true;
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

vector<Student*> kreirajStudente(){
  string red;
  vector<Student*> povratni;
  vector<string> temp;
  ifstream infile("student.dat");
  if(!infile.is_open()){
    cout<<"Greska. Student!"<<endl;
    return povratni;
  }
  getline(infile,red);
  temp=rastavi(red);
  for(int i=0;i<temp.size()/5;++i){
    if(provjeriStudenta(temp[5*i],temp[5*i+4])){
      povratni.push_back(new Student(temp[5*i+1],temp[5*i+2],temp[5*i],temp[5*i+3],temp[5*i+4]));
    }
  }
  return povratni;  
}

bool provjeriNastavnika(string jmbg){
  if(jmbg.length()==13) return true;
  else return false;
}

vector<Nastavnik*> kreirajNastavnike(){
  string red;
  vector<Nastavnik*> povratni;
  vector<string> temp;
  ifstream infile("nastavnik.dat");
  if(!infile.is_open()){
    cout<<"Greska. Nastavnik!"<<endl;
    return povratni;
  }
  getline(infile,red);
  temp=rastavi(red);
  for(int i=0;i<temp.size()/5;++i){
    if(provjeriNastavnika(temp[5*i])){
      povratni.push_back(new Nastavnik (temp[5*i+1],temp[5*i+2],temp[5*i],temp[5*i+3],temp[5*i+4]));

    }
  }
  return povratni;
}

vector<Ispit*> kreirajIspite(){
  string red;
  vector<Ispit*> povratni;
  vector<string> temp;
  ifstream infile("ispit.dat");
  if(!infile.is_open()){
    cout<<"Greska. Ispit!"<<endl;
    return povratni;
  }
  getline(infile,red);
  temp=rastavi(red);
  for(int i=0;i<temp.size()/5;++i){
    int ocj=stringUBroj(temp[5*i+4]);
    if(provjeriIspit(temp[5*i+1],ocj)){
      povratni.push_back(new Ispit(temp[5*i],temp[5*i+1],temp[5*i+2],temp[5*i+3],ocj));
    }
  }
  return povratni;
}

vector<Predmet*> kreirajPredmete(){
  string red;
  vector<Predmet*> povratni;
  vector<string> temp;
  ifstream infile("predmet.dat");
  if(!infile.is_open()){ 
    cout<<"Greska. Predmet!"<<endl;
    return povratni;
  }
  getline(infile,red);
  temp=rastavi(red);
  for(int i=0;i<temp.size()/10;++i){
    povratni.push_back(new Predmet(temp[10*i],temp[10*i+1],temp[10*i+2],temp[10*i+3],stringUBroj(temp[10*i+4]),stringUBroj(temp[10*i+5]),stringUBroj(temp[10*i+6]),stringUBroj(temp[10*i+7]),stringUBroj(temp[10*i+8]),stringUBroj(temp[10*i+9])));
  }
  return povratni;
}

vector<stProgram*> kreirajStPrograme(){
  string red;
  vector<stProgram*> povratni;
  vector<string> temp;
  ifstream infile("studijskiProgram.dat");
  if(infile.is_open()){
    getline(infile,red);
    temp=rastavi(red);
    for(int i=0;i<temp.size()/2;++i){
      povratni.push_back(new stProgram(temp[2*i],temp[2*i+1]));
    }
  }
  return povratni;
}

vector<Usmjerenje*> kreirajUsmjerenja(){
  string red;
  vector<Usmjerenje*> povratni;
  vector<string> temp;
  ifstream infile("usmjerenje.dat");
  if(infile.is_open()){
    getline(infile,red);
    temp=rastavi(red);
    for(int i=0;i<temp.size()/3;++i){
      povratni.push_back(new Usmjerenje(temp[3*i],temp[3*i+1],temp[3*i+2]));
    }
  }
  return povratni;
}
#endif

