#include "baza.h"

#include <unistd.h>
#include <cstdlib>
using namespace std;

int main(){
  Baza b;
  int izlaz=0;
  int opcija=0;
  int podopcija=0;
  cout<<"Baza podataka IPI akademije"<<endl;
  while(!izlaz){
    b.printOpcije();
    cin>>opcija;
    if(opcija==5){
      b.spremiPodatke();
      break;
    }
    b.printPodOpcije(opcija);
    cin.clear();
    cin>>podopcija;
    if(opcija==1){
      b.print(podopcija);
    }else if(opcija==2){
      b.kreiraj(podopcija);
    }else if(opcija==3){
      b.izmijeni(podopcija);
    }
    cin.clear();
    opcija=0;
    podopcija=0;
  }

  return 0;
}
