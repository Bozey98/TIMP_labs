#include <iostream>

using namespace std;
class List
{
private:
	
	int* list;
	int size;

public:
	List();
	List(const int& value);
	~List();
	void add(int num,  int value);
	void del(int num);
	void output()const;
	int get(int num);
};

List::List()
{
	list = new int[5]();
	size = 5;
}
List::List(const int& value)
{
	list = new int[value]();
	size = value;
}
List::~List()
{
	delete[] list;
}
void List::add(int num,  int value)
{
	if (num >= size)
	{
		int* ptr = new int [num+1]();
		for (int i = 0; i < size; i++)
			ptr[i] = list[i];
		delete[] list;
		list = ptr;
		size = num+1;
		list[num] = value;
	}
	else
	{
		list[num] = value;
	}
}


void List::del(int num)
{
	if (num < size)
	{
		int j = 0;
		int* ptr = new int[size - 1]();
		for (int i = 0; i < size; i++)
		{
			if (num == i)
				continue;
			ptr[j] = list[i];
			++j;
		}
		delete[] list;
		list = ptr;
		size--;
	}
	else {
		cout << "List is empty!";
	}
}

void List::output()const
{
	if (size)
	{

		for (int i = 0; i < size; i++)
			cout << list[i] << "\t";
		cout << "\nSIZE *" << size << "*" << "\n\n";
	}
	else
	{
		cout << "List is empty!";
	}
}

int List::get(int num)
{
	if (num < size)
		return list[num];
	else
	{
		cout << "Error";
		exit(1);
	}
}