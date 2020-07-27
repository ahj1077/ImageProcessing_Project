#pragma once


// CMulDlg 대화 상자

class CMulDlg : public CDialog
{
	DECLARE_DYNAMIC(CMulDlg)

public:
	CMulDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CMulDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_MUL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnImageprocessingMul();
	double m_Constant;
};
