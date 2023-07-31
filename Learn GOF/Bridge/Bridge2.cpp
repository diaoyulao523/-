#pragma once
#include "stdafx.h"
#include "Bridge.cpp"
/*
动机:
由于某些类型的固有的实现逻辑，使得它们具有两个变化的维度，
乃至多个纬度的变化。
如何应对这种“多维度的变化”？如何利用面向对象技术来使得
类型可以轻松地沿着两个乃至多个方向变化，而不引入额外的复杂
度？
 ！！继承转组合
*/


// Bridge2.cpp : 定义控制台应用程序的入口点。
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


//平台实现

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



//业务抽象

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
	// 静态绑定
	MobileMessagerPerfect  *p1 = new MobileMessagerPerfect();
	p1->Login("","");

	//桥模式 动态绑定
	printf("\n\n\n动态绑定\n");
	MobileMessagerImp *imp = new MobileMessagerImp();
	MessagerPerfect *p2 = new MessagerPerfect(imp);
	p2->Login("", "");;


	system("pause");
	return -1;
}