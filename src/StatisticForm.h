//-----------------------------------------------------------------------------
//
//	GraphStudioNext
//
//	Author : CPlusSharp
//
//-----------------------------------------------------------------------------
#pragma once

class CGraphView;

struct GraphStatisticEntry
{
    long lIndex;
    BSTR szName;
    long lCount;
    double dLast;
    double dAverage;
    double dStdDev;
    double dMin;
    double dMax;
};

//-----------------------------------------------------------------------------
//
//	CStatisticForm class
//
//-----------------------------------------------------------------------------
class CStatisticForm : public CGraphStudioModelessDialog
{
protected:
	DECLARE_DYNAMIC(CStatisticForm)
	DECLARE_MESSAGE_MAP()

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    const CString CStatisticForm::GetEntryString(LONG entryNr, int field);
    GraphStatisticEntry* GetEntry(LONG entryNr);
	LONG GetEntryCount(bool reset);

    void FreeCachedStatisticEntry();
    GraphStatisticEntry m_cachedEntry;

public:
	GraphStudio::TitleBar	title;
    CButton					btn_reset;
	CButton					btn_export;
	CButton					btn_filter_mapper;
    CListCtrl               m_listCtrl;
	bool					show_filter_mapper;

public:
	CStatisticForm(CWnd* pParent = NULL);   // standard constructor
	virtual ~CStatisticForm();
	virtual CRect GetDefaultRect() const;

	enum { IDD = IDD_DIALOG_STATISTIC };

	// initialization
	BOOL DoCreateDialog(CWnd* parent);
	void OnSize(UINT nType, int cx, int cy);

	afx_msg void OnTimer(UINT_PTR id);
	afx_msg void OnResetClick();
    afx_msg void OnExportClick();
    afx_msg void OnFilterMapperClick();
    afx_msg void OnLvnGetdispinfoListData(NMHDR *pNMHDR, LRESULT *pResult);
};
