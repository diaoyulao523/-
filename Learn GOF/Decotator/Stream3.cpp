#pragma once
#include "stdafx.h"
#include "Stream.cpp"


class DecotatorStream: public Stream
{
protected:
	Stream *m_stm;
	DecotatorStream(Stream*s) :m_stm(s) {}
};

// �� �ļ��������������ڴ��� ������


class CryptoStream3 :public DecotatorStream
{
public:
	CryptoStream3(Stream*s) :DecotatorStream(s) {}
	virtual ~CryptoStream3() {}

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
class BufferStream3 :public DecotatorStream
{
public:
	BufferStream3(Stream*s) :DecotatorStream(s) {}
	virtual ~BufferStream3()
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