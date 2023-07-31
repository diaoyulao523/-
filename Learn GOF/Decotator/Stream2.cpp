#pragma once
#include "stdafx.h"
#include "Stream.cpp"

// �� �ļ��������������ڴ��� ������


class CryptoStream :public Stream
{
	Stream *m_stm;

public:
	CryptoStream(Stream*s) :m_stm(s) {}
	virtual ~CryptoStream() {}

	virtual void read(int num)
	{
		MY_PRINT1("%d", num);
		m_stm->read(num);
	}
	virtual void seek(int num)
	{
		MY_PRINT1("%d", num);
		m_stm->seek(num);
	}

	virtual void write(char* str, int length)
	{
		MY_PRINT1("%s %d", str, length);
		m_stm->write(str, length);
	}
};


// �� �ļ��������������ڴ��� ������
class BufferStream :public Stream
{
	Stream *m_stm;

public:
	BufferStream(Stream*s) :m_stm(s) {}
	virtual ~BufferStream()
	{}

	virtual void read(int num)
	{
		MY_PRINT1("%d", num);
		m_stm->read(num);
	}
	virtual void seek(int num)
	{
		MY_PRINT1("%d", num);
		m_stm->seek(num);
	}

	virtual void write(char* str, int length)
	{
		MY_PRINT1("%s %d", str, length);
		m_stm->write(str, length);
	}
};


// �� �ļ��������������ڴ��� �ȼ�����������
/*

     ���� BufferStream ��CryptoStream���󼴿�

*/