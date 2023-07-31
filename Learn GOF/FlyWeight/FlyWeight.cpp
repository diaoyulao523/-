// FlyWeight.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<string>
#include <map>
#include"../Commond.h"

class File
{
public:
	File(const std::string& fullPath) :m_fullPath(fullPath)
	{
		MY_PRINT1("%s", fullPath.c_str());
	}
private:
	std::string  m_fullPath;
	void *m_content;
};


class FileFactory
{
public:
	FileFactory()
	{}
	File* getFile(const std::string& fullPath)
	{
		std::map<std::string, File*>::iterator iter = m_filePool.find(fullPath);
		if (iter != m_filePool.end())
		{
			return m_filePool[fullPath];
		}
		else
		{
			File *file = new  File(fullPath);
			m_filePool[fullPath] = file;
			return file;

		}

	}

private:
	std::map<std::string, File*> m_filePool;
};





int main()
{
	FileFactory fc;
	fc.getFile("a");
	fc.getFile("b");
	fc.getFile("c");
	fc.getFile("c");
	system("pause");
    return 0;
}

