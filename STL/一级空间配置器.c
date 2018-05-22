#include<iostream>
using namespace std;

template<int _inst>
class Malloc_alloc_template
{
private:
	//���º������������ڴ治������
	static void* _S_oom_malloc(size_t);
	static void* _S_oom_realloc(void*, size_t);

	static void(*_Malloc_alloc_oom_handler)();   //�ڴ治�㴦������

public:
	//�ռ����ú���
	static void* allocate(size_t _n)
	{
		//��malloc����ռ�
		void* _result = malloc(_n);
		//�������ռ�ʧ�ܣ������_S_oom_malloc��������ռ�
		if (_result == NULL) 
			_result = _S_oom_malloc(_n);

		return _result;
	}

	//�ռ������ú���
	static void* reallocate(void* _p/*, size_t*/, size_t _new_sz)
	{
		void* _result = realloc(_p, _new_sz);
		if (_result == NULL)
			_result = _S_oom_realloc(_p, _new_sz);

		return _result;
	}

	//�ռ��ͷź���
	static void deallocate(void* _p, size_t)
	{
		free(_p);
	}
	//�ú�������ָ�����ڴ�����쳣����������������ԭ�е��ڴ�����쳣������
	//�ú�������һ��������ֵ�Ͳ�����Ϊ�յĺ���ָ�롱��Ϊ����
	//�ú�����󷵻�һ��������ֵ�Ͳ�����Ϊ�յĺ���ָ�롱
	static void(*_set_malloc_handler( void(*_f)() ))()
	{
		void(*_old)() = _Malloc_alloc_oom_handler;
		//����ָ���ڴ�����쳣������
		_Malloc_alloc_oom_handler = _f;
		//����ԭ�е��ڴ�����쳣������
		return _old;
	}
};

template<int _inst>
//�ڴ治�㴦�����̣���ֵΪ0�����û��Զ��壬�����ڴ治��ʱ��Ӧ���ʩ
void(*Malloc_alloc_template<_inst>::_Malloc_alloc_oom_handler)() = 0;

template<int _inst>
//����ռ�ʧ��ʱ����_S_oom_malloc��������ռ�
void* Malloc_alloc_template<_inst>::_S_oom_malloc(size_t n)
{
	//����һ������ָ��_my_malloc_handler
	void(*_my_malloc_handler)();
	void* _result;
	
	for (;;)
	{
		_my_malloc_handler = _Malloc_alloc_oom_handler;
		if (_my_malloc_handler == 0)
		{
			_THROW_BAD_ALLOC;
		}
		//�����ڴ治�㴦�����̣������ͷſռ�
		(*_my_malloc_handler)();
		_result = malloc(n);
		if (_result != NULL)
			return _result;
	}
}

template<int _inst>
//�������ÿռ�ʧ��ʱ����_S_oom_realloc����ռ�
void* Malloc_alloc_template<_inst>::_S_oom_realloc(void* _p,size_t n)
{
	//����һ������ָ��_my_malloc_handler
	void(*_my_malloc_handler)();
	void* _result;

	for (;;)
	{
		_my_malloc_handler = _Malloc_alloc_oom_handler;
		if (_my_malloc_handler == 0)
		{
			_THROW_BAD_ALLOC;
		}
		//�����ڴ治�㴦�����̣������ͷſռ�
		(*_my_malloc_handler)();

		_result = realloc(_p,n);
		if (_result != NULL)
			return _result;
	}
}

//���ڲ���_inst������û�������ó�����˶���Ϊ��ֵ0
typedef Malloc_alloc_template<0> malloc_alloc;
