#if !defined(INC_H___7379FDD7_F126_4814_ABD3_0DF33647115A__HEAD__)
#define INC_H___7379FDD7_F126_4814_ABD3_0DF33647115A__HEAD__

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <Windows.h>
#include <assert.h>
#include <system_error>
#include <winioctl.h>
#include <intrin.h>
#include <sddl.h>
#include <windowsx.h>
#include <winsock2.h>  
#include <ws2tcpip.h>
#pragma comment(lib,"ws2_32")
#include <AclAPI.h>
#include <IPHlpApi.h>
#pragma comment(lib,"Iphlpapi.lib")
#if ENABLE_WIN_DEFINE_IMAGEHLP
#include <ImageHlp.h>
#pragma comment(lib,"ImageHlp.lib")  
#endif

#include <rpcdce.h>
#pragma comment(lib,"Rpcrt4")

#if ENABLE_WIN_DEFINE_WININET
#include <wininet.h>
#pragma comment(lib,"Wininet")
#endif
#if ENABLE_WIN_DEFINE_WINHTTP
#include "winhttp.hpp"
#pragma comment(lib, "winhttp")
#endif

#include <atlbase.h>
#include <atlsafe.h>
#include <strsafe.h>
#include <comdef.h>
#include <comutil.h>
#include <ExDisp.h>
#pragma comment(lib,"wbemuuid")
#pragma comment(lib,"comsuppw")
#include <shellapi.h>
#include <wincrypt.h>
#include <KnownFolders.h>
#pragma comment(lib,"crypt32")
#include <shlwapi.h>
#pragma comment(lib, "shlwapi")
#include <shlobj.h>
#include <TlHelp32.h>
#include <Psapi.h>
#pragma comment(lib,"psapi")
#pragma comment(lib, "version")

#include <Msi.h>
#pragma comment(lib,"msi")
#include <WbemIdl.h>
#pragma comment(lib,"wbemuuid")
#include <wintrust.h>
#include <Softpub.h>
#pragma comment (lib, "Wintrust")
#include <userenv.h>
#pragma comment(lib,"Userenv")

#if ENABLE_WIN_DEFINE_GDIPLUS
#include <gdiplus.h>
#pragma comment(lib,"gdiplus")
#endif

#pragma comment(lib,"Comctl32")

#include <io.h>
#include <direct.h>
#include <tchar.h>

//!@ Enable SK NTCore(Packaging)
#if ENABLE_WIN_DEFINE_NT
#include <winternl.h>
#else
#endif

//!@ GroupPolicy
#define INITGUID 
#include <Guiddef.h>
#include <Gpedit.h>

#define CSIDL_WINDOWS_QUICK_LAUNCH (0xFFFF-2)
#define CSIDL_WINDOWS_CURRENT_USER (0xFFFF-3)
#define CSIDL_WINDOWS_COMMON_APPDATA (0xFFFF-4)
#define CSIDL_WINDOWS_USER_TEMP (0xFFFF-5)
#define CSIDL_WINDOWS_USER_APPDATA (0xFFFF-6)

namespace windows {

}///namespace windows

/// /*新生®（上海）**/
/// /*2022_02_19T05:51:39.1314990Z**/
/// /*_ _ _ _ _ _ _ www.skstu.com _ _ _ _ _ _ _**/
#endif ///INC_H___7379FDD7_F126_4814_ABD3_0DF33647115A__HEAD__