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

	void expand();

public:

	Queue(int capacity = 2);
	~Queue();
	Queue(const Queue<T> &origObj);
	Queue operator=(const Queue<T> &origObj);

	void enqueue(const T& element);		// lägger till element i kön.
	T dequeue()throw(…);				// tar bort och returnerar det element som är först i kön. Undantag ska hanteras.
	T front() const throw(…);			// returnerar det element som är först i kön. Undantag ska hanteras.	
	bool isEmpty() const;				// returnerar sant om kön är tom, annars falskt.
};
#endif

template<typename T>
void Queue<T>::expand()
{
	this->capacity *= 2;
	T *temp = new T[this->capacity];

	for (int i = 0; i < this->nrOfElements; i++) {
		temp[i] = this->elements[i];
	}

	this->elements = temp;
}

template<typename T>
Queue<T>::Queue(int capacity)
{
	this->nrOfElements = 0;
	this->capacity = capacity;
	this->elements = new T[this->capacity];
}

template<typename T>
Queue<T>::~Queue()
{
	delete[] this->elements;
}

template<typename T>
inline Queue<T>::Queue(const Queue<T>& origObj)
{
	this->capacity = origObj.capacity;
	this->nrOfElements = origObj.nrOfElements;
	this->elements = new T[origObj.capacity];
	for (int i = 0; i < origObj.nrOfElements; i++) {
		this->elements[i] = origObj.elements[i];
	}
}

template<typename T>
Queue<T> Queue<T>::operator=(const Queue<T>& origObj)
{
	if (this != origObj) {
		delete[] this->elements;

		this->capacity = origObj.capacity;
		this->nrOfElements = origObj.nrOfElements;
		this->elements = new T[origObj.capacity];
		for (int i = 0; i < origObj.nrOfElements; i++) {
			this->elements[i] = origObj.elements[i];
		}
	}
}

template<typename T>
inline bool Queue<T>::isEmpty() const
{
	return (this->nrOfElements == 0 );
}
