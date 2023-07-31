// FactoryMethod.cpp : �������̨Ӧ�ó������ڵ㡣
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
		TaxInterface *tax = m_fac->createTax(); // �˴�ʹ�ù���ģʽ��������
		double val = tax->calculate();
		delete tax;
		return val;
	}

private:
	TaxFactoryInterface *m_fac;
};

/*
�����ϵͳ�У����������Ŵ�������Ĺ�������������ı仯��
��Ҫ�����Ķ���ľ������;����仯��
 ���Ӧ�����ֱ仯������ƹ�����Ķ��󴴽�����(new)���ṩһ
�֡���װ���ơ�������ͻ���������֡�������󴴽��������Ľ�
��ϣ�
 ����ģʽ �ӳٴ���
*/

int main()
{

	CNTaxFac fac;
	SalesOrder3 sales(&fac);
	printf("%d \n", sales.calculate());
	system("pause");
    return 0;
}

