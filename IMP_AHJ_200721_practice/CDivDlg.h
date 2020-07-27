#pragma once


// CDivDlg 대화 상자

class CDivDlg : public CDialog
{
	DECLARE_DYNAMIC(CDivDlg)

public:
	CDivDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDivDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_DIV };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnImageprocessingDiv();
	double m_Constant;
};
