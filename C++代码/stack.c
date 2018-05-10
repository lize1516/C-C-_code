#include<iostream>
using namespace std;

#define NUMBER 10

template<class T>
class mystack
{
public:
	mystack()
		:size(0)
	{
		data[NUMBER] = 0;
	}
	mystack(const T* arr, int _size)
	{
		size = 0;
		int i = 0;
		for (i = 0; i<_size; i++)
		{
			data[i] = arr[i];
			size++;
		}
	}
	mystack<T>& operator =(mystack<T>& s)
	{
		if (&s != this)
		{
			int _size = s.Size();
			data[NUMBER] = 0;
			int i = 0;
			for (i = 0; i<size; i++)
			{
				data[i] = s.data[i];
				size++;
			}
		}
		return (*this);
	}


	void Push(T d)
	{
		if (size >= NUMBER)
		{
			return;
		}
		data[size] = d;
		size++;
	}
	void Pop()
	{
		if (!Empty())
		{
			size--;
		}
	}
	bool Empty()
	{
		if (size == 0)
			return true;
		else
			return false;
	}
	T Top()
	{
		if (Empty())
			return NULL;

		return data[size - 1];
		size--;
	}

	int Size()
	{
		return size;
	}
	void Swap(T*arr1, T*arr2)
	{
		T data;
		data = *arr1;
		*arr1 = *arr2;
		*arr2 = data;
	}

private:
	T data[NUMBER];
	int size;
};


int main()
{
	int arr[] = { 1, 2, 3, 4, 5 };
	int size = sizeof(arr) / sizeof(arr[0]);
	mystack<int> s(arr, size);
	mystack<int> s2;
	cout << s.Size() << endl;
	for (int i = 0; i<size; i++)
	{
		cout << s.Top() << ",";
		s.Pop();
		cout << s.Size();
		cout << endl;

	}
	s.Push(7);
	cout << s.Top() << endl;
	s.Push(8);
	cout << s.Top() << endl;
	cout << s.Size() << endl;
	
	cout << "S2:";
	cout << s2.Size() << endl;
	s2 = s;
	int ret = s.Size();
	for (int i = 0; i < ret; i++)
	{
		cout << s.Top() << ",";
		s.Pop();
	}


	system("pause");
	return 0;
}