#include <iostream>
#include "Simulator.h"

using namespace std;

int main(){

  Simulator S(2);
  S.setup(1000);
  S.doAllEvents();
  
  
return 0;
}
