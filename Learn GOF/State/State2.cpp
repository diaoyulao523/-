#pragma once

#include "stdafx.h"
#include "../Commond.h"
#include "State2.h"





	Idle::Idle()
	{}


	 TMState * Idle::GetInstance()
	{

		static Idle instance;
		return  &instance;
	}

	 void Idle::init()
	{
		MY_PRINT1("%s", "do reset");
		MY_PRINT1("%s", "do init");
		pNextState = Ready::GetInstance();
	}

	 void Idle::test()
	{
		MY_PRINT1("%s", "do reset");
		MY_PRINT1("%s", "do init");
		MY_PRINT1("%s", "do run");
		pNextState = Run::GetInstance();
	}
	 void Idle::reset()
	{
		MY_PRINT1("%s", "do reset");
		MY_PRINT1("%s", "do init");
		pNextState = Ready::GetInstance();
	}


	Ready::Ready()
	{} 
	TMState * Ready::GetInstance()
	{

		static Ready instance;
		return  &instance;
	}

	 void Ready::init()
	{

	}
	 void Ready::test()
	{
		MY_PRINT1("%s", "do run");
		pNextState = Run::GetInstance();
	}
	void Ready::reset()
	{
	}


	Run::Run()
	{}

	 TMState * Run::GetInstance()
	{

		static Run instance;
		return  &instance;
	}

	 void Run::init()
	{

	}
	 void Run::test()
	{
		MY_PRINT1("%s", "do stop");
		pNextState = Stop::GetInstance();
	}
	 void Run::reset()
	{
	}

	 Stop::Stop()
	{}
	
	 TMState * Stop::GetInstance()
	{

		static Stop instance;
		return  &instance;
	}

	void Stop::init()
	{

	}
	void Stop::test()
	{
		MY_PRINT1("%s", "do run");
		pNextState = Run::GetInstance();
	}
	 void Stop::reset()
	{
	}


	 Abort::Abort()
	{}
	 TMState * Abort::GetInstance()
	{

		static Abort instance;
		return  &instance;
	}

	 void Abort::init()
	{
		MY_PRINT1("%s", "do reset");
		MY_PRINT1("%s", "do init");
		pNextState = Ready::GetInstance();
	}
	 void Abort::test()
	{
		MY_PRINT1("%s", "do reset");
		MY_PRINT1("%s", "do init");
		MY_PRINT1("%s", "do run");
		pNextState = Run::GetInstance();
	}
	 void Abort::reset()
	{
		MY_PRINT1("%s", "do reset");
		MY_PRINT1("%s", "do init");
		pNextState = Ready::GetInstance();
	}




	void Test1::init()
	{
		next->init();
		next = next->pNextState;

	}
	void Test1::test()
	{
		next->test();
		next = next->pNextState;
	}
	void Test1::reset()
	{
		next->reset();
		next = next->pNextState;
	}

int main()
{
	Test1 t;
	t.test();	// run
	t.test();	// stop
	t.test();	// run
	
	system("pause");
	return 0;
}