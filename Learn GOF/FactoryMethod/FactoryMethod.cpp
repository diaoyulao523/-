// FactoryMethod.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "../Strategy/Strategy2.cpp"

class TaxFactoryInterface
{
public:
	 virtual  TaxInterface* createTax() = 0;

	virtual ~TaxFactoryInterface()
	{}
};

class CNTaxFac :public TaxFactoryInterface
{
	TaxInterface* createTax()
	{
		return new CNTax();
	}
};


class USTaxFac :public TaxFactoryInterface
{
	TaxInterface* createTax()
	{
		return new USTax();
	}
};


class JPTaxFac :public TaxFactoryInterface
{
	TaxInterface* createTax()
	{
		return new JPTax();
	}
};


class GMTaxFac :public TaxFactoryInterface
{
	TaxInterface* createTax()
	{
		return new GMTax();
	}
};



class SalesOrder3
{

public:
	SalesOrder3(TaxFactoryInterface* fac) :m_fac(fac)
	{}


	double calculate()
	{
		TaxInterface *tax = m_fac->createTax(); // 此处使用工厂模式创建对象
		double val = tax->calculate();
		delete tax;
		return val;
	}

private:
	TaxFactoryInterface *m_fac;
};

/*
在软件系统中，经常面临着创建对象的工作；由于需求的变化，
需要创建的对象的具体类型经常变化。
 如何应对这种变化？如何绕过常规的对象创建方法(new)，提供一
种“封装机制”来避免客户程序和这种“具体对象创建工作”的紧
耦合？
 工厂模式 延迟创建
*/

int main()
{

	CNTaxFac fac;
	SalesOrder3 sales(&fac);
	printf("%d \n", sales.calculate());
	system("pause");
    return 0;
}

