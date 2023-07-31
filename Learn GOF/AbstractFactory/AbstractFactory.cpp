// AbstractFactory.cpp : 定义控制台应用程序的入口点。
//
#pragma once
#include "stdafx.h"
#include "../Commond.h"
#include <vector>


class IDBConnect
{
public:
	virtual ~IDBConnect()
	{}
	virtual void connect() = 0;
};

class IDBCommand
{
public:
	virtual ~IDBCommand()
	{}
	virtual void exec(IDBConnect* con) = 0;
};

class IDBReader
{
public:
	virtual ~IDBReader()
	{}
	virtual void read(IDBConnect* con)=0;
};




class MysqlDBConnnect: public IDBConnect
{
public:
	void connect()
	{
		MY_PRINT1();
	}
};

class MysqlDBCommand : public IDBCommand
{
public:
	void exec(IDBConnect* con)
	{
		MY_PRINT1();
	}
};

class MysqlDBReader : public IDBReader
{
public:
	void read(IDBConnect* con)
	{
		MY_PRINT1();
	}
};


class OracleDBConnnect : public IDBConnect
{
public:
	void connect()
	{
		MY_PRINT1();
	}
};

class OracleDBCommand : public IDBCommand
{
public:
	void exec(IDBConnect* con)
	{
		MY_PRINT1();
	}
};

class OracleDBReader : public IDBReader
{
public:
	void read(IDBConnect* con)
	{
		MY_PRINT1();
	}
};


class SqliteDBConnnect : public IDBConnect
{
public:
	void connect()
	{
		MY_PRINT1();
	}
};

class SqliteDBCommand : public IDBCommand
{
public:
	void exec(IDBConnect* con)
	{
		MY_PRINT1();
	}
};

class SqliteDBReader : public IDBReader
{

public:
	void read(IDBConnect* con)
	{
		MY_PRINT1();
	}
};





class EmployeDAO2
{


public:
	std::vector<std::string> employe()
	{
		IDBConnect *con = new MysqlDBConnnect();
		IDBCommand *cmd = new MysqlDBCommand();
		cmd->exec(con);
		IDBReader *reader = new MysqlDBReader();
		reader->read(con);
	}
};







