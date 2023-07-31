#pragma once
#include "stdafx.h"
#include "Bridge.cpp"
/*
����:
����ĳЩ���͵Ĺ��е�ʵ���߼���ʹ�����Ǿ��������仯��ά�ȣ�
�������γ�ȵı仯��
���Ӧ�����֡���ά�ȵı仯����������������������ʹ��
���Ϳ������ɵ��������������������仯�������������ĸ���
�ȣ�
 �����̳�ת���
*/


// Bridge2.cpp : �������̨Ӧ�ó������ڵ㡣
//
class MessagerImp {
public:
	virtual void PlaySound() = 0;
	virtual void DrawShape() = 0;
	virtual void WriteText() = 0;
	virtual void Connect() = 0;

	virtual ~MessagerImp() {}
};


class Messager2 {

protected:

	MessagerImp *m_message;
public:
	Messager2(MessagerImp* msg) :m_message(msg)
	{}
	virtual void Login(string username, string password) = 0;
	virtual void SendMessage(string message) = 0;
	virtual void SendPicture(string string) = 0;
	virtual ~Messager2() {}

};


//ƽ̨ʵ��

class PCMessagerImp : public MessagerImp {
public:
	virtual ~PCMessagerImp() {}
	virtual void PlaySound() {
		MY_PRINT1();
	}
	virtual void DrawShape() {
		MY_PRINT1();
	}
	virtual void WriteText() {
		MY_PRINT1();
	}
	virtual void Connect() {
		MY_PRINT1();
	}
};

class MobileMessagerImp : public MessagerImp {
public:
	virtual ~MobileMessagerImp() {}
	virtual void PlaySound() {
		MY_PRINT1();
	}
	virtual void DrawShape() {
		MY_PRINT1();
	}
	virtual void WriteText() {
		MY_PRINT1();
	}
	virtual void Connect() {
		MY_PRINT1();
	}
};



//ҵ�����

class MessagerLite: public Messager2
{
public:

	MessagerLite(MessagerImp*msg):Messager2(msg)
	{
	}
	virtual void Login(string username, string password) {

		m_message->Connect();
		MY_PRINT1();
	}
	virtual void SendMessage(string message) {

		m_message->WriteText();
		MY_PRINT1();
	}
	virtual void SendPicture(string string) {

		m_message->DrawShape();
		MY_PRINT1();
	}
};


class MessagerPerfect : public Messager2 {

public:

	MessagerPerfect(MessagerImp*msg) :Messager2(msg)
	{
	}

	virtual void Login(string username, string password) {

		m_message->PlaySound();

		m_message->Connect();
		MY_PRINT1();
	}
	virtual void SendMessage(string message) {

		m_message->PlaySound();

		m_message->WriteText();
		MY_PRINT1();
	}
	virtual void SendPicture(string string) {

		m_message->PlaySound();

		m_message->DrawShape();
		MY_PRINT1();
	}
};




int main()
{
	// ��̬��
	MobileMessagerPerfect  *p1 = new MobileMessagerPerfect();
	p1->Login("","");

	//��ģʽ ��̬��
	printf("\n\n\n��̬��\n");
	MobileMessagerImp *imp = new MobileMessagerImp();
	MessagerPerfect *p2 = new MessagerPerfect(imp);
	p2->Login("", "");;


	system("pause");
	return -1;
}