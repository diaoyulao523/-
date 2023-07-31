#include "stdafx.h"
#include "Strategy2.cpp"

/*

动机:
在软件构建过程中，某些对象使用的算法可能多种多样，经常改
变，如果将这些算法都编码到对象中，将会使对象变得异常复杂
而且有时候支持不使用的算法也是一个性能负担。
如何在运行时根据需要透明地更改对象的算法？将算法与对象本
身解耦，从而避免上述问题？

*/

int main()
{
	SalesOrder2 order;

	printf("%.3f\n", order.calculate());
	system("pause");
	return 0;
}