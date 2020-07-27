// CSubDlg.cpp: 구현 파일
//

#include "pch.h"
#include "IMP_AHJ_200721_practice.h"
#include "CSubDlg.h"
#include "afxdialogex.h"


// CSubDlg 대화 상자

IMPLEMENT_DYNAMIC(CSubDlg, CDialog)

CSubDlg::CSubDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_SUB, pParent)
	, m_Constant(0)
{

}

CSubDlg::~CSubDlg()
{
}

void CSubDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_Constant);
	DDV_MinMaxDouble(pDX, m_Constant, 1, 255);
}


BEGIN_MESSAGE_MAP(CSubDlg, CDialog)
END_MESSAGE_MAP()


