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

动机:

对某一项任务，它常常有稳定的整体操作结构，但各个子步骤却又很多改变的需求，或者由于固有的原因而无法和任务的整体结构同时实现
如何在确定稳定的操作结构下，应对灵活变化的子步骤 ？

*/
int main()
{
	CLibrary *my = new MyClass();
	my->run();
	system("pause");
	return 0;
}
