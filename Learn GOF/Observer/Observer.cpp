// Observer.cpp : 定义控制台应用程序的入口点。
//
#pragma once

#include "stdafx.h"
#include <stdlib.h>
#include "../Commond.h"

using namespace std;


#include <string>
#include <list>

class IProcess
{
public:
	virtual ~IProcess()
	{}
	virtual void updateProgress(float value) = 0;

};


class PrintObserver :public IProcess
{
public:
	void updateProgress(float value)
	{
		MY_PRINT1("%.3f", value);
	}
};


class ProcessbarObserver :public IProcess
{
public:
	void updateProgress(float value)
	{
		MY_PRINT1("%.3f", value);
	}
};



class FileSpliter
{
public:
	FileSpliter(const std::string & filePath, int splitNumber) :m_filePath(filePath), m_splitNumber(splitNumber)
	{
	}


	bool split()
	{
		for (size_t i = 0; i < m_splitNumber; i++)
		{
			// do split

			// update process
			onUpdateProress((i + 1.0) / m_splitNumber);
		}
		return true;
	}

	void addProcess(IProcess* process)
	{
		m_processList.push_back(process);
	}
	void removeProcess(IProcess* process)
	{
		m_processList.remove(process);
	}



private:
	std::string m_filePath;
	int m_splitNumber;
	std::list<IProcess*> m_processList;

private:
	void onUpdateProress(float value)
	{
		for (auto pro : m_processList)
		{
			if (nullptr != pro)
			{
				pro->updateProgress(value);
			}
		}
	}

};





/*

动机:
在软件构建过程中，我们需要为某些对象建立一种“通知依赖关
系” —— 一个对象（目标对象）的状态发生改变，所有的依赖对
象（观察者对象）都将得到通知。如果这样的依赖关系过于紧密，
将使软件不能很好地抵御变化。
使用面向对象技术，可以将这种依赖关系弱化，并形成一种稳定
的依赖关系。从而实现软件体系结构的松耦合。
*/


int main()
{
	PrintObserver observer;
	ProcessbarObserver observer2;


	FileSpliter spliter("xxxx", 10);
	spliter.addProcess(&observer);
	spliter.addProcess(&observer2);
	spliter.split();
	system("pause");
	return 0;

}
