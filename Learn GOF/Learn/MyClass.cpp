#include "stdafx.h"
#include "Library.h"
#include "../Commond.h"

class MyClass : public CLibrary
{
public:

	bool step2()
	{
		{
			MY_PRINT1();
			return false;
		}
	}
	int step4()
	{
		MY_PRINT1();
		return 0;
	}


};



/*

����:

��ĳһ���������������ȶ�����������ṹ���������Ӳ���ȴ�ֺܶ�ı�����󣬻������ڹ��е�ԭ����޷������������ṹͬʱʵ��
�����ȷ���ȶ��Ĳ����ṹ�£�Ӧ�����仯���Ӳ��� ��

*/
int main()
{
	CLibrary *my = new MyClass();
	my->run();
	system("pause");
	return 0;
}
