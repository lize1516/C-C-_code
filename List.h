#include<iostream>
using namespace std;

template<class T>
struct ListNode
{
	ListNode(const T& data = T())
	: _pPre(0)
	, _pNext(0)
	, _data(data)
	{}

	ListNode* _pPre;
	ListNode* _pNext;
	T _data;
};

//template<class T>
//class ListIterator
//{
//	typedef ListIterator Self;
//public:
//	ListIterator()
//		: _pCur(0)
//	{}
//
//	ListIterator(ListNode* pCur)
//		: _pCur(pCur)
//	{
//	}
//
//	ListIterator(const Self& s)
//		: _pCur(s._pCur)
//	{}
//
//	Ref operator*()
//	{
//		return _pCur->_data;
//	}
//
//	Ptr operator->()
//	{
//		return &(operator*());
//		//return &(_pCur->_data); 
//	}
//
//	Self& operator++()
//	{
//		_pCur = _pCur->_pNext;
//		return*this;
//	}
//
//	Self operator++(int)
//	{
//		Self temp(*this);
//		_pCur = _pCur->_pNext;
//		return temp;
//	}
//
//	Self& operator--()
//	{
//		_pCur = _pCur->_pPre;
//		return*this;
//	}
//
//	Self operator--(int)
//	{
//		Self temp(*this);
//		_pCur = _pCur->_pPre;
//		return temp;
//	}
//
//	bool operator!=(const Self& s)
//	{
//		return _pCur != s._pCur;
//	}
//
//	bool operator==(const Self& s)
//	{
//		return _pCur == s._pCur;
//	}
//
//	ListNode* _pCur;
//};

template<class T>
class List
{
public:
	/*typedef ListIterator Iterator;*/
	typedef ListNode<T> Node;
public:
	List()
		: _pHead(new Node)
	{
		_pHead->_pNext = _pHead;
		_pHead->_pPre = _pHead;
	}

	// 1 2 3 4 5 
	List(const T* array, size_t size)
		:_pHead(new Node)
	{
		_pHead->_pNext = _pHead;
		_pHead->_pPre = _pHead;
		for (size_t i=0; i < size; i++)
			PushBack(array[i]);
	}
	List(const List<T>& l)
		:_pHead(new Node(l._pHead->_data))
	{
		_pHead->_pNext = _pHead;
		_pHead->_pPre = _phead;
		Node*ret = l._pHead->_pNext;
		while ((l._pHead!= ret)
		{
			PushBack(ret->_data);
			ret = ret->_pNext;
		}
	}
	List& operator=(const List<T>& l)
	{
		if (*this != l)
		{
			_pHead = new Node(l._pHead->_data);
			_pHead->_pNext = _pHead;
			_pHead->_pPre = _pHead;
			Node* ret = l._pHead->_pNext;
			while (ret != l._pHead)
			{
				PushBack(ret->_data);
				ret = ret->_pNext;
			}
		}
		return *this;
	}
	~List();

		///////////////////////////////////////////////////// 
	/*Iterator Begin()
	{
		return Iterator(_pHead->_pNext);
	}

	Iterator End()
	{
		return Iterator(_pHead->_pPre);
	}*/
	/////////////////////Modify////////////////////////// 
	void PushBack(const T& d);
		void PopBack();
		void PushFront(const T& d);
		void PopFront();
		/*Iterator Insert(Iterator pos, const T& d);
		Iterator Erase(Iterator pos);*/
		bool Empty()const;
		size_t Size()const;
		T& Front();
		const T& Front()const;
		T& Back();;
		const T& Back()const;
		void Clear();
		friend ostream& operator<<(ostream &_cout, List<T>&v)      //ÖØÔØÊä³öÔËËã·û
		{
			Node*ret = _pHead->_pNext;
			while (ret != _pHead)
			{
				_cout << ret->_data << " ";
				ret = ret->_pNext;
			}
			return _cout;
		}
private:
	ListNode* _pHead;
};

template <class T>
void List<T>::PushBack(const T& d)
{
	Node* newNode = new Node(d);

	_pHead->_pPre->_pNext=newListNode;
	newListNode->_pPre = _pHead->_pPre;
	newListNode->_pNext = _pHead;
	_pHead->_pPre = newListNode;
}
template <class T>
void List<T>::PopBack()
{
	if (_pHead == _pHead->_pNext)
		return;

	_pHead->_pPre = _pHead->_pPre->_pPre;
	delete (_pHead->_pPre->_pNext);
	_pHead->_pPre->_pNext = _pHead;

}
template <class T>
void List<T>::PushFront(const T& d)
{
    Node* newNode = new Node(d);
	
	newNode->_pNext = _pHead->_pNext;
	newNode->_pNext->_pPre = newNode;
	_pHead->_pNext = newNode;
	newNode->_pPre = _pHead;

}
template <class T>
void List<T>::PopFront()
{
	if (_pHead == _pHead->_pNext)
		return;
	Node* ret = _pHead->_pNext;
	_pHead->_pNext = ret->_pNext;
	ret->_pNext->_pPre = _pHead;
	delete ret;
	ret = NULL;

}
//Iterator Insert(Iterator pos, const T& d);
//Iterator Erase(Iterator pos);
//bool Empty()const;
//size_t Size()const;
//T& Front();
//const T& Front()const;
//T& Back();;
//const T& Back()const;
//void Clear();

void test1()
{
	List<int> v;
	v.PushBack(1);
	v.PushBack(2);
	v.PushBack(3);
	v.PushBack(4);
	cout << v << endl;
}