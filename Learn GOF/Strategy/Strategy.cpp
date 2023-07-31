// SalesOrder.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
class SalesOrder
{
	enum TaxType
	{
		CN_Tax,
		US_Tax,
		JP_Tax,
		GM_Tax  //add

	};
public:
	double calculate(TaxType type)
	{
		switch (type)
		{
		case CN_Tax:
			return 1;
		case US_Tax:
			return 2;
		case JP_Tax:
			return 3;
		case GM_Tax:    // 添加新的税种  需要修改枚举 及计算函数
			return 4;
		default:
			break;
		}
		return -1;
	}

};

