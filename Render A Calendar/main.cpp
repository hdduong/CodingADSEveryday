#include <iostream> 
#include <vector>
#include <algorithm>

using namespace std;

class Event {
public:
	Event(int start,  int end) {
		_start = start;
		_end = end;
	}

	bool Event::operator<(const Event& lhs) {
		if (getEnd() < lhs.getEnd()) //if (getEnd() <= lhs.getEnd()) will cause issue
			return true;

		return false;
	}

	
	int getStart() const {return _start;}
	int getEnd() const { return _end; }
	
	ostream& print(ostream &os) {
		os << "("<<getStart() <<"," << getEnd() << ")";
		return os;
	}
private: 
	int _start;
	int _end;
};

ostream& operator<<(ostream& os, Event& event) {
	return event.print(os);
}

bool EventPointerCompare(Event * event1, Event * event2) {
	return (*event1 < *event2);
}

bool EndPointCompare(pair<int,bool> endpoint1, pair<int,bool> endpoint2) {
	return (endpoint1.first < endpoint2.first);
}

int countConcurrency(vector<Event *> vecEvent) {
	int numCon = 0;
	int maxCon = 0;
	vector <pair <int, bool> > vecEndPoint;
	
	for (vector<Event*>::iterator it = vecEvent.begin(); it < vecEvent.end(); it++) {
		vecEndPoint.push_back(make_pair((*it)->getStart(), true));
		vecEndPoint.push_back(make_pair((*it)->getEnd(), false));
	}

	sort(vecEndPoint.begin(), vecEndPoint.end(), EndPointCompare);

	for (vector<pair<int,bool> >::iterator it = vecEndPoint.begin(); it < vecEndPoint.end(); it++) {
		if ( it->second == true) numCon = numCon + 1;
		else numCon = numCon - 1;
		
		if (maxCon < numCon) maxCon = numCon;
	}
	return maxCon;
}

int main() {

	Event * E1 = new Event(1,5);
	Event * E2 = new Event(6,10);
	Event * E3 = new Event(11,13);
	Event * E4 = new Event(14,15);
	Event * E5 = new Event(2,7);
	Event * E6 = new Event(8,9);
	Event * E7 = new Event(12,15);
	Event * E8 = new Event(4,5);
	Event * E9 = new Event(9,17);

	vector<Event *> vevent;
	vevent.push_back(E1);
	vevent.push_back(E2);
	vevent.push_back(E3);
	vevent.push_back(E4);
	vevent.push_back(E5);
	vevent.push_back(E6);
	vevent.push_back(E7);
	vevent.push_back(E8);
	vevent.push_back(E9);

	sort(vevent.begin(), vevent.end(), EventPointerCompare);

	for (vector<Event *>::iterator it = vevent.begin(); it != vevent.end(); it++) {
		cout << *(*it) << endl;
	}

	cout << endl;

	int numCon = countConcurrency(vevent);
	cout << numCon << endl;
}
