// main.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include "Stream2.cpp"
#include "Stream3.cpp"


/*
��ĳЩ��������ǿ��ܻᡰ���ȵ�ʹ�ü̳�����չ����Ĺ��ܡ���
���ڼ̳�Ϊ��������ľ�̬���ʣ�ʹ��������չ��ʽȱ������ԣ�
����������������ࣨ��չ���ܵ����ࣩ�������������ϣ���չ
���ܵ���ϣ��ᵼ�¸�����������͡�
���ʹ�������ܵ���չ���ܹ�������Ҫ����̬��ʵ�֣�ͬʱ��
�⡰��չ���ܵ����ࡱ�����������������⣿�Ӷ�ʹ���κΡ�����
��չ�仯�������µ�Ӱ�콫Ϊ��ͣ�
*/



int main()
{


 // ��̬װ��
	CryptoBufferFileStream *scbf = new CryptoBufferFileStream();
	scbf->read(100);

	printf("2.0ģʽ---------\n");
//��̬װ��
	FileStream *fs = new FileStream();
	BufferStream *bs = new BufferStream(fs);
	CryptoStream *cbs = new CryptoStream(bs);
	cbs->read(100);


	printf("3.0ģʽ---------\n");
	BufferStream3 *bs3 = new BufferStream3(fs);
	CryptoStream3 *cbs3 = new CryptoStream3(bs);
	cbs3->read(100);


	system("pause");
    return 0;
}

