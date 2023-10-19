#if !defined(INC_H___51A2AF25_67CA_4EC7_BDD4_110BF0B02226__HEAD__)
#define INC_H___51A2AF25_67CA_4EC7_BDD4_110BF0B02226__HEAD__

#ifdef _WINDOWS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <fcntl.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <regex>
#include <algorithm>
#include <atomic>
#include <mutex>
#include <memory>
#include <functional>
#include <condition_variable>
#include <thread>
#include <chrono>
#include <tuple>
#include <random>
#include <typeinfo>
#if _HAS_CXX17
//!@discard -- #include <locale>
//!@discard -- #include <codecvt>
#include <variant>
#include <filesystem>
#endif
#if _HAS_CXX20/*_MSVC_LANG>201703L*/
#include <format>
#include <coroutine>
#include <concepts>  // (模板)类型约束
#endif
#if _HAS_CXX23
#endif


#include <future>

#include <array>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <bitset>
#include <limits>

namespace stdcxx {

 template<typename T>
 requires std::is_convertible_v<T, std::string> || std::is_convertible_v<T, std::wstring>
  static T Lower(const T & input) {
  T result{ input };
  if (!result.empty()) {
   std::transform(result.begin(), result.end(), result.begin(), ::tolower);
  }
  return result;
 }

 template<typename T>
 requires std::is_convertible_v<T, std::string> || std::is_convertible_v<T, std::wstring>
  static T Upper(const T & input) {
  T result{ input };
  if (!result.empty()) {
   std::transform(result.begin(), result.end(), result.begin(), ::toupper);
  }
  return result;
 }

 static std::string ReadFile(const std::string& file_, const int& mode_ = std::ios::in | std::ios::binary /*std::ios::_Nocreate | std::ios::_Noreplace | std::ios::binary*/) {
  std::string result;
  std::fstream of;
  of.open(file_, mode_);
  do {
   if (!of.is_open())
    break;
   of.seekg(0, of.end);
   size_t size = static_cast<size_t>(of.tellg());
   if (size <= 0)
    break;
   result.resize(size, 0x00);
   of.seekg(0, of.beg);
   of.read(&result[0], size);
  } while (0);
  if (of.is_open())
   of.close();
  return result;
 }

 static void ReadFile(const std::string& file_, std::vector<char>& out_, const int& mode_ = std::ios::in | std::ios::binary /*std::ios::_Nocreate | std::ios::_Noreplace | std::ios::binary*/) {
  out_.clear();
  std::fstream of;
  of.open(file_, mode_);
  do {
   if (!of.is_open())
    break;
   of.seekg(0, of.end);
   size_t size = static_cast<size_t>(of.tellg());
   if (size <= 0)
    break;
   out_.resize(size, 0x00);
   of.seekg(0, of.beg);
   of.read(&out_[0], size);
  } while (0);
  if (of.is_open())
   of.close();
 }

 static bool WriteFile(const std::string& file_, const std::string& data_, const int& mode_ = std::ios::binary | std::ios::out | std::ios::trunc) {
  bool result = false;
  do {
   if (data_.empty())
    break;
#if 0
   if (!Win::AccessA(Win::GetPathByPathnameA(FilePathname)))
    Win::CreateDirectoryA(Win::GetPathByPathnameA(FilePathname));
#endif
   std::ofstream of(file_, mode_);
   if (!of.is_open())
    break;
   of << data_;
   of.close();
   result = true;
 } while (0);
 return result;
}

 static bool WriteFileAddto(const std::string& file_, const std::string& data_) {
  bool result = false;
  do {
   if (data_.empty())
    break;
#if 0
   if (!Win::AccessA(FilePathname))
    Win::CreateDirectoryA(Win::GetPathByPathnameA(FilePathname));
#endif
   std::ofstream of(file_, std::ios::binary | std::ios::out | std::ios::app);
   if (!of.is_open())
    break;
   of << data_;
   of.close();
   result = true;
 } while (0);
 return result;
 }


}///namespace stdcxx

/// /*新生®（上海）**/
/// /*2022_02_19T06:18:54.5642649Z**/
/// /*_ _ _ _ _ _ _ www.skstu.com _ _ _ _ _ _ _**/
#endif ///INC_H___51A2AF25_67CA_4EC7_BDD4_110BF0B02226__HEAD__
