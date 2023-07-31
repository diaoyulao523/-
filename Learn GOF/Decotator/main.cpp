// main.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include "Stream2.cpp"
#include "Stream3.cpp"


/*
在某些情况下我们可能会“过度地使用继承来扩展对象的功能”，
由于继承为类型引入的静态特质，使得这种扩展方式缺乏灵活性；
并且随着子类的增多（扩展功能的增多），各种子类的组合（扩展
功能的组合）会导致更多子类的膨胀。
如何使“对象功能的扩展”能够根据需要来动态地实现？同时避
免“扩展功能的增多”带来的子类膨胀问题？从而使得任何“功能
扩展变化”所导致的影响将为最低？
*/



int main()
{


 // 静态装饰
	CryptoBufferFileStream *scbf = new CryptoBufferFileStream();
	scbf->read(100);

	printf("2.0模式---------\n");
//动态装饰
	FileStream *fs = new FileStream();
	BufferStream *bs = new BufferStream(fs);
	CryptoStream *cbs = new CryptoStream(bs);
	cbs->read(100);


	printf("3.0模式---------\n");
	BufferStream3 *bs3 = new BufferStream3(fs);
	CryptoStream3 *cbs3 = new CryptoStream3(bs);
	cbs3->read(100);


	system("pause");
    return 0;
}

