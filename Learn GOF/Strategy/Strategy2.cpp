#pragma once

#include "stdafx.h"
class TaxInterface
{
public:
	~TaxInterface()
	{
	}
	virtual double calculate() = 0;
};

class CNTax :public TaxInterface
{
public:
	virtual double calculate()
	{
		return 1;
	}

};


class USTax :public TaxInterface
{
public:
	virtual double calculate()
	{
		return 2;
	}
};


class JPTax :public TaxInterface
{

public:
	virtual double calculate()
	{
		return 3;
	}
};


class GMTax :public TaxInterface
{
public:
	virtual double calculate()
	{
		return 4;
	}
};



class SalesOrder2
{

public:
	double calculate()
	{

		TaxInterface *tax = new CNTax();  // 此处可使用工厂模式创建对象
		double val = tax->calculate();
		delete tax;
		return val;
	}

};
