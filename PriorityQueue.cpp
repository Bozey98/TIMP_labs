#include <iostream>
#include <iterator>
template <typename T> class PrQueue
{
private:
	T* quptr;
	int size;
	T top;
public:
	PrQueue();
	PrQueue(const T& size);
	PrQueue(const PrQueue<T>& one);
	~PrQueue();

	void print()const;
	T operator[] (const T& num)const;
	void add(const T& val);
	bool isFull()const;
	void pop();
	T get()const;
	// void quickSort(Iterator start, Iterator end);

};
template<typename Iterator>
void quicksort(Iterator start, Iterator end)
{
	Iterator pivot = end - 1;
	Iterator j = end - 1;
	Iterator i = start;
	while (i <= j)
	{

		while (*i > *pivot)
		{
			++i;
		}
		while (*j < *pivot)
		{
			--j;
		}
		if (i <= j)
		{
			std::iter_swap(j, i);
			++i;
			--j;
		}
	}
	if (i < end)
		quicksort(i, end);
	if (start < j)
		quicksort(start, j + 1);
}

template <typename T> PrQueue<T>::PrQueue()
{
	quptr = new T[5]();
	top = 0;
	size = 5;
}

template<typename T> PrQueue<T>::PrQueue(const T& _size)
{
	quptr = new T[_size]();
	top = 0;
	size = _size;
}

template <typename T> PrQueue<T>::~PrQueue()
{
	delete[] quptr;
}

template<typename T> T PrQueue<T>::operator[](const T& num)const
{
	return quptr[num];
}

template<typename T> bool PrQueue<T>::isFull()const
{
	return (top >= size);
}

template<typename T> void PrQueue<T>::add(const T& val)
{
	if (size == 0)
	{
		delete[] quptr;
		quptr = new T[1]();
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
	if (isFull())
	{
		T* ptr = new T[size + 1]();
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

	T* i1 = &quptr[0];
	T* i2 = &quptr[top + 1];
	quicksort(i1, i2);
}

template<typename T> void PrQueue<T>::print()const
{
	if (size)
	{
		for (int i = 0; i < size; i++)
			std::cout << quptr[i] << "\t";
		std::cout << "\n";
	}
	else std::cout << "Queue is empty!";
}

template<typename T> void PrQueue<T>::pop()
{
	if (top)
	{
		T* ptr = new T[size - 1];
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

template<typename T> T PrQueue<T>::get()const
{
	return quptr[top];
}

int main()
{
	int _size, val;
	char ch = '9';
	std::cout << "Enter the size: ";
	std::cin >> _size;
	PrQueue<int> test(_size);
	while (ch != '0')
	{
		std::cout << "\n\n--------------------------------------------------------------\n" <<
			"What do you want to do?\nPress:\n\"1\" to add data\n\"2\" to delete data\n\"3\" to show last element\n\"4\" to show the stack\n\"0\" to exit\n"
			<< "--------------------------------------------------------------" << "\n\n";

		std::cin >> ch;
		std::cout << "\n";
		switch (ch)
		{
		case '1':
		{
			std::cout << "Enter the val: ";
			std::cin >> val;
			test.add(val);
			break;
		}
		case '2':
		{
			test.pop();
			break;
		}
		case '3':
		{
			std::cout << "Last element: " << test.get() << "\n";
			break;
		}

		case '4':
		{
			test.print();
			break;
		}
		}
	}


	system("pause");
	return 0;
}
