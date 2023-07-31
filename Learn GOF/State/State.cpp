// State.cpp : 定义控制台应用程序的入口点。
//
#pragma once

#include "stdafx.h"
#include "../Commond.h"



enum TMState
{
	Idle,
	Ready,
	Run,
	Stop,
	Abort
};



class Test
{
private:
	TMState m_state;

	void init()
	{
		switch (m_state)
		{
		case Idle:
			MY_PRINT1("%s", "do reset");
			MY_PRINT1("%s", "do init");
			m_state = Ready;
			break;
		case Ready:
			break;
		case Run:
			break;
		case Stop:
			break;
		case Abort:
			MY_PRINT1("%s", "do reset");
			MY_PRINT1("%s", "do init");
			m_state = Ready;
			break;
		default:
			break;
		}
	}

	void test()
	{
		switch (m_state)
		{
		case Idle:
			MY_PRINT1("%s", "do reset");
			MY_PRINT1("%s", "do init");
			MY_PRINT1("%s", "do run");
			m_state = Run;
			break;
		case Ready:
			MY_PRINT1("%s", "do run");
			m_state = Run;
			break;
		case Run:
			MY_PRINT1("%s", "do stop");
			m_state = Stop;
			break;
		case Stop:
			MY_PRINT1("%s", "do run");
			m_state = Run;
			break;
		case Abort:
			MY_PRINT1("%s", "do reset");
			MY_PRINT1("%s", "do init");
			MY_PRINT1("%s", "do run");
			m_state = Run;
			break;
		default:
			break;
		}

	}

	void reset()
	{
		switch (m_state)
		{
		case Idle:
			MY_PRINT1("%s", "do reset");
			MY_PRINT1("%s", "do init");
			m_state = Ready;
			break;
		case Ready:
			break;
		case Run:
			break;
		case Stop:
			break;
		case Abort:
			MY_PRINT1("%s", "do reset");
			MY_PRINT1("%s", "do init");
			m_state = Ready;
			break;
		default:
			break;
		}

	}


};