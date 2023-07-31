// Bridge.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
using namespace std;
#include <string>
#include "../Commond.h"



/*
使用继承方式实现
*/



class Messager {
public:
	virtual void Login(string username, string password) = 0;
	virtual void SendMessage(string message) = 0;
	virtual void SendPicture(string string) = 0;

	virtual void PlaySound() = 0;
	virtual void DrawShape() = 0;
	virtual void WriteText() = 0;
	virtual void Connect() = 0;

	virtual ~Messager() {}
};


//平台实现

class PCMessagerBase : public Messager {
public:

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

class MobileMessagerBase : public Messager {
public:

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

class PCMessagerLite : public PCMessagerBase {
public:
	PCMessagerLite() :PCMessagerBase()
	{
	}
	virtual void Login(string username, string password) {

		PCMessagerBase::Connect();
		MY_PRINT1();
	}
	virtual void SendMessage(string message) {

		PCMessagerBase::WriteText();
		MY_PRINT1();
	}
	virtual void SendPicture(string string) {

		PCMessagerBase::DrawShape();
		MY_PRINT1();
	}
};



class PCMessagerPerfect : public PCMessagerBase {
public:
	PCMessagerPerfect() :PCMessagerBase()
	{
	}

	virtual void Login(string username, string password) {

		PCMessagerBase::PlaySound();
		
		PCMessagerBase::Connect();
		MY_PRINT1();
	}
	virtual void SendMessage(string message) {

		PCMessagerBase::PlaySound();
		
		PCMessagerBase::WriteText();
		MY_PRINT1();
	}
	virtual void SendPicture(string string) {

		PCMessagerBase::PlaySound();
		
		PCMessagerBase::DrawShape();
		MY_PRINT1();
	}
};


class MobileMessagerLite : public MobileMessagerBase {
public:
	MobileMessagerLite() :MobileMessagerBase()
	{
	}
	virtual void Login(string username, string password) {

		MobileMessagerBase::Connect();
		MY_PRINT1();
	}
	virtual void SendMessage(string message) {

		MobileMessagerBase::WriteText();
		MY_PRINT1();
	}
	virtual void SendPicture(string string) {

		MobileMessagerBase::DrawShape();
		MY_PRINT1();
	}
};


class MobileMessagerPerfect : public MobileMessagerBase {
public:
	MobileMessagerPerfect() :MobileMessagerBase()
	{
	}
	virtual void Login(string username, string password) {

		MobileMessagerBase::PlaySound();
		
		MobileMessagerBase::Connect();
		MY_PRINT1();
	}
	virtual void SendMessage(string message) {

		MobileMessagerBase::PlaySound();
		
		MobileMessagerBase::WriteText();
		MY_PRINT1();
	}
	virtual void SendPicture(string string) {

		MobileMessagerBase::PlaySound();
		
		MobileMessagerBase::DrawShape();
		MY_PRINT1();
	}
};




