#include "stdafx.h"

namespace local {
 VGAppPlugin::VGAppPlugin() {

 }

 VGAppPlugin::~VGAppPlugin() {

 }


 // 定义按钮点击回调函数
 bool STDMETHODCALLTYPE ButtonClickCallback(void* /* appData */) {
  // 在按钮点击时执行的操作
  // 这里可以添加你的自定义逻辑
  // ...

  return true; // 返回true表示操作成功
 }

 COM_DECLSPEC_NOTHROW HRESULT STDMETHODCALLTYPE VGAppPlugin::raw_OnLoad(VGCore::IVGApplication* Application) {
  LOG_INIT;

  //LOGINFO("{}", __FUNCTION__);

  //MessageBoxW(NULL, __FUNCTIONW__, NULL, MB_TOPMOST);

  HRESULT result = S_OK;
  return result;
  do {
   m_pVGApplication = Application;
   if (m_pVGApplication)
    m_pVGApplication->AddRef();


   //VARIANT_BOOL success = VARIANT_TRUE;
   //VGCore::ICUICommandBarPtr pMainMenu = nullptr;

   //std::set<_bstr_t> commandbar_name_s;

   //auto total = m_pVGApplication->CommandBars->GetCount();
   //total = m_pVGApplication->CommandBars->GetCount();
   //m_pVGApplication->CommandBars->raw_Add(
   //VGCore::ICUICommandBar* pStandardControlPtr = nullptr;
   ////Standard
   //for (long i = 1; i < total; ++i) {
   // _variant_t idx;
   // idx.vt = VT_I4;
   // idx.lVal = i;
   // auto ctrl = m_pVGApplication->CommandBars->Item[idx];
   // auto standard_id = ctrl->GetIndex();
   // auto name = ctrl->GetName();
   // //if (!wcscmp(L"Standard", name.GetBSTR())) {
   // // auto total = ctrl->Controls->Count;
   // // ::MessageBoxW(NULL, std::format(L"Found standard cmdbar and total is({}).", total).c_str(), NULL, MB_TOPMOST);
   // // for (long i = 0; i < total; ++i) {
   // //  VGCore::ICUIControl* p = nullptr;
   // //  ctrl->Controls->get_Item(i,&p);
   // //  if (!p)
   // //   continue;
   // //  //::MessageBoxW(NULL, p->GetDescriptionText().GetBSTR(), NULL, MB_TOPMOST);

   // // }
   // // //pStandardControlPtr = ctrl;

   // //}
   // commandbar_name_s.emplace(name);
   // //MessageBoxW(NULL, std::format(L"Total({}),standard id is({}),name is({})", total, standard_id, name).c_str(), NULL, MB_TOPMOST);
   //}


   //auto std_cmdbar_total = pStandardControlPtr->Controls->GetCount();
   //MessageBoxW(NULL, std::format(L"Std cmdbar total ({}).",std_cmdbar_total).c_str(), NULL, MB_TOPMOST);



   ////auto ctrl_s = pStandardControlPtr->GetControls();
   ////for (long i = 0; i < std_cmdbar_total; ++i) {
   //// VGCore::ICUIControl* ctrl = ctrl_s->GetItem(i);
   //// if (!ctrl)
   ////  continue;
   //// //MessageBoxW(NULL, ctrl->DescriptionText, NULL, MB_TOPMOST);

   ////}

   //MessageBoxW(NULL, std::format(L"CommandBar total ({})", commandbar_name_s.size()).c_str(), NULL, MB_TOPMOST);

   ////for (const auto& cmdbar : commandbar_name_s) {
   //// MessageBoxW(NULL, std::format(L"Cmdbar name ({})", cmdbar).c_str(), NULL, MB_TOPMOST);
   ////}


   //auto find = commandbar_name_s.find(L"小慧辅助工具®");
   //if (find != commandbar_name_s.end()) {
   // //::MessageBoxW(NULL, L"预添加的命令栏已经存在！", NULL, MB_TOPMOST);
   // //break;
   //}
   //::MessageBoxW(NULL, L"添加命令栏完成！", NULL, MB_TOPMOST);
   //!@ 添加一行命令栏
   auto pNewCommandBar = m_pVGApplication->CommandBars->Add(_bstr_t(L"小慧辅助工具®"), VGCore::cuiBarPosition::cuiBarFloating, VARIANT_FALSE);
   if (pNewCommandBar) {
    pNewCommandBar->raw_SetWidth(200);
    pNewCommandBar->put_Enabled(VARIANT_TRUE);
    //::MessageBoxW(NULL, L"Append cmdbar success.", NULL, MB_TOPMOST);
    VGCore::ICUIControlPtr pControl = pNewCommandBar->Controls->AddCustomButton(/*VGCore::cdrCmdCategoryPlugins*/_bstr_t("yijianzhuanqu"), _bstr_t("一键转曲"), 1, VARIANT_FALSE);
    if (pControl) {
     pControl->put_Width(100);
     pControl->put_Height(30);

     pControl->put_Visible(VARIANT_TRUE);

     wchar_t* ico = new wchar_t[50];
     wmemset(ico, 0x00, 50);
     wmemcpy(ico, L"D:\\taiji.ico", wcslen(L"D:\\taiji.ico"));
     pControl->raw_SetIcon(16, 16);
     pControl->raw_SetIcon2(ico);
     pControl->raw_SetCustomIcon(ico);

     //RegisterEvent(_bstr_t("MyPluginButton"), cdrClick, &ButtonClickCallback, nullptr);
#if 0
     //auto w = pControl->wid
     pControl->put_Width(16);
     pControl->put_Height(16);

     pControl->put_Visible(VARIANT_TRUE);


     long w{ 0 }, h{ 0 };
     //pControl->get_Height(&h);
     //pControl->get_Width(&w);

     //MessageBoxW(NULL, L"Append commandbar button success.", NULL, MB_TOPMOST);
     std::wstring btn_text = std::format(L"width({}),height({}),visible({})", w, h, pControl->GetVisible() ? L"True" : L"Failed");
     MessageBoxW(NULL, btn_text.c_str(), NULL, MB_TOPMOST);
#endif
    }


   }
#if 0
   auto total = m_pVGApplication->CommandBars->GetCount();
   total = m_pVGApplication->CommandBars->GetCount();
   MessageBoxW(NULL, std::format(L"Total({})", total).c_str(), NULL, MB_TOPMOST);
   //m_pVGApplication->CommandBars->raw_Add(
   for (long i = 1; i < total; ++i) {
    _variant_t idx;
    idx.vt = VT_I4;
    idx.lVal = i;
    auto pStandardControlPtr = m_pVGApplication->CommandBars->Item[idx];
    auto standard_id = pStandardControlPtr->GetIndex();
    auto name = pStandardControlPtr->GetName();
    MessageBoxW(NULL, std::format(L"Total({}),standard id is({}),name is({})", total, standard_id, name).c_str(), NULL, MB_TOPMOST);
   }
#endif
   //_bstr_t("Standard")

#if 0
   if (pStandardControlPtr)
   {
    auto count = pStandardControlPtr->Controls->GetCount();
    MessageBoxW(NULL, std::format(L"Item count({})", count).c_str(), NULL, MB_TOPMOST);
    for (long i = 0; i < count; ++i) {
     VGCore::ICUIControl* ctrl = nullptr;
     if (!SUCCEEDED(pStandardControlPtr->Controls->get_Item(i, &ctrl)))
      continue;
     BSTR desc_text = nullptr;
     BSTR caption = nullptr;
     ctrl->get_Caption(&caption);
     ctrl->get_DescriptionText(&desc_text);
     auto msg = std::format(L"idx({}) desc({}),caption({})", i, desc_text, caption);
     MessageBoxW(NULL, msg.c_str(), NULL, MB_TOPMOST);
    }


   }
#endif



   struct VGCore::ICUICommandBars* pCommandBars = nullptr;
   if (SUCCEEDED(m_pVGApplication->get_CommandBars(&pCommandBars))) {




    //long count = 0;
    //pCommandBars->get_Count(&count);
    //VGCore::ICUICommandBar* pCommandBar = nullptr;
    //VARIANT idx;
    //idx.vt = VT_I4;
    //idx.lVal = 0;
    //MessageBoxW(NULL, pCommandBars->Item[_bstr_t("Standard")]->Name, NULL, MB_TOPMOST);

    //m_pVGApplication->AddPluginCommand(_bstr_t("ClearFill"), _bstr_t("Clear Fill"), _bstr_t("Clears fill from selected objects"));
    //auto pControlPtr = m_pVGApplication->CommandBars->Item[_bstr_t("Standard")]->Controls->AddCustomButton(VGCore::cdrCmdCategoryPlugins, _bstr_t("ClearFill"), 0, VARIANT_TRUE);

    //if(pControlPtr)
    // MessageBoxW(NULL, L"success", NULL, MB_TOPMOST);


    //if (!SUCCEEDED(pCommandBars->get_Item(idx, &pCommandBar))) {

    // MessageBoxW(NULL, L"success", NULL, MB_TOPMOST);
    //}
    //else {
    // MessageBoxW(NULL, L"failed", NULL, MB_TOPMOST);
    //}
    //auto pControlPtr = pCommandBars->Item[_bstr_t("标准")]->Controls->AddCustomButton(VGCore::cdrCmdCategoryPlugins, _bstr_t("ClearFill"), 0, VARIANT_TRUE);
    //auto pControlPtr = m_pVGApplication->CommandBars->Item[_bstr_t("Standard")]->Controls->AddCustomButton(VGCore::cdrCmdCategoryPlugins, _bstr_t("ClearFill"), 0, VARIANT_TRUE);


#if 0
    MessageBoxW(NULL, std::format(L"{}", count).c_str(), NULL, MB_TOPMOST);
    for (long i = 0; i < count; ++i) {
     VGCore::ICUICommandBar* pCommandBar = nullptr;
     VARIANT idx;
     idx.vt = VT_I4;
     idx.lVal = i;
     if (!SUCCEEDED(pCommandBars->get_Item(idx, &pCommandBar)))
      continue;
     MessageBoxW(NULL, L"success", NULL, MB_TOPMOST);
     BSTR name;
     if (!SUCCEEDED(pCommandBar->get_Name(&name)))
      continue;
     MessageBoxW(NULL, name, NULL, NULL);
    }
#endif
   }


#if 0 //!@ 主菜单操作
   auto hr = m_pVGApplication->get_MainMenu(&pMainMenu);
   auto sss = pMainMenu->GetControls();
   //VARIANT_BOOL ddd;
   sss->AddCustomControl(bstr_t("akdslfjg"), bstr_t(""), 3, TRUE);
   long count = 0;
   sss->get_Count(&count);
   for (long i = 0; i < count; ++i) {
    VGCore::ICUIControl* ctrl = nullptr;
    if (!SUCCEEDED(sss->get_Item(i, &ctrl)))
     continue;

    _bstr_t name = ctrl->GetCaption();
    _bstr_t desc_text = ctrl->GetDescriptionText();
    _bstr_t id = ctrl->GetID();

    if (wcscmp(L"6c91d5ab-d648-4364-96fb-3e71bcfaf70d", id.GetBSTR()) != 0)
     continue;

    void* com_ctrl = nullptr;
    GUID guid;
    if (!SUCCEEDED(CLSIDFromString(L"6c91d5ab-d648-4364-96fb-3e71bcfaf70d", &guid))) {
     MessageBoxW(NULL, L"Get GUID Failed 1.", NULL, MB_TOPMOST);
    }
    if (!SUCCEEDED(ctrl->QueryInterface(guid, &com_ctrl))) {

     MessageBoxW(NULL, L"Get GUID Failed 2.", NULL, MB_TOPMOST);
    }


    MessageBoxW(NULL, name, NULL, MB_TOPMOST);
    /*if (!name ||!desc_text || !id)
     continue;*/





     /*std::wstring output_msg =
      std::format(L"desc {}, name {}, id {}", desc_text.GetBSTR(), name.GetBSTR(), id.GetBSTR());
     MessageBoxW(NULL, output_msg.c_str(), NULL, MB_TOPMOST);*/
     /*
     ---------------------------
 错误
 ---------------------------
 desc 工具(O), name 工具(&O), id 0f948c18-f326-40e5-9beb-2efc73803797
 ---------------------------
 确定
 ---------------------------


 /*
 * ---------------------------
 错误
 ---------------------------
 desc 窗口(W), name 窗口(&W), id 6c91d5ab-d648-4364-96fb-3e71bcfaf70d
 ---------------------------
 确定
 ---------------------------

 */
   }
#endif//@主菜单操作



   //auto ret = sss->AddCustomButton(_bstr_t("MyPluginButton"), _bstr_t("My PluginButton"), 0, success);

   //if (ret) {
   // MessageBoxW(NULL, L"CDR Append button Success!", NULL, NULL);
   //}
  } while (0);
  return result;
 }

#if 0
#include "stdafx.h"
#include "VGAppPlugin.h"

 // 导入CorelDRAW的类型库
#import "C:\Program Files\Corel\CorelDRAW Graphics Suite 2022\Programs64\CorelDrw.tlb" no_namespace

// 定义按钮点击回调函数
 bool STDMETHODCALLTYPE ButtonClickCallback(void* /* appData */) {
  // 在按钮点击时执行的操作
  // 这里可以添加你的自定义逻辑
  // ...

  return true; // 返回true表示操作成功
 }

 // 实现插件类
 class CMyPlugin : public VGAppPlugin {
 public:
  CMyPlugin() {}

  // 实现COM接口的raw_StartSession方法
  STDMETHOD(raw_StartSession)() {
   // 获取CorelDRAW应用程序对象
   IApplicationPtr pApp;
   pApp.CreateInstance("CorelDRAW.Application");

   // 获取主菜单
   IControlBarPtr pMainMenu = pApp->GetUI()->GetControlBar(cdrMenuType_Main);

   // 添加自定义按钮
   VARIANT_BOOL success = VARIANT_TRUE;
   pMainMenu->AddCustomButton(_bstr_t("MyPluginButton"), _bstr_t("My Plugin Button"), 0, success);

   // 注册按钮回调函数
   if (success == VARIANT_TRUE) {
    RegisterEvent(_bstr_t("MyPluginButton"), cdrClick, &ButtonClickCallback, nullptr);
   }

   return S_OK;
  }
 };

 // 导出插件类
 extern "C" CMyPlugin * CreatePluginInstance() {
  return new CMyPlugin();
 }
#endif

 COM_DECLSPEC_NOTHROW HRESULT STDMETHODCALLTYPE VGAppPlugin::raw_StartSession(void) {
  HRESULT result = S_OK;
  //MessageBoxW(NULL, __FUNCTIONW__, NULL, MB_TOPMOST);
  do {

   auto pNewCommandBar = m_pVGApplication->CommandBars->Add(_bstr_t(L"小慧辅助工具®"), VGCore::cuiBarPosition::cuiBarFloating, VARIANT_FALSE);
   if (!pNewCommandBar)
    break;
   VGCore::ICUIControlPtr pControl = pNewCommandBar->Controls->AddCustomButton(/*VGCore::cdrCmdCategoryPlugins*/_bstr_t("yijianzhuanqu"), _bstr_t("一键转曲"), 1, VARIANT_FALSE);
   if (pControl) {
    pControl->put_Width(100);
    pControl->put_Height(30);

    pControl->put_Visible(VARIANT_TRUE);

    wchar_t* ico = new wchar_t[50];
    wmemset(ico, 0x00, 50);
    wmemcpy(ico, L"D:\\taiji.ico", wcslen(L"D:\\taiji.ico"));
    pControl->raw_SetIcon(16, 16);
    pControl->raw_SetIcon2(ico);
    pControl->raw_SetCustomIcon(ico);
   }


   MessageBoxW(NULL, L"Append plugin cmd success.", NULL, MB_TOPMOST);











#if 1
   //VARIANT_BOOL success = VARIANT_TRUE;
   //VGCore::ICUICommandBarPtr pMainMenu = nullptr;
   //
   //m_pVGApplication->get_MainMenu(&pMainMenu);
   //auto sss = pMainMenu->GetControls();
   //sss->AddCustomButton(_bstr_t("MyPluginButton"), _bstr_t("My PluginButton"), 0, success);
   //VGCore::IControlBarPtr pMainMenu = pApp->GetUI()->GetControlBar(cdrMenuType_Main);

   // 添加自定义按钮
   //VARIANT_BOOL success = VARIANT_TRUE;
   //pMainMenu->AddCustomButton(_bstr_t("MyPluginButton"), _bstr_t("My Plugin Button"), 0, success);



   //auto pCmds = m_pVGApplication->GetCommandBars();
   //auto pCreate = pCmds->Add(_bstr_t("Martell Button test"), VGCore::cuiBarPosition::cuiBarLeft, success);
#if 0
   m_pVGApplication->raw_AddPluginCommand(_bstr_t("ClearFill"), _bstr_t("Clear Fill"), _bstr_t("Clears fill from selected objects"), &success);
   //LOGINFO("raw_AddPluginCommand({}) on ({})", success == VARIANT_TRUE ? "success" : "failed", __FUNCTION__);
   auto pCmds = m_pVGApplication->GetCommandBars();
   auto pCreate = pCmds->Add(_bstr_t("ClearFill"), VGCore::cuiBarPosition::cuiBarLeft, success);

   m_pVGApplication->AddPluginCommand(_bstr_t("ClearFill"), _bstr_t("Clear Fill"), _bstr_t("Clears fill from selected objects"));
   auto pControlPtr = m_pVGApplication->CommandBars->Item[_bstr_t("Standard")]->Controls->AddCustomButton(VGCore::cdrCmdCategoryPlugins, _bstr_t("ClearFill"), 0, VARIANT_TRUE);
   /*VGCore::CommandBarControlPtr ctl = */
   /*_bstr_t bstrPath(m_pVGApplication->Path + _bstr_t("Plugins\\ClearFill.bmp"));
   pControlPtr->SetCustomIcon(bstrPath);*/
   //m_lCookie = m_pVGApplication->AdviseEvents(this);
#endif
   m_lCookie = m_pVGApplication->AdviseEvents(this);
#endif


   //try
   //{
   // m_pVGApplication->AddPluginCommand(_bstr_t("ClearFill"), _bstr_t("Clear Fill"), _bstr_t("Clears fill from selected objects"));
   // VGCore::ICUIControlPtr ctl = m_pVGApplication->CommandBars->Item[_bstr_t("Standard")]->Controls->AddCustomButton(VGCore::cdrCmdCategoryPlugins, _bstr_t("ClearFill"), 0, VARIANT_TRUE);
   // //_bstr_t bstrPath(m_pVGApplication->Path + _bstr_t("D:\\Yin_yang.svg.png"));
   // //ctl->SetCustomIcon(bstrPath);
   // m_lCookie = m_pVGApplication->AdviseEvents(this);
   //}
   //catch (_com_error& e)
   //{
   // MessageBoxW(NULL, e.Description(), L"Error", MB_ICONSTOP);
   //}
  } while (0);
  //LOGINFO("{}({}({}))", __FUNCTION__, "m_lCookie", m_lCookie);
  return result;
 }
 COM_DECLSPEC_NOTHROW HRESULT STDMETHODCALLTYPE VGAppPlugin::raw_StopSession(void) {
  HRESULT result = S_OK;
  do {
   //try
   //{
   // m_pVGApplication->UnadviseEvents(m_lCookie);
   // m_pVGApplication->RemovePluginCommand(_bstr_t("ClearFill"));
   //}
   //catch (_com_error& e)
   //{
   // MessageBoxW(NULL, e.Description(), L"Error", MB_ICONSTOP);
   //}
   result = m_pVGApplication->UnadviseEvents(m_lCookie);
  } while (0);
  //LOGINFO("{}", __FUNCTION__);
  return result;
 }
 COM_DECLSPEC_NOTHROW HRESULT STDMETHODCALLTYPE VGAppPlugin::raw_OnUnload(void) {
  //MessageBoxW(NULL, __FUNCTIONW__, NULL, NULL);

  HRESULT result = S_FALSE;
  do {
   if (!m_pVGApplication)
    break;
   m_pVGApplication->Release();
   m_pVGApplication = nullptr;
   result = S_OK;
  } while (0);
  //LOGINFO("{}", __FUNCTION__);

  LOG_UNINIT;
  return result;
 }


 /* [local] */ HRESULT STDMETHODCALLTYPE VGAppPlugin::Invoke(
  /* [annotation][in] */
  _In_  DISPID dispIdMember,
  /* [annotation][in] */
  _In_  REFIID riid,
  /* [annotation][in] */
  _In_  LCID lcid,
  /* [annotation][in] */
  _In_  WORD wFlags,
  /* [annotation][out][in] */
  _In_  DISPPARAMS* pDispParams,
  /* [annotation][out] */
  _Out_opt_  VARIANT* pVarResult,
  /* [annotation][out] */
  _Out_opt_  EXCEPINFO* pExcepInfo,
  /* [annotation][out] */
  _Out_opt_  UINT* puArgErr) {
  HRESULT result = S_OK;
  switch (dispIdMember) {
  case 0x0008: {//!@ OnSave???

  }break;
  case 0x0011: {//!@ DISPID_APP_SELCHANGE

  }break;
  case 0x0012: {//!@ DISPID_APP_START
   //LOGINFO("{}({})", __FUNCTION__, "DISPID_APP_START");
  }break;
  case 0x0014: {//!@ DISPID_APP_ONPLUGINCMD

  }break;
  case 0x0015: {//!@ DISPID_APP_ONPLUGINCMDSTATE

  }break;
  default:
   break;
  }

  puArgErr = nullptr;
  pExcepInfo = nullptr;
  pVarResult = nullptr;
  return result;
 }

}///namespace local
