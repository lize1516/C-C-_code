#include<iostream>
using namespace std;

template<int _inst>
class Malloc_alloc_template
{
private:
	//以下函数用来处理内存不足的情况
	static void* _S_oom_malloc(size_t);
	static void* _S_oom_realloc(void*, size_t);

	static void(*_Malloc_alloc_oom_handler)();   //内存不足处理例程

public:
	//空间配置函数
	static void* allocate(size_t _n)
	{
		//用malloc申请空间
		void* _result = malloc(_n);
		//如果申请空间失败，则调用_S_oom_malloc重新申请空间
		if (_result == NULL) 
			_result = _S_oom_malloc(_n);

		return _result;
	}

	//空间重配置函数
	static void* reallocate(void* _p/*, size_t*/, size_t _new_sz)
	{
		void* _result = realloc(_p, _new_sz);
		if (_result == NULL)
			_result = _S_oom_realloc(_p, _new_sz);

		return _result;
	}

	//空间释放函数
	static void deallocate(void* _p, size_t)
	{
		free(_p);
	}
	//该函数重新指定了内存分配异常处理函数，并返回了原有的内存分配异常处理函数
	//该函数接受一个“返回值和参数均为空的函数指针”作为参数
	//该函数最后返回一个“返回值和参数均为空的函数指针”
	static void(*_set_malloc_handler( void(*_f)() ))()
	{
		void(*_old)() = _Malloc_alloc_oom_handler;
		//重新指定内存分配异常处理函数
		_Malloc_alloc_oom_handler = _f;
		//返回原有的内存分配异常处理函数
		return _old;
	}
};

template<int _inst>
//内存不足处理例程，初值为0，待用户自定义，考虑内存不足时的应变措施
void(*Malloc_alloc_template<_inst>::_Malloc_alloc_oom_handler)() = 0;

template<int _inst>
//申请空间失败时调用_S_oom_malloc重新申请空间
void* Malloc_alloc_template<_inst>::_S_oom_malloc(size_t n)
{
	//定义一个函数指针_my_malloc_handler
	void(*_my_malloc_handler)();
	void* _result;
	
	for (;;)
	{
		_my_malloc_handler = _Malloc_alloc_oom_handler;
		if (_my_malloc_handler == 0)
		{
			_THROW_BAD_ALLOC;
		}
		//调用内存不足处理例程，尝试释放空间
		(*_my_malloc_handler)();
		_result = malloc(n);
		if (_result != NULL)
			return _result;
	}
}

template<int _inst>
//重新配置空间失败时调用_S_oom_realloc申请空间
void* Malloc_alloc_template<_inst>::_S_oom_realloc(void* _p,size_t n)
{
	//定义一个函数指针_my_malloc_handler
	void(*_my_malloc_handler)();
	void* _result;

	for (;;)
	{
		_my_malloc_handler = _Malloc_alloc_oom_handler;
		if (_my_malloc_handler == 0)
		{
			_THROW_BAD_ALLOC;
		}
		//调用内存不足处理例程，尝试释放空间
		(*_my_malloc_handler)();

		_result = realloc(_p,n);
		if (_result != NULL)
			return _result;
	}
}

//由于参数_inst在这里没有排上用场，因此定义为数值0
typedef Malloc_alloc_template<0> malloc_alloc;
