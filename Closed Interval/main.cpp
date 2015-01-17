#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;


class Point {
public:
	Point() {
		_point = INT_MAX;
		_isStart = false;
	}

	Point (int time, bool isStart) {
		_point = time;
		_isStart = isStart;
	}

	void setTime(int time) {_point = time;}
	int getTime() { return _point;}

	void setStart(bool isStart) {_isStart = isStart;}
	int getStart() { return _isStart;}

private: 
	int _point;
	bool _isStart;
};

class Event {
public:
	Event() {
		_start = _end = NULL;
	}

	Event(int start, int end) {
		_start = new Point(start, true);
		_end = new Point(end,false);
	}
	
	int getStartTime() { return _start->getTime(); };
	int getEndTime() {return _end->getTime(); }
	Point * getStart() { return _start; }
	Point * getEnd() {return _end;}

	// order by start
	bool operator<(Event &rhs) {
		if (_start->getTime() < rhs.getStartTime())
			return true;
		return false;
	}
	

	bool operator<(Event * rhs) {
		if (this->getStartTime() < rhs->getStartTime())
			return true;
		return false;
	}

	friend ostream& operator<< (ostream& os, Event& aEvent) {
		cout << "(" << aEvent.getStartTime() << "," << aEvent.getEndTime() << ")";
		return os;
	}

private:
	Point * _start;
	Point * _end;
};

void printEventChain(vector<Event*> stEvent) {
	for (vector<Event*>::iterator it = stEvent.begin(); it != stEvent.end(); it++) {
		cout << *(*it) << endl; 
	}

}

bool EventComparePointer(Event * fEvent, Event * sEvent) {
	return !(*fEvent < *sEvent);	
}

void addClosedEvent(vector<Event*> stEvent, Event * newEvent) {

	vector<Point*> stPoint;

	stEvent.push_back(newEvent);

	sort(stEvent.begin(), stEvent.end(), EventComparePointer);

	printEventChain(stEvent);

	Event * eventPop = stEvent.back();
	stEvent.pop_back();

	stPoint.push_back(eventPop->getStart());
	stPoint.push_back(eventPop->getEnd());


	while(!stEvent.empty() ) {
		eventPop = stEvent.back();
		stEvent.pop_back();

		if (eventPop->getStartTime() > stPoint.back()->getTime()) {
			//if (stPoint.back()->getStart() == false) { //end time
				stPoint.push_back(eventPop->getStart());
				stPoint.push_back(eventPop->getEnd());
			//} else { //start time
				
			//}
		} else {
			if (stPoint.back()->getTime() > eventPop->getEndTime()) {
				//
			} else {
				stPoint.pop_back();
				stPoint.push_back(eventPop->getEnd());
			}
		}

	}

	cout << "Result: " << endl;

	while(!stPoint.empty()) {
		Point * endPoint = stPoint.back();
		stPoint.pop_back();
		
		Point * startPont = stPoint.back();
		stPoint.pop_back();

		Event * aEvent = new Event(startPont->getTime(), endPoint->getTime());
		cout << *aEvent << endl;
		delete(aEvent);
	}
}



int main() {
	vector<Event *> stEvent;
	Event * e1 = new Event(0,2);
	Event * e2 = new Event(2,9);
	Event * e3 = new Event(7,7);
	Event * e4 = new Event(9,12);
	
	Event * newEvent = new Event(13,14);

	stEvent.push_back(e1);
	stEvent.push_back(e2);
	stEvent.push_back(e3);
	stEvent.push_back(e4);

	addClosedEvent(stEvent,newEvent);

	return 0;
}

