#if !defined(INC_H___3E548501_2719_447B_8FD7_CEEC7C097AC7__HEAD__)
#define INC_H___3E548501_2719_447B_8FD7_CEEC7C097AC7__HEAD__

namespace local {

 class VGAppPlugin final : public VGCore::IVGAppPlugin {
 public:
  VGAppPlugin();
  virtual ~VGAppPlugin();
 private:
  long m_lCookie = 0;
  unsigned long m_ulRefCount = 1;
  //VGCore::IVGApplication* m_pVGApplication = nullptr;
  VGCore::IVGApplicationPtr m_pVGApplication = nullptr;
 protected://!@IVGAppPlugin
  COM_DECLSPEC_NOTHROW HRESULT STDMETHODCALLTYPE raw_OnLoad(
   /*[in]*/ struct VGCore::IVGApplication* Application) override final;
  COM_DECLSPEC_NOTHROW HRESULT STDMETHODCALLTYPE raw_StartSession() override final;
  COM_DECLSPEC_NOTHROW HRESULT STDMETHODCALLTYPE raw_StopSession() override final;
  COM_DECLSPEC_NOTHROW HRESULT STDMETHODCALLTYPE raw_OnUnload() override final;
 protected://!@IDispatch
  HRESULT STDMETHODCALLTYPE GetTypeInfoCount(
   /* [out] */ __RPC__out UINT* pctinfo) override final {
   return E_NOTIMPL;
  }

  HRESULT STDMETHODCALLTYPE GetTypeInfo(
   /* [in] */ UINT iTInfo,
   /* [in] */ LCID lcid,
   /* [out] */ __RPC__deref_out_opt ITypeInfo** ppTInfo) override final {
   return E_NOTIMPL;
  }

  HRESULT STDMETHODCALLTYPE GetIDsOfNames(
   /* [in] */ __RPC__in REFIID riid,
   /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR* rgszNames,
   /* [range][in] */ __RPC__in_range(0, 16384) UINT cNames,
   /* [in] */ LCID lcid,
   /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID* rgDispId) override final {
   return E_NOTIMPL;
  }

  /* [local] */ HRESULT STDMETHODCALLTYPE Invoke(
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
   _Out_opt_  UINT* puArgErr) override final;
 protected://!@IUnknown
  HRESULT STDMETHODCALLTYPE QueryInterface(
   /* [in] */ REFIID riid,
   /* [iid_is][out] */ _COM_Outptr_ void __RPC_FAR* __RPC_FAR* ppvObject) override final {
   *ppvObject = nullptr;
   HRESULT result = S_OK;
   m_ulRefCount++;
   if (riid == IID_IUnknown)
   {
    *ppvObject = (IUnknown*)this;
    //LOGINFO("{}({})", __FUNCTION__, R"(*ppvObject = (IUnknown*)this)");
   }
   else if (riid == IID_IDispatch)
   {
    *ppvObject = (IDispatch*)this;
    //LOGINFO("{}({})", __FUNCTION__, R"(*ppvObject = (IDispatch*)this)");
   }
   else if (riid == __uuidof(VGCore::IVGAppPlugin))
   {
    *ppvObject = (VGCore::IVGAppPlugin*)this;
    //LOGINFO("{}({})", __FUNCTION__, R"(*ppvObject = (VGCore::IVGAppPlugin*)this)");
   }
   else
   {
    m_ulRefCount--;
    result = E_NOINTERFACE;
    //LOGINFO("{}({})", __FUNCTION__, R"(m_ulRefCount--)");
   }
   return result;
  }

  ULONG STDMETHODCALLTYPE AddRef(void) override final {
   ULONG result = 0;
   do {
    result = m_ulRefCount++;
   } while (0);
   //LOGINFO("{}", __FUNCTION__);
   return result;
  }

  ULONG STDMETHODCALLTYPE Release(void) override final {
   ULONG result = 0;
   do {
    ULONG ulCount = --m_ulRefCount;
    if (ulCount <= 0)
     delete this;
    result = ulCount;
   } while (0);
   //LOGINFO("{}", __FUNCTION__);
   return result;
  }

 };
}///namespace local

/// /*新生®（上海）**/
/// /*2022_11_14T09:15:30.5143843Z**/
/// /*_ _ _ _ _ _ _ www.skstu.com _ _ _ _ _ _ _**/
#endif ///INC_H___3E548501_2719_447B_8FD7_CEEC7C097AC7__HEAD__