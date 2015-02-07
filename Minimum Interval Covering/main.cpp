#include <iostream>
#include <stdlib.h>
#include <set> // Order & BST
#include <vector>


using namespace std;

struct Interval {
	int startTime;
	int endTime;
};


Interval * createInterval(int _start, int _end) {
	Interval *newInterval = (Interval*) malloc(sizeof(Interval));
	newInterval->startTime = _start;
	newInterval->endTime = _end;

	return newInterval;
}

struct  CompareInteralEnd {
	bool operator() (Interval * lhs, Interval * rhs) {
		if (rhs != lhs) {
			return (lhs->endTime < rhs->endTime);
		}
	}
};

void printSetInterval(set<Interval *,CompareInteralEnd> setInterval) {
	for (set<Interval *>::iterator it = setInterval.begin(); it != setInterval.end(); it++) {
		cout << "{" << (*it)->startTime << "," << (*it)->endTime << "} ";
	}
	cout << endl;
}

void printVector(vector<int> vVisit) {
	for (vector<int>::iterator it = vVisit.begin(); it != vVisit.end(); it++) {
		cout << *it << ", ";
	}
	cout << endl;
}


vector<int> findMinimumVisit(set<Interval*, CompareInteralEnd>& sInterval) {
	vector<int> timeVisit;
	for(set<Interval*,CompareInteralEnd>::iterator it = sInterval.begin(); it != sInterval.end(); it++) {
		
		timeVisit.emplace_back((*it)->endTime);

		//remove startTime < currentIt->endTime
		for(set<Interval*,CompareInteralEnd>::iterator itErase = sInterval.begin(); itErase != sInterval.end(); ) {
			if ( (it != itErase) && ( (*itErase)->startTime < (*it)->endTime) ) {
				sInterval.erase(itErase++);
			}
			else {
				itErase++;
			}
		}
	}

	return timeVisit;
}


/*

You should change your prefix iterator into something like this:

Iterator<T> operator++() 
{ 
    pointer = pointer->next; 
    return *this;
}
And your postfix iterator into something like this:

Iterator<T> operator++(int) 
{ 
    node<T>* previous = pointer;
    pointer = pointer->next; 
    return Iterator<T>(previous);
}


*/
int main() {

	vector<Interval *> vInterval;
	set<Interval *, CompareInteralEnd> sInterval;

	
	sInterval.emplace(createInterval(1,4));
	sInterval.emplace(createInterval(0,5));
	sInterval.emplace(createInterval(2,3));
	sInterval.emplace(createInterval(6,8));
	sInterval.emplace(createInterval(5,7));
	sInterval.emplace(createInterval(9,10));

	//printSetInterval(sInterval);

	vector<int> visit = findMinimumVisit(sInterval);
	printVector(visit);

	return 0;
}