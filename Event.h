/* Event class */

#ifndef EVENT_H
#define EVENT_H
#include <iostream>
#include <sstream>

class Event {
public:
    Event(int id = 0, double time = -1.0){id_ = id;time_ = time;};
    virtual ~Event(){};
    int id();
    double time() const;
    void setTime(double time);
    
    bool operator<(Event &other);
    bool operator<=(Event &other);
    bool operator>(Event &other);
    bool operator>=(Event &other);
    bool operator==(Event &other);
    
    virtual std::string str() const;
    virtual void execute();
    
protected:
    int id_;
    double time_;
};
#endif // EVENT_H

