#include <iostream>


using namespace std;
class Stack {

private: 
	int* stptr;
	int size;
	int top;

public:
	Stack();
	Stack(const int& size);
	~Stack();
	void print()const;
	void POP();
	int operator[] (const int& num)const;
	void add(const int& val);
	bool checkFull()const;
	int get()const;

};

Stack::Stack()
{
	stptr = new int [5]();
	top = 0;
	size = 5;
}

Stack::Stack(const int & _size)
{
	stptr = new int [_size]();
	top = 0;
	size = _size;
}

Stack::~Stack()
{
	delete[] stptr;
}

int Stack::operator[](const int& num)const
{
	return stptr[num];
}

bool Stack::checkFull()const
{
	return (top >= size);
}

void Stack::POP()
{
	if (top)
	{
		int* ptr = new int[size - 1];
		for (int i = 0; i < size - 1; i++)
			ptr[i] = stptr[i];
		delete[] stptr;
		stptr = ptr;
		--size;
		--top;
	}
	else
	{
		cout << "Now stack is empty!\n";
		if (top == 0)
		{
			delete[] stptr;
			stptr = nullptr;
			size = 0;
		}
	}
}

void Stack::add(const int& val)
{	
	if (size == 0)
	{
		delete[] stptr;
		stptr = new int [1]();
		stptr[0] = val;
		++size;
		return;
	}
	
	if (!top && !stptr[0])
	{
		stptr[0] = val;
		return;
	}

	++top;
	
	if (checkFull())
	{
		int* ptr = new int [size + 1]();
		for (int i = 0; i < size; i++)
			ptr[i] = stptr[i];
		delete[] stptr;
		stptr = ptr;
		++size;
		stptr[top] = val;
	}
	else
	{	
		stptr[top] = val;
	}
}

void Stack::print()const
{
	if (size)
	{

		for (int i = 0; i < size; i++)
			cout << stptr[i] << "\t";
		cout << "\n";
	}
	else cout << "Stack is empty!";
}


int Stack::get()const
{
	return stptr[top];
}


