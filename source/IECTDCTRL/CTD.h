// CTD.h : CCTD 的声明

#pragma once
#include "resource.h"       // 主符号

#include "IECTDCTRL_i.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE 平台(如不提供完全 DCOM 支持的 Windows Mobile 平台)上无法正确支持单线程 COM 对象。定义 _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA 可强制 ATL 支持创建单线程 COM 对象实现并允许使用其单线程 COM 对象实现。rgs 文件中的线程模型已被设置为“Free”，原因是该模型是非 DCOM Windows CE 平台支持的唯一线程模型。"
#endif



// CCTD

class ATL_NO_VTABLE CCTD :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CCTD, &CLSID_CTD>,
	public IObjectWithSiteImpl<CCTD>,
	public IDispatchImpl<ICTD, &IID_ICTD, &LIBID_IECTDCTRLLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
	public IOleCommandTarget
{
public:
	CCTD();

DECLARE_REGISTRY_RESOURCEID(IDR_CTD)


BEGIN_COM_MAP(CCTD)
	COM_INTERFACE_ENTRY(ICTD)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IObjectWithSite)
	COM_INTERFACE_ENTRY(IOleCommandTarget)
END_COM_MAP()

	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:
	STDMETHOD(SetSite)(IUnknown * pUnkSite);  
	STDMETHOD(QueryStatus)(const GUID *,ULONG,OLECMD [],OLECMDTEXT *);  
	STDMETHOD(Exec)(const GUID *,DWORD,DWORD,VARIANT *,VARIANT *);  
private:
	CComPtr<IWebBrowser2> m_spWebBrowser;//保存Browser指针的私有变量
	eSpace::IECSEspaceApp *m_pEspaceApp;
};

OBJECT_ENTRY_AUTO(__uuidof(CTD), CCTD)
