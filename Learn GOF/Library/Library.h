// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� LIBRARY_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// LIBRARY_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef LIBRARY_EXPORTS
#define LIBRARY_API __declspec(dllexport)
#else
#define LIBRARY_API __declspec(dllimport)
#endif

// �����Ǵ� Library.dll ������
class LIBRARY_API CLibrary {
public:
	CLibrary(void);
	~CLibrary()
	{

	}
	// TODO:  �ڴ�������ķ�����
private:
	void step1();
	void step3();
	void step5();

public:
	void run();
	virtual bool step2() = 0;
	virtual int step4() =0;

};

extern LIBRARY_API int nLibrary;

LIBRARY_API int fnLibrary(void);
