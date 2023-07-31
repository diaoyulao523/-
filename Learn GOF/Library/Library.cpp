// Library.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "Library.h"
#include "../Commond.h"


// 这是导出变量的一个示例
LIBRARY_API int nLibrary=0;

// 这是导出函数的一个示例。
LIBRARY_API int fnLibrary(void)
{
    return 42;
}

// 这是已导出类的构造函数。
// 有关类定义的信息，请参阅 Library.h
CLibrary::CLibrary()
{
    return;
}

void CLibrary::step1()
{
	MY_PRINT1();

}
void CLibrary::step3()
{
	MY_PRINT1();

}
void CLibrary::step5()
{
	MY_PRINT1();

}


void CLibrary::run()
{
	step1();
	if (step2())
	{
		step3();
	}
	for (size_t i = 0; i < 3; i++)
	{
		step4();
	}
	step5();

}

bool  CLibrary::step2()
{
	MY_PRINT1();
	return true;
}

int CLibrary::step4()
{
	MY_PRINT1();
	return  -1;
}
