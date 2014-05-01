#include <iostream>
#include "OrderedSet.h"
#include "Event.h"

using namespace std;

int main(){

  OrderedSet<Event*> S;
  Event e1;
  cout << e1.str() << endl;
  S.insert(&e1);
  string expect("[<Event 0: -1");
  cout << expect << " ?== " << S.str().substr(0, expect.length()) << endl;
  cout << ">*]" << " ?== " << S.str().substr(S.str().length() - 3, 3) << endl;
return 0;
}
