// CMulDlg.cpp: 구현 파일
//

#include "pch.h"
#include "IMP_AHJ_200721_practice.h"
#include "CMulDlg.h"
#include "afxdialogex.h"


// CMulDlg 대화 상자

IMPLEMENT_DYNAMIC(CMulDlg, CDialog)

CMulDlg::CMulDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_MUL, pParent)
	, m_Constant(0)
{

}

CMulDlg::~CMulDlg()
{
}

void CMulDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//  DDX_Text(pDX, IDC_EDIT1, m_Contant);
	//  DDV_MinMaxDouble(pDX, m_Contant, 0, 255);
	DDX_Text(pDX, IDC_EDIT1, m_Constant);
	DDV_MinMaxDouble(pDX, m_Constant, 0, 255);
}


BEGIN_MESSAGE_MAP(CMulDlg, CDialog)
END_MESSAGE_MAP()


