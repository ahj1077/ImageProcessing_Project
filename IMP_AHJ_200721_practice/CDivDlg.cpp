// CDivDlg.cpp: 구현 파일
//

#include "pch.h"
#include "IMP_AHJ_200721_practice.h"
#include "CDivDlg.h"
#include "afxdialogex.h"


// CDivDlg 대화 상자

IMPLEMENT_DYNAMIC(CDivDlg, CDialog)

CDivDlg::CDivDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_DIV, pParent)
	, m_Constant(0)
{

}

CDivDlg::~CDivDlg()
{
}

void CDivDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_Constant);
	DDV_MinMaxDouble(pDX, m_Constant, 0, 255);
}


BEGIN_MESSAGE_MAP(CDivDlg, CDialog)
END_MESSAGE_MAP()


