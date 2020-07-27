// CAddDlg.cpp: 구현 파일
//

#include "pch.h"
#include "IMP_AHJ_200721_practice.h"
#include "CAddDlg.h"
#include "afxdialogex.h"


// CAddDlg 대화 상자

IMPLEMENT_DYNAMIC(CAddDlg, CDialog)

CAddDlg::CAddDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_ADD, pParent)
	, m_Constant(0)
{

}

CAddDlg::~CAddDlg()
{
}

void CAddDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_Constant);
	DDV_MinMaxDouble(pDX, m_Constant, 0, 255);
}


BEGIN_MESSAGE_MAP(CAddDlg, CDialog)
//	ON_COMMAND(ID_IMAGEPROCESSING_ADD, &CAddDlg::OnImageprocessingAdd)
END_MESSAGE_MAP()

