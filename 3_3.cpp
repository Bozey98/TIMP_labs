#include <iostream>

class Queue
{
private:
	int* quptr;
	int size;
	int top;
public:
	Queue();
	Queue(const int& size);
	~Queue();

	void add(const int& val);
	bool checkFull()const;
	void pop();
	void print()const;
	int get()const;

};
Queue::Queue()
{
	quptr = new int[4]();
	top = 0;
	size = 4;
}

Queue::Queue(const int& _size)
{
	quptr = new int[_size]();
	top = 0;
	size = _size;
}

Queue::~Queue()
{
	delete[] quptr;
}


bool Queue::checkFull()const
{
	return (top >= size);
}

void Queue::add(const int& val)
{
	if (size == 0)
	{
		delete[] quptr;
		quptr = new int[1]();
		quptr[0] = val;
		++size;
		return;
	}
	
	
	if (!top && !quptr[0])
	{
		quptr[0] = val;
		return;
	}
	++top;
	if (checkFull())
	{
		int* ptr = new int[size + 1]();
		for (int i = 0; i < size; i++)
			ptr[i] = quptr[i];
		delete[] quptr;
		quptr = ptr;
		++size;
		quptr[top] = val;
	}
	else
	{
		quptr[top] = val;
	}
}


 void Queue::pop()
{
	if (top)
	{
		int* ptr = new int[size - 1];
		for (int i = 0; i < size - 1; i++)
			ptr[i] = quptr[i + 1];
		delete[] quptr;
		quptr = ptr;
		--size;
		--top;
	}
	else
	{
		std::cout << "Now queue is empty!\n";
		if (top == 0)
		{
			delete[] quptr;
			quptr = nullptr;
			size = 0;
		}
	}
}

 void Queue::print()const
 {
	 if (size)
	 {
		 for (int i = 0; i < size; i++)
			 std::cout << quptr[i] << "\t";
		 std::cout << "\n";
	 }
	 else std::cout << "Queue is empty!";
 }

int Queue::get()const
{
	return quptr[top];
}

