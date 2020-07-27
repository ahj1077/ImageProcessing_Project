#pragma once


// CStressDlg 대화 상자

class CStressDlg : public CDialog
{
	DECLARE_DYNAMIC(CStressDlg)

public:
	CStressDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CStressDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_STRESS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	int m_StartPoint;
	int m_EndPoint;
};
