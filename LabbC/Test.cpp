#include "Test.h"
#include <iostream>
#include <string>

using namespace std;
void testing() {
	
	cout << "L�gger till Bokst�ver fr�n 1 till 8, expand k�rs vid 5" << endl;
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

	cout << "Efter att gjort dequeue p� alla v�ra element s� testar vi front, d� det ej finns n�gra element b�r vi f� 'empty queue'" << endl;
	try {
		std::cout << to_string(myIntQueue->front()) << endl;
	}
	catch (char* e) {
		std::cout << e << endl;
	}
	
	cout << "L�gger till Bokst�ver fr�n A till H" << endl;
	Queue<char> *myCharQueue = new Queue<char>(5);
	myCharQueue->enqueue('A');
	myCharQueue->enqueue('B');
	myCharQueue->enqueue('C');
	myCharQueue->enqueue('D');
	myCharQueue->enqueue('E');
	myCharQueue->enqueue('F');
	myCharQueue->enqueue('G');
	myCharQueue->enqueue('H');

	cout << "Printar ut Bokst�verna som vi satte in" << endl;
	for (int i = myCharQueue->getStart()-1; i > myCharQueue->getEnd() - 1; i--) {
		std::cout << (myCharQueue->dequeue()) << endl;
	}
	cout << "Testar att h�mta fr�n en K� utan element" << endl;
	try {
		std::cout << (myCharQueue->front()) << endl;
	}
	catch (char* e) {
		std::cout << e << endl;
	}

	cout << "L�gger till Elementet I" << endl;
	myCharQueue->enqueue('I');
	cout << "Printar elementet som �r l�ngst fram i listan, men ta inte bort" << endl;
	std::cout << (myCharQueue->front()) << endl;

	cout << "Anv�nder dequeue p� mina element i lsitan och printar ut dessa, ingen 'Empty Queue' h�r" << endl;
	
	try {
		std::cout << (myCharQueue->dequeue()) << endl;
	}
	catch (char *e) {
		cout << e << endl;
	}

	

	cout << "L�gger in A,B,C i listan" << endl;
	myCharQueue->enqueue('A');
	myCharQueue->enqueue('B');
	myCharQueue->enqueue('C');
	cout << "Printar ut Inneh�llet med dequeue, f�r inte 'Empty queue'" << endl;

	try {
		std::cout << (myCharQueue->dequeue()) << endl;
		std::cout << (myCharQueue->dequeue()) << endl;
		std::cout << (myCharQueue->dequeue()) << endl;
	}
	catch (char *e) {
		cout << e << endl;
	}

	

	cout << "L�gger in A,B,C i listan och sedan k�r jag en Deque f�r att ta bort A " << endl;
	myCharQueue->enqueue('A');
	myCharQueue->enqueue('B');
	myCharQueue->enqueue('C');
	myCharQueue->dequeue();

	cout << "Testar tilldelningsoperatorn" << endl;
	
	Queue<char> copyTo;
	copyTo = *myCharQueue;
	
	cout << "Printar ut Inneh�llet med dequeue fr�n min 'copyTo' k�, ingen 'Empty queue'" << endl;
	for (int i = copyTo.getStart(); i > copyTo.getEnd() ; i--) {
		try {
			std::cout << (copyTo.dequeue()) << endl;
		}
		catch (char *e) {
			cout << e << endl;
		}

	}

	cout << "L�gger in D,E,F i listan i myCharQueue, k�r en Deque f�r att ta bort B" << endl;
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


	cout << "Testar tilldelningsoperatorn, l�gger till A,B,C, och tar bort A; s� B och C ska komma ut" << endl;
	myCharQueue->enqueue('A');
	myCharQueue->enqueue('B');
	myCharQueue->enqueue('C');
	std::cout << "Tar bort : " << myCharQueue->dequeue() << endl;
	std::cout << "F�rst nu �r : " << myCharQueue->front() << endl;
	//Queue<char> * copyTo = new Queue<char>(3);
	Queue<char> copyTo2(*myCharQueue);
	
	cout << "Printar ut Inneh�llet med dequeue fr�n min 'copyTo2' k�, ingen 'Empty Queue'" << endl;
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