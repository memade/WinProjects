#include "stdafx.h"

int main(int argc, char** argv) {

 const std::u16string u16str = u"你好啊，abck,1234,!#%&#$%&.";


#if 0
 const wchar_t wstr[] = L"你好啊，abck,1234,!#%&#$%&.";

 std::u16string u16str = stdcxx::conv::WStringToU16String(wstr);
 std::u8string u8str = stdcxx::conv::U16StringToU8String(u16str);
 const wchar_t pwc[] = L"你好啊#$@%@#$^@!asdlfkhglkasdg!";

#endif

 auto adfkakdsf = 0;
#if 0
 size_t len = 0;
 char* pmbnull = NULL;
 auto akdfk = MB_CUR_MAX;
 const wchar_t* pwc = L"Hi";
 wchar_t* pwcs = (wchar_t*)malloc(sizeof(wchar_t));

 char* pmb = (char*)malloc(MB_CUR_MAX * wcslen(pwc) + 1);

 printf("转换为多字节字符串\n");
 len = wcstombs(pmb, pwc, MB_CUR_MAX * wcslen(pwc) + 1);
 printf("被转换的字符 %d\n", len);
 printf("第一个多字节字符的十六进制值：%#.4x\n", pmb);

 printf("转换回宽字符字符串\n");
 len = mbstowcs(pwcs, pmb, MB_CUR_MAX);
 printf("被转换的字符 %d\n", len);
 printf("第一个宽字符的十六进制值：%#.4x\n\n", pwcs);
#endif


 // 获取当前进程的句柄
 HANDLE hProcess = GetCurrentProcess();

 // 获取进程的模块信息
 MODULEINFO moduleInfo;
 ::GetModuleInformation(hProcess, NULL, &moduleInfo, sizeof(moduleInfo));

 // 从模块信息中获取可执行文件的路径
 TCHAR path[MAX_PATH] = { 0 };
 ::GetModuleFileNameW((HMODULE)moduleInfo.lpBaseOfDll, path, MAX_PATH);


 // 去除可执行文件的名称
 ::PathRemoveFileSpecW(path);



 auto ret = stdcxx::Lower<std::wstring>(path);

 auto break__ = 0;
#if 0



 auto path = std::filesystem::current_path();
 // 获取当前进程的名字
 auto currentProcessName = std::filesystem::path(std::filesystem::current_path()).filename();

 // 获取当前进程的后缀名
 auto currentProcessSuffix = currentProcessName.extension();

 auto adsfk = currentProcessSuffix.c_str();
 // 输出当前进程的后缀名
 std::cout << currentProcessSuffix << std::endl;


 /*auto path = std::filesystem::current_path();

 auto name = std::filesystem::path(path).filename();

 auto suffix = name.extension();*/
#endif
 printf("Hi Martell!");

 return 0;
}