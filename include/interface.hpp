#if !defined(INC_H___51A2AF25_67CA_4EC7_BDD4_110BF0B02220__HEAD__)
#define INC_H___51A2AF25_67CA_4EC7_BDD4_110BF0B02220__HEAD__

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <Windows.h>

#if defined(SHARED_API)
#define __SHARED_API_ extern "C" __declspec(dllexport)
#else
#define __SHARED_API_ extern "C" __declspec(dllimport)
#endif

__SHARED_API_ void* __stdcall interface_init(const void*, unsigned long);
__SHARED_API_ void __stdcall interface_uninit(void);

namespace shared {
 template<typename T>
 class Interface {
 public:
  using interface_init_type = void* (__stdcall*)(const void*, unsigned long);
  using interface_uninit_type = void(__stdcall*)(void);
 protected:
  HMODULE module_ = nullptr;
  interface_init_type interface_init_ = nullptr;
  interface_uninit_type interface_uninit_ = nullptr;
 public:
  virtual T* Create(
   const char* dll_pathname,
   const char* funname_init = "interface_init",
   const char* funname_uninit = "interface_uninit",
   const void* funparam_init_1 = nullptr,
   const unsigned long& funparam_init_2 = 0) {
   bool success = false;
   T* result = nullptr;
   do {
    if (!dll_pathname)
     break;
    module_ = ::LoadLibraryA(dll_pathname);
    if (!module_)
     break;
    interface_init_ = reinterpret_cast<decltype(interface_init_)>(::GetProcAddress(module_, funname_init));
    interface_uninit_ = reinterpret_cast<decltype(interface_uninit_)>(::GetProcAddress(module_, funname_uninit));
    if (!interface_init_ || !interface_uninit_)
     break;
    result =reinterpret_cast<decltype(result)>(interface_init_(funparam_init_1, funparam_init_2));
    if (!result)
     break;
    success = true;
   } while (0);
   if (!success) {
    if (module_) {
     if (TRUE == ::FreeLibrary(module_)) {
      module_ = nullptr;
     }
    }
   }
   return result;
  }

  virtual void Destroy() {
   do {
    if (!module_)
     break;
    if (FALSE == ::FreeLibrary(module_))
     break;
    if (!interface_uninit_)
     break;
    interface_uninit_();
    interface_init_ = nullptr;
    interface_uninit_ = nullptr;
    module_ = nullptr;
   } while (0);
  }

 };
}///namespace shared

/// /*新生®（上海）**/
/// /*2022_02_19T06:18:54.5642649Z**/
/// /*_ _ _ _ _ _ _ www.skstu.com _ _ _ _ _ _ _**/
#endif ///INC_H___51A2AF25_67CA_4EC7_BDD4_110BF0B02220__HEAD__
