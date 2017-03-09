#ifndef QUEUE_H
#define QUEUE_H

#include "IQueue.h"

template <typename T>
class Queue : public IQueue<T>
{
private:
	T * elements;				//För att vi vill ha en dynamisk allokerad array av typen "T" 
	int nrOfElements;
	int capacity;
	int start;
	int end;
	void expand();

public:

	Queue(int capacity = 2);
	~Queue();
	Queue(const Queue<T> &origObj);
	Queue<T> &operator=(const Queue<T> &origObj);

	int getNrOfElements() const;
	int getStart() const;
	int getEnd() const;

	void enqueue(const T& element);		// lägger till element i kön.
	T dequeue()throw(...);				// tar bort och returnerar det element som är först i kön. Undantag ska hanteras.
	T front() const throw(...);			// returnerar det element som är först i kön. Undantag ska hanteras.	
	bool isEmpty() const;				// returnerar sant om kön är tom, annars falskt.
};
#endif

template<typename T>
void Queue<T>::expand()
{
	this->capacity *= 2;
	T *temp = new T[this->capacity];

	for (int i = 0; i < this->capacity; i++) {
		temp[i] = -1;
	}
	
	for (int i = 0; i < this->nrOfElements; i++) {
		
		//temp[(this->capacity-1) - i] = this->elements[(this->nrOfElements-1) - i];
		temp[(this->capacity - 1) - i] = this->elements[this->start - i];
	}
	
	this->start = this->capacity - 1;
	this->end = (this->capacity - this->nrOfElements)-1;

	delete[] this->elements;

	this->elements = temp;
}

template<typename T>
Queue<T>::Queue(int capacity)
{
	this->nrOfElements = 0;
	this->capacity = capacity;
	this->elements = new T[this->capacity];

	for (int i = 0; i < this->capacity; i++) {
		this->elements[i] = -1;
	}

	this->start = this->capacity - 1;
	this->end = this->capacity - this->nrOfElements;
}

template<typename T>
Queue<T>::~Queue()
{
	delete[] this->elements;
}

template<typename T>
Queue<T>::Queue(const Queue<T>& origObj)
{
	this->start = origObj.start+1;
	this->end = origObj.end+1;
	this->capacity = origObj.capacity;
	this->nrOfElements = origObj.nrOfElements;
	this->elements = new T[origObj.capacity];
	//for (int i = this->start; i > this->end; i--) {
	//	this->elements[i] = T(origObj.elements[i]);
	//}

	for (int i = this->capacity-1; i > this->end; i--) {
		this->elements[i] = T(origObj.elements[i-1]);
	}

	this->start = this->capacity - 1;
	this->end = this->capacity - this->nrOfElements;
}

template<typename T>
Queue<T> & Queue<T>::operator=(const Queue<T> &origObj)
{

	if (this != &origObj) {
		delete[] this->elements;

		this->start = origObj.start;
		this->end = origObj.end;
		this->capacity = origObj.capacity;
		this->nrOfElements = origObj.nrOfElements;
		this->elements = new T[origObj.capacity];
		for (int i = this->start; i > this->end; i--) {
			this->elements[i] =  T(origObj.elements[i]);
		}
	}
	return *this;
}

template<typename T>
int Queue<T>::getNrOfElements() const
{
	return this->nrOfElements;
}

template<typename T>
int Queue<T>::getStart() const
{
	return this->start;
}

template<typename T>
int Queue<T>::getEnd() const
{
	return this->end;
}

template<typename T>
void Queue<T>::enqueue(const T & element)
{
	if (this->capacity == this->nrOfElements) {
		this->expand();//TODO: Kolla så att Expand Fugnerar...
	}

	// 10 obj i listan
	// 15 platser
	// - ,-  ,-  ,-  ,-  ,10 ,9  ,8  ,7  ,6   ,5   ,4   ,3   ,2  ,1
	//[0],[1],[2],[3],[4],[5],[6],[7],[8],[9],[10],[11],[12],[13],[14]	= Capacity = 15; arrayIndex = 14; 15-10 = 5 ; 5+ elements! 
	//
	// obs 11 läggs in på första platsen..
	// - ,-  ,-  ,-  ,11 ,10 ,9  ,8  ,7  ,6   ,5   ,4   ,3   ,2  ,1
	//[0],[1],[2],[3],[4],[5],[6],[7],[8],[9],[10],[11],[12],[13],[14]
	//				   ^- (15-11 = 4)
	//						   ^- Vi ska lägga in något på den 11 platsen.
	if (this->nrOfElements == 0) {
		this->start = this->capacity - 1;
		this->end   = this->capacity - 1;
	}
	this->nrOfElements++;
	this->end--;
	
	this->elements[(this->capacity - this->nrOfElements)] = element;

}

template<typename T>
T Queue<T>::dequeue() throw(...)
{
	
	if (this->isEmpty()) {
		throw "Empty Queue";
	}

	T firstInLine = this->elements[start];

	this->start--;
	this->nrOfElements--; 
	return firstInLine;
	
}

template<typename T>
T Queue<T>::front() const throw(...)
{
	if (this->isEmpty()) {
		throw "Empty Queue";
	}
	//this->start = this->nrOfElements - this->capacity;
	return this->elements[this->capacity - this->nrOfElements];
}

template<typename T>
bool Queue<T>::isEmpty() const
{
	return (this->nrOfElements == 0 );
}
