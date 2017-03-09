#ifndef IQUEUE_H
#define IQUEUE_H
template <typename T>
class IQueue
{
public:
	virtual void enqueue(const T& element) = 0;		// l�gger till element i k�n.
	virtual T dequeue() throw(...) = 0;				// tar bort och returnerar det element som �r f�rst i k�n. Undantag ska hanteras.
	virtual T front() const throw(...) = 0;			// returnerar det element som �r f�rst i k�n. Undantag ska hanteras.	
	virtual bool isEmpty() const = 0;				// returnerar sant om k�n �r tom, annars falskt.
};
#endif