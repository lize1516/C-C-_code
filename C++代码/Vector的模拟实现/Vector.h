
#include<iostream>
#include<assert.h>
using namespace std;


template<class T>
class Vector
{
public:
	typedef T* Iterator;
public:
	Vector()           //�޲ι��캯��
	{
		_start = NULL;
		_finish =0;
		_endOfstorage = 0;
	}
	Vector(const T* array, size_t size)    //�вι��캯��
	{
		_start = new T[size];
		_finish = _start+size;
		_endOfstorage = _start + size;
	
		if (_start!=NULL)
		for (size_t i = 0; i < size; i++)
		{
			_start[i] = array[i];
		}
	}
	Vector(const Vector& v)          //�������캯��
	{
		size_t sz = v.Size();
		T*newV = new T[sz];
		for (size_t i = 0; i < sz; i++)
		{
			newV[i]= v._start[i];
		}
		_start = newV;
		_finish = _start + sz;
		_endOfstorage = _finish;
	}
	Vector& operator=(const Vector& s)      //��ֵ���������
	{
		if (this != &s)
		{
			delete[]_start;
			_start = new T[s.Capacity()];
			for (size_t i = 0; i < s.Size(); i++)
			{
				_start[i] = s._start[i];
			}
			_finish = _start + s.Size();
			_endOfstorage = _start + s.Capacity();
		}
		return *this;
	}
	~Vector()             //��������
	{
		if (_start != NULL)
			delete[]_start;
		_start = _finish = _endOfstorage = 0;
	}

		////////////////////////////////////////////////// 
	Iterator Begin()
	{
		return _start;
	}
	Iterator End()
	{
		return _finish;
	}
	void PushBack(const T& data);    //β�庯��
	void PopBack();                  //βɾ����
	void Insert(size_t pos, const T& data);      //ָ��λ�ò���
	void Erase(size_t pos);           //ָ��λ��ɾ��

		///////////////////////////////////////////// 
	size_t Size()const            //��ȡԪ�ظ���
	{
		return _finish - _start;
	}
	size_t Capacity()const       //��ȡ��������
	{
		return _endOfstorage - _start;
	}
	bool Empty()const            //�пպ���
	{
		return (_start == _finish);
	}
	void Resize(size_t newSize, const T& data = T())        //����Ԫ�ظ�������
	{
		size_t sz = Size();
		if (newSize <=sz)
		{
			_finish = _start + newSize;
		}
		else if ((newSize>sz) && (newSize <=Capacity()))
		{
			_finish = _start + newSize;
			for (size_t i = sz; i < newSize; i++)
			{
				_start[i] = data;
			}
		}
		else if (newSize>Capacity())
		{
			T*ret = new T[newSize];
			if (ret != NULL)
			{
				for (size_t i = 0; i < sz; i++)
					ret[i]= _start[i];
				for (size_t j = sz; j < newSize; j++)
					ret[j] = data;
				delete[]_start;
				_start = ret;
				_finish = _start + newSize;
				_endOfstorage = _start + newSize;
			}
		}
	}

		//////////////////////////////////////// 
	T& operator[](size_t index);             //�±�����
	const T& operator[](size_t index)const;  //����һ�гɶԳ���
	T& Front();            //��ȡ��Ԫ��
	const T& Front()const; //����һ�гɶԳ���
	T& Back();              //��ȡ���һ��Ԫ��
	const T& Back()const;   //����һ�гɶԳ���
	void Clear();         //���
	template<class T>
	friend ostream& operator<<(ostream &_cout, Vector<T>&v)      //������������
	{
		for (size_t i = 0; i <v.Size() ; i++)
		{
			_cout << v._start[i] << " ";
		}
		return _cout;
	}

private:
	void _CheckCapacity()            //�ж��Ƿ���Ҫ����
	{
		int capacity = Capacity();
		int sz = Size();
		if (sz>=capacity)
		{
			T* temp = new T[capacity * 2 + 3];
				for (int i = 0; i < sz; i++)
				{
					temp[i] = _start[i];
				}
				delete[]_start;
		    	_start = temp;
				_finish = temp + sz;
				_endOfstorage = temp + (capacity + 3);
		}
	}

private:
	T* _start;
	T* _finish;
	T* _endOfstorage;
};

template<class T>
void Vector<T>::PushBack(const T& data)
{
	_CheckCapacity();
	*_finish = data;
	_finish++;
}
template<class T>
void Vector<T>::PopBack()
{
	assert(_start);
	_finish--;
}
template<class T>
void Vector<T>::Insert(size_t pos, const T& data)
{
	_CheckCapacity();
	int sz = Size();
	for (size_t i = sz; i < pos; i++)
	{
		_start[i] = _start[i-1];
	}
	_start[pos] = data;
	_finish++;
}
template<class T>
void Vector<T>::Erase(size_t pos)
{
	if (_start == NULL)
		return;
	size_t sz = Size();
	for (size_t i = pos; i < sz-1; i++)
	{
		_start[i] = _start[i + 1];
	}
	_finish--;
}

//////////////////////
template <class T>
T& Vector<T>::operator[](size_t index)
{
	if ((index>=0)&&(index<=Size()))
	return _start[index];
}
template <class T>
const T& Vector<T>::operator[](size_t index)const
{
	if ((index >= 0) && (index <= Size()))
	return _start[index];
}
template <class T>
T& Vector<T>::Front()
{
	if (_start!=NULL)
	return *_start;
}
template <class T>
const T& Vector<T>::Front()const
{
	if (_start!=NULL)
	return *_start;
}
template <class T>
T& Vector<T>::Back()
{
	if (_start != NULL)
	return *(_finish - 1);
}
template <class T>
const T& Vector<T>::Back()const
{
	if (_start != NULL)
	return *(_finish - 1);
}
template <class T>
void Vector<T>::Clear()
{
	if (_start == NULL)
		return;
	delete[]_start;
	_start = _finish = _endOfstorage = 0;
}


////////////////////////////////////////////////////���Ժ���
//void test()
//{
//	int arr[] = { 1, 2, 3, 4 };
//	Vector<int> v(arr,sizeof(arr)/sizeof(arr[0]));
//	cout << v.Size() << endl;;
//	cout << v.Capacity() << endl;
//
//	v.PushBack(7);
//	v.PushBack(8);
//	v.PushBack(9);
//	v.PushBack(10);
//	cout << v << endl;
//	cout << v.Size() << endl;
//	cout << v.Capacity() << endl;
//
//	v.PopBack();
//	cout << v << endl;
//
//	v.Insert(1, 0);
//	cout << v << endl;
//
//	v.Erase(3);
//	cout << v << endl;
//
//	v.Resize(20, 1);
//	cout << v << endl;
//
//	v.Resize(5, 1);
//	cout << v << endl;
//}
//void test2()
//{
//	int arr[] = { 1, 2, 3, 4 };
//	Vector<int> v(arr, sizeof(arr) / sizeof(arr[0]));
//	v.PushBack(7);
//	v.PushBack(8);
//	v.PushBack(9);
//	v.PushBack(10);
//	cout << v << endl;
//
//	cout << v.Front() << endl;
//	cout << v.Back() << endl;
//	v.Clear();
//	cout << "���" << endl;
//	cout << v << endl;
//}
//void test3()
//{
//	int arr[] = { 1, 2, 3, 4 };
//	Vector<int> v(arr, sizeof(arr) / sizeof(arr[0])),v2;
//	v.PushBack(7);
//	v.PushBack(8);
//	cout << v << endl;
//
//	cout << "v2 = ";
//	v2 = v;
//	cout << v2 << endl;
//}
//
//void test4()
//{
//	int arr[] = { 1, 2, 3, 4 };
//	Vector<int> v(arr, sizeof(arr) / sizeof(arr[0])), v2(v),v3;
//	v2.PushBack(7);
//	v3 = v2;
//	cout << v << endl;
//	cout << v2 << endl;
//	cout << v2.Size() << endl;
//	cout << v2.Capacity() << endl;
//
//}
void test5()
{
	int arr[] = { 1, 2, 3, 4 };
	Vector<int>v(arr, sizeof(arr) / sizeof(arr[0])), v2;
	cout << v << endl;
	cout << v.Size() << endl;
	cout << v.Capacity() << endl;
	cout << v.Begin() << endl;
	cout << v.End() << endl;

}
