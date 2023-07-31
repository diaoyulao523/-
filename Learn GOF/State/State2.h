#pragma once


class TMState
{
public:
	TMState *pNextState;

	virtual void init() = 0;
	virtual void test() = 0;
	virtual void reset() = 0;

	virtual ~TMState()
	{}

};


class Idle : public TMState
{

private:
	Idle();
	Idle(Idle&) = delete;
public:

	static TMState * GetInstance();

	virtual void init();

	virtual void test();
	virtual void reset();

};

class Ready : public TMState
{

private:
	Ready();
	Ready(Ready&) = delete;
public:

	static TMState * GetInstance();

	virtual void init();
	virtual void test();
	virtual void reset();

};


class Run : public TMState
{

private:
	Run();
	Run(Run&) = delete;
public:

	static TMState * GetInstance();
	virtual void init();
	virtual void test();
	virtual void reset();
};

class Stop : public TMState
{

private:
	Stop();
	Stop(Stop&) = delete;
public:

	static TMState * GetInstance();

	virtual void init();
	virtual void test();
	virtual void reset();

};


class Abort : public TMState
{

private:
	Abort();
	Abort(Abort&) = delete;
public:

	static TMState * GetInstance();

	virtual void init();
	virtual void test();
	virtual void reset();

};



class Test1
{
	TMState *next = Idle::GetInstance();
public:
	void init();
	void test();
	void reset();

};
