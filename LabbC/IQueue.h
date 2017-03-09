#ifndef IQUEUE_H
#define IQUEUE_H
template <typename T>
class IQueue
{
public:
	virtual void enqueue(const T& element) = 0;		// lägger till element i kön.
	virtual T dequeue() throw(...) = 0;				// tar bort och returnerar det element som är först i kön. Undantag ska hanteras.
	virtual T front() const throw(...) = 0;			// returnerar det element som är först i kön. Undantag ska hanteras.	
	virtual bool isEmpty() const = 0;				// returnerar sant om kön är tom, annars falskt.
};
#endif