#include "Test.h"
#include <iostream>
#include <string>

using namespace std;
void testing() {


	Queue<int> myIntQueue = Queue<int>(5);
	myIntQueue.enqueue(1);
	myIntQueue.enqueue(2);
	myIntQueue.enqueue(3);
	myIntQueue.enqueue(4);
	myIntQueue.enqueue(5);
	myIntQueue.enqueue(6);
	myIntQueue.enqueue(7);
	myIntQueue.enqueue(8);

	for (int i = 0; i < myIntQueue.getNrOfElements();i++) {
		std::cout << to_string(myIntQueue.dequeue()) << endl;
	}
	
}