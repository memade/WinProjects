#include "stdafx.h"

int main(int argc, char** argv) {

 const std::u16string u16str = u"��ð���abck,1234,!#%&#$%&.";


#if 0
 const wchar_t wstr[] = L"��ð���abck,1234,!#%&#$%&.";

 std::u16string u16str = stdcxx::conv::WStringToU16String(wstr);
 std::u8string u8str = stdcxx::conv::U16StringToU8String(u16str);
 const wchar_t pwc[] = L"��ð�#$@%@#$^@!asdlfkhglkasdg!";

#endif

 auto adfkakdsf = 0;
#if 0
 size_t len = 0;
 char* pmbnull = NULL;
 auto akdfk = MB_CUR_MAX;
 const wchar_t* pwc = L"Hi";
 wchar_t* pwcs = (wchar_t*)malloc(sizeof(wchar_t));

 char* pmb = (char*)malloc(MB_CUR_MAX * wcslen(pwc) + 1);

 printf("ת��Ϊ���ֽ��ַ���\n");
 len = wcstombs(pmb, pwc, MB_CUR_MAX * wcslen(pwc) + 1);
 printf("��ת�����ַ� %d\n", len);
 printf("��һ�����ֽ��ַ���ʮ������ֵ��%#.4x\n", pmb);

 printf("ת���ؿ��ַ��ַ���\n");
 len = mbstowcs(pwcs, pmb, MB_CUR_MAX);
 printf("��ת�����ַ� %d\n", len);
 printf("��һ�����ַ���ʮ������ֵ��%#.4x\n\n", pwcs);
#endif


 // ��ȡ��ǰ���̵ľ��
 HANDLE hProcess = GetCurrentProcess();

 // ��ȡ���̵�ģ����Ϣ
 MODULEINFO moduleInfo;
 ::GetModuleInformation(hProcess, NULL, &moduleInfo, sizeof(moduleInfo));

 // ��ģ����Ϣ�л�ȡ��ִ���ļ���·��
 TCHAR path[MAX_PATH] = { 0 };
 ::GetModuleFileNameW((HMODULE)moduleInfo.lpBaseOfDll, path, MAX_PATH);


 // ȥ����ִ���ļ�������
 ::PathRemoveFileSpecW(path);



 auto ret = stdcxx::Lower<std::wstring>(path);

 auto break__ = 0;
#if 0



 auto path = std::filesystem::current_path();
 // ��ȡ��ǰ���̵�����
 auto currentProcessName = std::filesystem::path(std::filesystem::current_path()).filename();

 // ��ȡ��ǰ���̵ĺ�׺��
 auto currentProcessSuffix = currentProcessName.extension();

 auto adsfk = currentProcessSuffix.c_str();
 // �����ǰ���̵ĺ�׺��
 std::cout << currentProcessSuffix << std::endl;


 /*auto path = std::filesystem::current_path();

 auto name = std::filesystem::path(path).filename();

 auto suffix = name.extension();*/
#endif
 printf("Hi Martell!");

 return 0;
}