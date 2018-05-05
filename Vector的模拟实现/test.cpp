#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include"Vector.h"
using namespace std;

#if 0
int main()
{
	//test();
	//test2();
	//test3();
	//test4();
	test5();

	system("pause");
	return 0;
}
#endif

#if 1
template<class T,class Container=Vector<T>>
class Stack
{
public:
	void  Push(const T&x)
	{
		_c.PushBack(x);
	}
	void Pop()
	{
		_c.PopBack();
	}
	const T&Top()
	{
		return _c.Back();
	}
	int Size()
	{
		return _c.Size();
	}
	bool Empty()
	{
		return _c.Empty();
	}
private:
	Container _c;
};

int main()
{
		Stack<int, Vector<int>> s;
		s.Push(1);
		s.Push(2);
		s.Push(3);
		s.Push(4);
		s.Push(6);

		cout << s.Size() << endl;
		cout << s.Top() << endl;
	system("pause");
	return 0;
}

//int mian()
//{
//	Stack<int, Vector<int>> s;
//	s.Push(1);
//	s.Push(2);
//	s.Push(3);
//	s.Push(4);
//
//	cout << s.Size() << endl;
//
//	system("pause");
//	return 0;
//}




#endif