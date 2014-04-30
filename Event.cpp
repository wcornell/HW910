#include "Event.h"

using namespace std;

/* Comparison operators for Event class
post: return true or false
*/
bool Event::operator<(Event &other){
    return( time_<other.time() );
}
bool Event::operator<=(Event &other){
    return( time_<=other.time() );
}
bool Event::operator>(Event &other){
    return( time_>other.time() );
}
bool Event::operator>=(Event &other){
    return( time_>=other.time() );
}
bool Event::operator==(Event &other){
	return( time_==other.time() );
}

string Event::str() const{
	// post: returns the string representation of the Event object
    stringstream os;
    os << "<Event " << id_ << ": " << time_ << ">";
    return os.str();
}

void Event::execute(){
	cout << this->str() << endl;
}
int Event::id(){return id_;}
double Event::time() const{return time_;}
void Event::setTime(double time){time_=time;}
