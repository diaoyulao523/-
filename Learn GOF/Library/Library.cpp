// Library.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "Library.h"
#include "../Commond.h"


// ���ǵ���������һ��ʾ��
LIBRARY_API int nLibrary=0;

// ���ǵ���������һ��ʾ����
LIBRARY_API int fnLibrary(void)
{
    return 42;
}

// �����ѵ�����Ĺ��캯����
// �й��ඨ�����Ϣ������� Library.h
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
