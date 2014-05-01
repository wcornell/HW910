#include <iostream>
#include "Simulator.h"

using namespace std;

int main(){

  Simulator S;
  S.setup(10);
  S.doAllEvents();
  
  
return 0;
}
