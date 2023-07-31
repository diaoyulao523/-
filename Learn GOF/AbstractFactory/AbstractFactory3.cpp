// AbstractFactory.cpp : 定义控制台应用程序的入口点。
//
#pragma once
#include "stdafx.h"
#include "../Commond.h"
#include "AbstractFactory.cpp"



class DBFactory
{
public:
	virtual ~DBFactory()
	{}
	virtual IDBConnect * createCon() = 0;
	virtual IDBCommand * createCom() = 0;
	virtual IDBReader * createRead() = 0;
};


class MysqlDBFactory:public DBFactory
{
public:

	virtual IDBConnect * createCon()
	{
		return new MysqlDBConnnect();
	}
	virtual IDBCommand * createCom()
	{
		return new MysqlDBCommand();
	}
	virtual IDBReader * createRead()
	{
		return new MysqlDBReader();
	}
};


class OracleDBFactory:public DBFactory
{
public:
	virtual IDBConnect * createCon()
	{
		return new OracleDBConnnect();
	}
	virtual IDBCommand * createCom()
	{
		return new OracleDBCommand();
	}
	virtual IDBReader * createRead()
	{
		return new OracleDBReader();
	}
};

class SqliteDBFactory :public DBFactory
{
public:
	virtual IDBConnect * createCon()
	{
		return new SqliteDBConnnect();
	}
	virtual IDBCommand * createCom()
	{
		return new SqliteDBCommand();
	}
	virtual IDBReader * createRead()
	{
		return new SqliteDBReader();
	}
};
class EmployeDAO3
{
	DBFactory *m_dbFac;

public:
	EmployeDAO3(DBFactory* fac) :m_dbFac(fac)
	{}
	std::vector<std::string> employe()
	{
		
		IDBConnect *con = m_dbFac->createCon();
		IDBCommand *cmd = m_dbFac->createCom();
		cmd->exec(con);
		IDBReader *reader = m_dbFac->createRead();
		reader->read(con);
		std::vector<std::string> employes;
        // employes.append(read data)
		return employes;
	}
};



int main()
{
	MysqlDBFactory fac;
	EmployeDAO3 dao(&fac);
	dao.employe();
	system("pause");
	return 0;
}