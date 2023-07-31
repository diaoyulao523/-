// Singleton.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "../Commond.h"
#include <mutex>
#include <atomic>
#include <vector>
#include <future>
#include <chrono>
#include <thread>

using namespace std::chrono_literals;

//非线程安全
class Singleton
{
private:
	Singleton()
	{
		MY_PRINT1();
	}
	Singleton(const Singleton&) = delete;

public:
	static Singleton* getInstance()  
	{    
		if (nullptr == m_sigleton)
		{
			m_sigleton = new Singleton();
		}
		return m_sigleton;
	}
	static Singleton* m_sigleton;
};
Singleton* Singleton::m_sigleton = nullptr;







//线程安全,但效率低下
std::mutex g_mutex;
class Singleton2
{
private:
	Singleton2()
	{
		MY_PRINT1();
	}
	Singleton2(const Singleton2&) = delete;

public:
	static Singleton2* getInstance()
	{
		const std::lock_guard<std::mutex> lock(g_mutex);
		if (nullptr == m_sigleton)
		{
			m_sigleton = new Singleton2();
		}
		return m_sigleton;
	}
	static Singleton2* m_sigleton;
};
Singleton2* Singleton2::m_sigleton = nullptr;







//双检查锁但需要考虑 memory order问题所以不一定线程安全
class Singleton3
{
private:
	Singleton3()
	{
		MY_PRINT1();
	}
	Singleton3(const Singleton3&) = delete;


public:
	static Singleton3* getInstance()
	{
		if (nullptr == m_sigleton)
		{
			const std::lock_guard<std::mutex> lock(g_mutex);
			if(nullptr == m_sigleton)
			{
				m_sigleton = new Singleton3();
			}
		}
		return m_sigleton;
	}
	static Singleton3* m_sigleton;
};
Singleton3* Singleton3::m_sigleton = nullptr;








//C++11 支持memory_order 其他语言 volatile
class Singleton4
{
private:
	Singleton4()
	{
		MY_PRINT1();
	}
	~Singleton4() {}

public:
	static Singleton4* getInstance()
	{
		Singleton4* tmp = m_sigleton.load(std::memory_order_relaxed);
		std::_Atomic_thread_fence(std::memory_order_acquire);
		if (nullptr == tmp)
		{
			const std::lock_guard<std::mutex> lock(g_mutex);
			tmp = m_sigleton.load(std::memory_order_relaxed);
			if (nullptr == tmp)
			{
				tmp = new Singleton4();
				std::_Atomic_thread_fence(std::memory_order_release);
				m_sigleton.store(tmp, std::memory_order_relaxed);
			}
		}
		return m_sigleton;
	}
	static std::atomic<Singleton4*> m_sigleton;
};
std::atomic<Singleton4*> Singleton4::m_sigleton = nullptr;






//局部静态变量 线程安全
class Singleton5
{
private:
	Singleton5()
	{
		MY_PRINT1();
	}
	Singleton5(const Singleton5&) = delete;

public:
	static Singleton5* getInstance()
	{
		static Singleton5 sigleton;
		return &sigleton;
	}

};


void func()
{
	Singleton::getInstance();	

	Singleton2::getInstance();
	Singleton3::getInstance();
	Singleton4::getInstance();
	Singleton5::getInstance();
}

int main()
{
	std::vector<std::future<void>> vf;

	for (size_t i = 0; i <5; i++)
	{
		vf.push_back(std::async(func));

	}
	for (auto& f : vf) {
		f.get();
	}
	system("pause");
	
    return 0;
}

