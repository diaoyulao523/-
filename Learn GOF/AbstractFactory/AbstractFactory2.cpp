// AbstractFactory.cpp : 定义控制台应用程序的入口点。
//
#pragma once
#include "stdafx.h"
#include "../Commond.h"
#include "AbstractFactory.cpp"


class IDBConnectFactory
{
public:
	virtual ~IDBConnectFactory()
	{}
	virtual IDBConnect* create() = 0;
};

class IDBCommandFactory
{
public:
	virtual ~IDBCommandFactory()
	{}
	virtual IDBCommand* create() = 0;
};

class IDBReaderFactory
{
public:
	virtual ~IDBReaderFactory()
	{}
	virtual IDBReader* create() = 0;
};


class MysqlDBConnectFactory
{
public:
	
	virtual IDBConnect* create()
	{
		return new MysqlDBConnnect();
	}
};

class MysqlDBCommandFactory
{
public:

	virtual IDBCommand* create()
	{
		return new MysqlDBCommand();
	}
};

class MysqlDBReaderFactory
{
public:

	virtual IDBReader* create()
	{
		return new MysqlDBReader();
	}
};


class OracleDBConnectFactory
{
public:

	virtual IDBConnect* create()
	{
		return new OracleDBConnnect();
	}
};

class OracleDBCommandFactory
{
public:

	virtual IDBCommand* create()
	{
		return new OracleDBCommand();
	}
};

class OraclelDBReaderFactory
{
public:
	
	virtual IDBReader* create()
	{
		return new OracleDBReader();
	}
};


class SqliteDBConnectFactory
{
public:

	virtual IDBConnect* create()
	{
		return new SqliteDBConnnect();
	}
};

class SqliteDBCommandFactory
{
public:

	virtual IDBCommand* create()
	{
		return new SqliteDBCommand();
	}
};

class SqliteDBReaderFactory
{
public:
	
	virtual IDBReader* create()
	{
		return new SqliteDBReader();
	}
};


class EmployeDAO2
{
	IDBConnectFactory *m_dbConFac;
	IDBCommandFactory *m_dbComFac;
	IDBReaderFactory *m_dbReadFac;

public:
	std::vector<std::string> employe()
	{
		IDBConnect *con = m_dbConFac->create();
		IDBCommand *cmd = m_dbComFac->create();
		cmd->exec(con);
		IDBReader *reader = m_dbReadFac->create();
		reader->read(con);
		std::vector<std::string> employes;
		// employes.append(read data)
		return employes;
	}
};






