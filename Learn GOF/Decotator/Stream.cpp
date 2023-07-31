#pragma once

#include "stdafx.h"
#include "../Commond.h"



class Stream
{
public:
	virtual ~Stream()
	{}

	virtual void read(int num) = 0;
	virtual void seek(int num) = 0;
	virtual void write(char*, int length) = 0;
};


class FileStream: public Stream
{
public:

	virtual ~FileStream()
	{}

	virtual void read(int num)
	{
		MY_PRINT1("%d", num);
	}
	virtual void seek(int num)
	{
		MY_PRINT1("%d", num);
	}

	virtual void write(char* str, int length) 
	{
			MY_PRINT1("%s %d", str, length);	
	}
};

class NetWorkStream :public Stream
{
public:

	virtual ~NetWorkStream()
	{}

	virtual void read(int num)
	{
		MY_PRINT1("%d", num);
	}
	virtual void seek(int num)
	{
		MY_PRINT1("%d", num);
	}

	virtual void write(char* str, int length)
	{
		MY_PRINT1("%s %d", str, length);
	}
};


class MemoryStream :public Stream
{
public:

	virtual ~MemoryStream()
	{}

	virtual void read(int num)
	{
		MY_PRINT1("%d", num);
	}
	virtual void seek(int num)
	{
		MY_PRINT1("%d", num);
	}

	virtual void write(char* str, int length)
	{
		MY_PRINT1("%s %d", str, length);
	}
};



// 采用继承方式实现
// 对 文件流、网络流、内存流 做加密

class CryptoFileStream :public FileStream
{
public:

	virtual ~CryptoFileStream()
	{}

	virtual void read(int num)
	{
		MY_PRINT1("%d", num);
		FileStream::read(num);
	}
	virtual void seek(int num)
	{
		MY_PRINT1("%d", num);
		FileStream::seek(num);
	}

	virtual void write(char* str, int length)
	{
		MY_PRINT1("%s %d", str, length);
		FileStream::write(str, length);
	}
};

class CryptoNetWorkStream :public NetWorkStream
{
public:

	virtual ~CryptoNetWorkStream()
	{}

	virtual void read(int num)
	{
		MY_PRINT1("%d", num);
		NetWorkStream::read(num);
	}
	virtual void seek(int num)
	{
		MY_PRINT1("%d", num);
		NetWorkStream::seek(num);
	}

	virtual void write(char* str, int length)
	{
		MY_PRINT1("%s %d", str, length);
		NetWorkStream::write(str, length);
	}
};


class CryptoMemoryStream :public MemoryStream
{
public:

	virtual ~CryptoMemoryStream()
	{}

	virtual void read(int num)
	{
		MY_PRINT1("%d", num);
		MemoryStream::read(num);
	}
	virtual void seek(int num)
	{
		MY_PRINT1("%d", num);
		MemoryStream::seek(num);
	}

	virtual void write(char* str, int length)
	{
		MY_PRINT1("%s %d", str, length);
		MemoryStream::write(str, length);
	}
};

// 对 文件流、网络流、内存流 做缓存

class BufferFileStream :public FileStream
{
public:

	virtual ~BufferFileStream()
	{}

	virtual void read(int num)
	{
		MY_PRINT1("%d", num);
		FileStream::read(num);
	}
	virtual void seek(int num)
	{
		MY_PRINT1("%d", num);
		FileStream::seek(num);
	}

	virtual void write(char* str, int length)
	{
		MY_PRINT1("%s %d", str, length);
		FileStream::write(str, length);
	}
};

class BufferNetWorkStream :public NetWorkStream
{
public:

	virtual ~BufferNetWorkStream()
	{}

	virtual void read(int num)
	{
		MY_PRINT1("%d", num);
		NetWorkStream::read(num);
	}
	virtual void seek(int num)
	{
		MY_PRINT1("%d", num);
		NetWorkStream::seek(num);
	}

	virtual void write(char* str, int length)
	{
		MY_PRINT1("%s %d", str, length);
		NetWorkStream::write(str, length);
	}
};


class BufferMemoryStream :public MemoryStream
{
public:

	virtual ~BufferMemoryStream()
	{}

	virtual void read(int num)
	{
		MY_PRINT1("%d", num);
		MemoryStream::read(num);
	}
	virtual void seek(int num)
	{
		MY_PRINT1("%d", num);
		MemoryStream::seek(num);
	}

	virtual void write(char* str, int length)
	{
		MY_PRINT1("%s %d", str, length);
		MemoryStream::write(str, length);
	}
};



// 对 文件流、网络流、内存流 先加密再缓存

class CryptoBufferFileStream :public FileStream
{
public:

	virtual ~CryptoBufferFileStream()
	{}

	virtual void read(int num)
	{
		MY_PRINT1("%d", num);
		FileStream::read(num);
	}
	virtual void seek(int num)
	{
		MY_PRINT1("%d", num);
		FileStream::seek(num);
	}

	virtual void write(char* str, int length)
	{
		MY_PRINT1("%s %d", str, length);	
		FileStream::write(str, length);
	}
};

class CryptoBufferNetWorkStream :public NetWorkStream
{
public:

	virtual ~CryptoBufferNetWorkStream()
	{}

	virtual void read(int num)
	{
		MY_PRINT1("%d", num);
		NetWorkStream::read(num);
	}
	virtual void seek(int num)
	{
		MY_PRINT1("%d", num);
		NetWorkStream::seek(num);
	}

	virtual void write(char* str, int length)
	{
		MY_PRINT1("%s %d", str, length);
		NetWorkStream::write(str, length);
	}
};


class CryptoBufferMemoryStream :public MemoryStream
{
public:

	virtual ~CryptoBufferMemoryStream()
	{}

	virtual void read(int num)
	{
		MY_PRINT1("%d", num);
		MemoryStream::read(num);
	}
	virtual void seek(int num)
	{
		MY_PRINT1("%d", num);
		MemoryStream::seek(num);
	}

	virtual void write(char* str, int length)
	{
		MY_PRINT1("%s %d", str, length);
		MemoryStream::write(str, length);
	}
};