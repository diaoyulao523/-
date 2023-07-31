#pragma once
#include "stdafx.h"
#include "Stream.cpp"

// 对 文件流、网络流、内存流 做加密


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


// 对 文件流、网络流、内存流 做缓存
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


// 对 文件流、网络流、内存流 先加密再做缓存
/*

     构造 BufferStream 传CryptoStream对象即可

*/