#include <iostream>
#include "DLList.h"

using namespace std;

int main(){

	DLList<int> L;
	L.append(5);
	L.append(6);
	cout << L << endl;
	

return 0;
}
