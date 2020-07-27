// CStressDlg.cpp: 구현 파일
//

#include "pch.h"
#include "IMP_AHJ_200721_practice.h"
#include "CStressDlg.h"
#include "afxdialogex.h"


// CStressDlg 대화 상자

IMPLEMENT_DYNAMIC(CStressDlg, CDialog)

CStressDlg::CStressDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_STRESS, pParent)
	, m_StartPoint(0)
	, m_EndPoint(0)
{

}

CStressDlg::~CStressDlg()
{
}

void CStressDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_StartPoint);
	DDV_MinMaxInt(pDX, m_StartPoint, 0, 255);
	DDX_Text(pDX, IDC_EDIT2, m_EndPoint);
}


BEGIN_MESSAGE_MAP(CStressDlg, CDialog)
END_MESSAGE_MAP()


// CStressDlg 메시지 처리기
