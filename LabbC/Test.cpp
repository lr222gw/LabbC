#include "Test.h"
#include <iostream>
#include <string>

using namespace std;
void testing() {
	
	cout << "Lägger till Bokstäver från 1 till 8, expand körs vid 5" << endl;
	Queue<int> *myIntQueue = new Queue<int>(5);

	myIntQueue->enqueue(1);
	myIntQueue->enqueue(2);
	myIntQueue->enqueue(3);
	myIntQueue->enqueue(4);
	myIntQueue->enqueue(5);
	myIntQueue->enqueue(6);
	

	myIntQueue->enqueue(7);
	myIntQueue->enqueue(8);
	cout << "Printar ut allt som lagts in och tar bort det (dequeue)" << endl;
	for (int i = (myIntQueue->getStart()-1); i > (myIntQueue->getEnd() - 1); i--) {
		std::cout << to_string(myIntQueue->dequeue()) << endl;
	}

	cout << "Efter att gjort dequeue på alla våra element så testar vi front, då det ej finns några element bör vi få 'empty queue'" << endl;
	try {
		std::cout << to_string(myIntQueue->front()) << endl;
	}
	catch (char* e) {
		std::cout << e << endl;
	}
	
	cout << "Lägger till Bokstäver från A till H" << endl;
	Queue<char> *myCharQueue = new Queue<char>(5);
	myCharQueue->enqueue('A');
	myCharQueue->enqueue('B');
	myCharQueue->enqueue('C');
	myCharQueue->enqueue('D');
	myCharQueue->enqueue('E');
	myCharQueue->enqueue('F');
	myCharQueue->enqueue('G');
	myCharQueue->enqueue('H');

	cout << "Printar ut Bokstäverna som vi satte in" << endl;
	for (int i = myCharQueue->getStart()-1; i > myCharQueue->getEnd() - 1; i--) {
		std::cout << (myCharQueue->dequeue()) << endl;
	}
	cout << "Testar att hämta från en Kö utan element" << endl;
	try {
		std::cout << (myCharQueue->front()) << endl;
	}
	catch (char* e) {
		std::cout << e << endl;
	}

	cout << "Lägger till Elementet I" << endl;
	myCharQueue->enqueue('I');
	cout << "Printar elementet som är längst fram i listan, men ta inte bort" << endl;
	std::cout << (myCharQueue->front()) << endl;

	cout << "Använder dequeue på mina element i lsitan och printar ut dessa, ingen 'Empty Queue' här" << endl;
	
	try {
		std::cout << (myCharQueue->dequeue()) << endl;
	}
	catch (char *e) {
		cout << e << endl;
	}

	

	cout << "Lägger in A,B,C i listan" << endl;
	myCharQueue->enqueue('A');
	myCharQueue->enqueue('B');
	myCharQueue->enqueue('C');
	cout << "Printar ut Innehållet med dequeue, får inte 'Empty queue'" << endl;

	try {
		std::cout << (myCharQueue->dequeue()) << endl;
		std::cout << (myCharQueue->dequeue()) << endl;
		std::cout << (myCharQueue->dequeue()) << endl;
	}
	catch (char *e) {
		cout << e << endl;
	}

	

	cout << "Lägger in A,B,C i listan och sedan kör jag en Deque för att ta bort A " << endl;
	myCharQueue->enqueue('A');
	myCharQueue->enqueue('B');
	myCharQueue->enqueue('C');
	myCharQueue->dequeue();

	cout << "Testar tilldelningsoperatorn" << endl;
	
	Queue<char> copyTo;
	copyTo = *myCharQueue;
	
	cout << "Printar ut Innehållet med dequeue från min 'copyTo' kö, ingen 'Empty queue'" << endl;
	for (int i = copyTo.getStart(); i > copyTo.getEnd() ; i--) {
		try {
			std::cout << (copyTo.dequeue()) << endl;
		}
		catch (char *e) {
			cout << e << endl;
		}

	}

	cout << "Lägger in D,E,F i listan i myCharQueue, kör en Deque för att ta bort B" << endl;
	myCharQueue->enqueue('D');
	myCharQueue->enqueue('E');
	myCharQueue->enqueue('F');
	myCharQueue->dequeue();

	////////////////////////
	try {
		for (int i = myCharQueue->getStart(); i > myCharQueue->getEnd() - 1; i--) {
			std::cout << (myCharQueue->dequeue()) << endl;
		}
	}
	catch (char * e) {
		cout << e << endl;
	}
	
	////////////////////////


	cout << "Testar tilldelningsoperatorn, lägger till A,B,C, och tar bort A; så B och C ska komma ut" << endl;
	myCharQueue->enqueue('A');
	myCharQueue->enqueue('B');
	myCharQueue->enqueue('C');
	std::cout << "Tar bort : " << myCharQueue->dequeue() << endl;
	std::cout << "Först nu är : " << myCharQueue->front() << endl;
	//Queue<char> * copyTo = new Queue<char>(3);
	Queue<char> copyTo2(*myCharQueue);
	
	cout << "Printar ut Innehållet med dequeue från min 'copyTo2' kö, ingen 'Empty Queue'" << endl;
	std::cout << (copyTo2.dequeue()) << endl;
	std::cout << (copyTo2.dequeue()) << endl;
	//for (int i = copyTo2.getStart()-1; i > copyTo2.getEnd()-1; i--) {
	//	try {
	//		std::cout << (copyTo2.dequeue()) << endl;
	//	}
	//	catch (char *e) {
	//		cout << e << endl;
	//	}
	//
	//}

	
	delete myIntQueue;

	delete myCharQueue;
	
}