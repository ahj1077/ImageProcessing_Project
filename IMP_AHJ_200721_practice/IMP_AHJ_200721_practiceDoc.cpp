
// IMP_AHJ_200721_practiceDoc.cpp: CIMPAHJ200721practiceDoc 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "IMP_AHJ_200721_practice.h"
#endif

#include "IMP_AHJ_200721_practiceDoc.h"
#include"CDownSampleDlg.h"
#include"CUpSampleDlg.h"
#include"CQuantizationDlg.h"
#include"CAddDlg.h"
#include"CSubDlg.h"
#include"CMulDlg.h"
#include"CDivDlg.h"
#include"CConstantDlg.h"
#include"CStressDlg.h"

#include"math.h"
#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CIMPAHJ200721practiceDoc

IMPLEMENT_DYNCREATE(CIMPAHJ200721practiceDoc, CDocument)

BEGIN_MESSAGE_MAP(CIMPAHJ200721practiceDoc, CDocument)
	ON_COMMAND(ID_Quantization, &CIMPAHJ200721practiceDoc::OnQuantization)
	ON_COMMAND(ID_IMAGEPROCESSING_ADD, &CIMPAHJ200721practiceDoc::OnImageprocessingAdd)
	ON_COMMAND(ID_IMAGEPROCESSING_SUB, &CIMPAHJ200721practiceDoc::OnImageprocessingSub)
	ON_COMMAND(ID_IMAGEPROCESSING_MUL, &CIMPAHJ200721practiceDoc::OnImageprocessingMul)
	ON_COMMAND(ID_IMAGEPROCESSING_DIV, &CIMPAHJ200721practiceDoc::OnImageprocessingDiv)
	ON_COMMAND(ID_LOGICAL_AND, &CIMPAHJ200721practiceDoc::OnLogicalAnd)
	ON_COMMAND(ID_LOGICAL_OR, &CIMPAHJ200721practiceDoc::OnLogicalOr)
	ON_COMMAND(ID_LOGICAL_XOR, &CIMPAHJ200721practiceDoc::OnLogicalXor)
	ON_COMMAND(ID_LOGICAL_NOT, &CIMPAHJ200721practiceDoc::OnLogicalNot)
	ON_COMMAND(ID_NEGA_TRANSFORM, &CIMPAHJ200721practiceDoc::OnNegaTransform)
	ON_COMMAND(ID_GAMMA_CORRECTION, &CIMPAHJ200721practiceDoc::OnGammaCorrection)
	ON_COMMAND(ID_BINARIZATION, &CIMPAHJ200721practiceDoc::OnBinarization)
	ON_COMMAND(ID_STRESS_TRANSFORM, &CIMPAHJ200721practiceDoc::OnStressTransform)
	ON_COMMAND(ID_HISTO_STRETCH, &CIMPAHJ200721practiceDoc::OnHistoStretch)
	ON_COMMAND(ID_HISTOGRAM, &CIMPAHJ200721practiceDoc::OnHistogram)
	ON_COMMAND(ID_HISTO_EQUAL, &CIMPAHJ200721practiceDoc::OnHistoEqual)
	ON_COMMAND(ID_HISTO_SPEC, &CIMPAHJ200721practiceDoc::OnHistoSpec)
	ON_COMMAND(ID_EMBOSSING, &CIMPAHJ200721practiceDoc::OnEmbossing)
	ON_COMMAND(ID_BLURR, &CIMPAHJ200721practiceDoc::OnBlurr)
	ON_COMMAND(ID_GAUSSIAN_FILTER, &CIMPAHJ200721practiceDoc::OnGaussianFilter)
	ON_COMMAND(ID_SHARPENING, &CIMPAHJ200721practiceDoc::OnSharpening)
	ON_COMMAND(ID_HPF_SHARP, &CIMPAHJ200721practiceDoc::OnHpfSharp)
	ON_COMMAND(ID_LPF_SHARP, &CIMPAHJ200721practiceDoc::OnLpfSharp)
	ON_COMMAND(ID_DIFF_OPERATOR_HOR, &CIMPAHJ200721practiceDoc::OnDiffOperatorHor)
	ON_COMMAND(ID_HOMOGEN_OPERATOR, &CIMPAHJ200721practiceDoc::OnHomogenOperator)
	ON_COMMAND(ID_LAPLACIAN, &CIMPAHJ200721practiceDoc::OnLaplacian)
	ON_COMMAND(ID_NEAREST, &CIMPAHJ200721practiceDoc::OnNearest)
	ON_COMMAND(ID_BILINEAR, &CIMPAHJ200721practiceDoc::OnBilinear)
	ON_COMMAND(ID_MEDIAN_SUB, &CIMPAHJ200721practiceDoc::OnMedianSub)
	ON_COMMAND(ID_MEAN_SUB, &CIMPAHJ200721practiceDoc::OnMeanSub)
	ON_COMMAND(ID_TRANSLATION, &CIMPAHJ200721practiceDoc::OnTranslation)
	ON_COMMAND(ID_MIRROR_HOR, &CIMPAHJ200721practiceDoc::OnMirrorHor)
	ON_COMMAND(ID_MIRROR_VER, &CIMPAHJ200721practiceDoc::OnMirrorVer)
	ON_COMMAND(ID_ROTATION, &CIMPAHJ200721practiceDoc::OnRotation)
END_MESSAGE_MAP()


// CIMPAHJ200721practiceDoc 생성/소멸

CIMPAHJ200721practiceDoc::CIMPAHJ200721practiceDoc() noexcept
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CIMPAHJ200721practiceDoc::~CIMPAHJ200721practiceDoc()
{
}

BOOL CIMPAHJ200721practiceDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// CIMPAHJ200721practiceDoc serialization

void CIMPAHJ200721practiceDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 여기에 저장 코드를 추가합니다.
	}
	else
	{
		// TODO: 여기에 로딩 코드를 추가합니다.
	}
}

#ifdef SHARED_HANDLERS

// 축소판 그림을 지원합니다.
void CIMPAHJ200721practiceDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 문서의 데이터를 그리려면 이 코드를 수정하십시오.
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT)GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 검색 처리기를 지원합니다.
void CIMPAHJ200721practiceDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 문서의 데이터에서 검색 콘텐츠를 설정합니다.
	// 콘텐츠 부분은 ";"로 구분되어야 합니다.

	// 예: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CIMPAHJ200721practiceDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl* pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CIMPAHJ200721practiceDoc 진단

#ifdef _DEBUG
void CIMPAHJ200721practiceDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CIMPAHJ200721practiceDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CIMPAHJ200721practiceDoc 명령


BOOL CIMPAHJ200721practiceDoc::OnOpenDocument(LPCTSTR lpszPathName)
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.

	
	CFile File;
	File.Open(lpszPathName, CFile::modeRead | CFile::typeBinary);

	if (File.GetLength() == 256 * 256) {
		m_width = 256;
		m_height = 256;
	}
	else if (File.GetLength() == 512 * 512) {
		m_height = 512;
		m_width = 512;
	}
	else if (File.GetLength() == 640 * 480) {
		m_height = 480;
		m_width = 640;
	}
	else {
		AfxMessageBox(L"Not Support Image Size");
		return 0;
	}

	m_size = m_width * m_height;

	m_InputImage = new unsigned char[m_size];

	for (int i = 0; i < m_size; i++)
		m_InputImage[i] = 255;

	File.Read(m_InputImage, m_size);
	File.Close();

	return TRUE;
}


BOOL CIMPAHJ200721practiceDoc::OnSaveDocument(LPCTSTR lpszPathName)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	CFile File;

	CFileDialog SaveDlg(FALSE, L"raw", NULL, OFN_HIDEREADONLY);

	if (SaveDlg.DoModal() == IDOK) {
		File.Open(SaveDlg.GetPathName(), CFile::modeCreate | CFile::modeWrite);
		File.Write(m_InputImage, m_size);
		File.Close();
	}


	return TRUE;
}


void CIMPAHJ200721practiceDoc::OnDownSampling()
{
	// TODO: 여기에 구현 코드 추가.
	CDownSampleDlg dlg;

	if (dlg.DoModal() == IDOK) {
		m_Re_height = m_height / dlg.m_DownSampleRate;
		m_Re_width = m_width / dlg.m_DownSampleRate;
		m_Re_size = m_Re_height * m_Re_width;

		m_OutputImage = new unsigned char[m_Re_size];

		for (int i = 0; i < m_Re_height; i++) {
			for (int j = 0; j < m_Re_width; j++) {
				m_OutputImage[i * m_Re_width + j] = m_InputImage[(i * dlg.m_DownSampleRate * m_width + dlg.m_DownSampleRate * j)];
			}
		}
	}

}

void CIMPAHJ200721practiceDoc::OnUpSampling()
{
	// TODO: 여기에 구현 코드 추가.
	CUpSampleDlg dlg;

	if (dlg.DoModal() == IDOK) {
		m_Re_height = m_height * dlg.m_UpSampleRate;
		m_Re_width = m_width * dlg.m_UpSampleRate;
		m_Re_size = m_Re_height * m_Re_width;


		///////////////////////////// memory allocation

		m_OutputImage = new unsigned char[m_Re_size];

		m_2DImage = new unsigned char* [m_Re_height];

		for (int i = 0; i < m_Re_width; i++) {
			m_2DImage[i] = new unsigned char[m_Re_width];
		}


		//bilinear interpolation

		for (int i = 0; i < m_Re_height; i++) {
			for (int j = 0; j < m_Re_width; j++) {

			}
		}

		/*for (int i = 0; i < m_Re_size; i++) {
			m_OutputImage[i] = 0;
		}


		for (int i = 0; i < m_height; i++) {
			for (int j = 0; j < m_width; j++) {
				m_OutputImage[i * dlg.m_UpSampleRate * m_Re_width + dlg.m_UpSampleRate * j] = m_InputImage[(i * m_width + j)];
			}
		}*/
	}

}



void CIMPAHJ200721practiceDoc::OnQuantization()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.

	CQuantizationDlg dlg;

	if (dlg.DoModal() == IDOK) {
		int i, j, value, LEVEL;
		double HIGH;
		double* TEMP;

		m_Re_height = m_height;
		m_Re_width = m_width;
		m_Re_size = m_Re_height * m_Re_width;

		m_OutputImage = new unsigned char[m_Re_size];

		TEMP = new double[m_size];

		LEVEL = 256;
		HIGH = 256.;

		value = (int)pow(2, dlg.m_QuanBit);

		for (i = 0; i < m_size; i++) {
			for (j = 0; j < value; j++) {
				if (m_InputImage[i] >= (LEVEL / value) * j && m_InputImage[i] < (LEVEL / value) * (j + 1)) {
					TEMP[i] = (double)(HIGH / value) * j;
				}
			}
		}

		for (i = 0; i < m_size; i++) {
			m_OutputImage[i] = (unsigned char)TEMP[i];
		}
	}
}


void CIMPAHJ200721practiceDoc::OnImageprocessingAdd()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CAddDlg dlg;

	if (dlg.DoModal() == IDOK) {
		m_Re_height = m_height;
		m_Re_width = m_width;
		m_Re_size = m_Re_height * m_Re_width;

		m_OutputImage = new unsigned char[m_Re_size];

		for (int i = 0; i < m_Re_height; i++) {
			for (int j = 0; j < m_Re_width; j++) {
				if (m_InputImage[(i * m_width + j)] + dlg.m_Constant > 255) {
					m_OutputImage[i * m_Re_width + j] = 255;
				}
				else {
					m_OutputImage[i * m_Re_width + j] = m_InputImage[(i * m_width + j)] + dlg.m_Constant;
				}
			}
		}

	}
}


void CIMPAHJ200721practiceDoc::OnImageprocessingSub()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CSubDlg dlg;
	if (dlg.DoModal() == IDOK) {
		m_Re_height = m_height;
		m_Re_width = m_width;
		m_Re_size = m_Re_height * m_Re_width;

		m_OutputImage = new unsigned char[m_Re_size];

		for (int i = 0; i < m_Re_height; i++) {
			for (int j = 0; j < m_Re_width; j++) {
				if (m_InputImage[(i * m_width + j)] - dlg.m_Constant < 0) {
					m_OutputImage[i * m_Re_width + j] = 0;
				}
				else {
					m_OutputImage[i * m_Re_width + j] = m_InputImage[(i * m_width + j)] - dlg.m_Constant;
				}
			}
		}
	}
}


void CIMPAHJ200721practiceDoc::OnImageprocessingMul()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CMulDlg dlg;
	if (dlg.DoModal() == IDOK) {
		m_Re_height = m_height;
		m_Re_width = m_width;
		m_Re_size = m_Re_height * m_Re_width;

		m_OutputImage = new unsigned char[m_Re_size];

		for (int i = 0; i < m_Re_height; i++) {
			for (int j = 0; j < m_Re_width; j++) {
				if (m_InputImage[(i * m_width + j)] * dlg.m_Constant > 255) {
					m_OutputImage[i * m_Re_width + j] = 255;
				}
				else {
					m_OutputImage[i * m_Re_width + j] = m_InputImage[(i * m_width + j)] * dlg.m_Constant;
				}
			}
		}
	}
}


void CIMPAHJ200721practiceDoc::OnImageprocessingDiv()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CDivDlg dlg;
	if (dlg.DoModal() == IDOK) {
		m_Re_height = m_height;
		m_Re_width = m_width;
		m_Re_size = m_Re_height * m_Re_width;

		m_OutputImage = new unsigned char[m_Re_size];

		for (int i = 0; i < m_Re_height; i++) {
			for (int j = 0; j < m_Re_width; j++) {
				m_OutputImage[i * m_Re_width + j] = m_InputImage[(i * m_width + j)] / dlg.m_Constant;
			}
		}

	}
}


void CIMPAHJ200721practiceDoc::OnLogicalAnd()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.

	CConstantDlg dlg;
	if (dlg.DoModal() == IDOK) {
		m_Re_height = m_height;
		m_Re_width = m_width;
		m_Re_size = m_Re_height * m_Re_width;

		m_OutputImage = new unsigned char[m_Re_size];

		for (int i = 0; i < m_Re_size; i++) {
			if ((m_InputImage[i] & (unsigned char)dlg.m_Constant) >= 255) {
				m_OutputImage[i] = 255;
			}
			else if ((m_InputImage[i] & (unsigned char)dlg.m_Constant) < 0) {
				m_OutputImage[i] = 0;
			}
			else {
				m_OutputImage[i] = (m_InputImage[i] & (unsigned char)dlg.m_Constant);
			}
		}

	}


}


void CIMPAHJ200721practiceDoc::OnLogicalOr()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CConstantDlg dlg;
	if (dlg.DoModal() == IDOK) {
		m_Re_height = m_height;
		m_Re_width = m_width;
		m_Re_size = m_Re_height * m_Re_width;

		m_OutputImage = new unsigned char[m_Re_size];

		for (int i = 0; i < m_Re_size; i++) {
			if ((m_InputImage[i] | (unsigned char)dlg.m_Constant) >= 255) {
				m_OutputImage[i] = 255;
			}
			else if ((m_InputImage[i] | (unsigned char)dlg.m_Constant) < 0) {
				m_OutputImage[i] = 0;
			}
			else {
				m_OutputImage[i] = (m_InputImage[i] | (unsigned char)dlg.m_Constant);
			}
		}

	}
}


void CIMPAHJ200721practiceDoc::OnLogicalXor()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CConstantDlg dlg;
	if (dlg.DoModal() == IDOK) {
		m_Re_height = m_height;
		m_Re_width = m_width;
		m_Re_size = m_Re_height * m_Re_width;

		m_OutputImage = new unsigned char[m_Re_size];

		for (int i = 0; i < m_Re_size; i++) {
			if ((m_InputImage[i] ^ (unsigned char)dlg.m_Constant) >= 255) {
				m_OutputImage[i] = 255;
			}
			else if ((m_InputImage[i] ^ (unsigned char)dlg.m_Constant) < 0) {
				m_OutputImage[i] = 0;
			}
			else {
				m_OutputImage[i] = (m_InputImage[i] ^ (unsigned char)dlg.m_Constant);
			}
		}

	}
}


void CIMPAHJ200721practiceDoc::OnLogicalNot()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.

	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height * m_Re_width;

	m_OutputImage = new unsigned char[m_Re_size];

	for (int i = 0; i < m_Re_size; i++) {
		m_OutputImage[i] = ~m_InputImage[i];
	}
}


void CIMPAHJ200721practiceDoc::OnNegaTransform()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.

	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height * m_Re_width;

	m_OutputImage = new unsigned char[m_Re_size];

	for (int i = 0; i < m_Re_size; i++) {
		m_OutputImage[i] = 255 - m_InputImage[i];
	}
}


void CIMPAHJ200721practiceDoc::OnGammaCorrection()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CConstantDlg dlg;
	if (dlg.DoModal() == IDOK) {
		m_Re_height = m_height;
		m_Re_width = m_width;
		m_Re_size = m_Re_height * m_Re_width;

		m_OutputImage = new unsigned char[m_Re_size];

		for (int i = 0; i < m_Re_size; i++) {
			double temp = pow(m_InputImage[i], 1 / dlg.m_Constant);
			if (temp < 0)
				m_OutputImage[i] = 0;
			else if (temp > 255)
				m_OutputImage[i] = 255;
			else
				m_OutputImage[i] = (unsigned char)temp;
		}

	}
}


void CIMPAHJ200721practiceDoc::OnBinarization()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CConstantDlg dlg;
	if (dlg.DoModal() == IDOK) {
		m_Re_height = m_height;
		m_Re_width = m_width;
		m_Re_size = m_Re_height * m_Re_width;

		m_OutputImage = new unsigned char[m_Re_size];

		for (int i = 0; i < m_Re_size; i++) {
			if (m_InputImage[i] >= dlg.m_Constant)
				m_OutputImage[i] = 255;
			else
				m_OutputImage[i] = 0;
		}

	}
}


void CIMPAHJ200721practiceDoc::OnStressTransform()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CStressDlg dlg;
	if (dlg.DoModal() == IDOK) {
		m_Re_height = m_height;
		m_Re_width = m_width;
		m_Re_size = m_Re_height * m_Re_width;

		m_OutputImage = new unsigned char[m_Re_size];

		for (int i = 0; i < m_Re_size; i++) {
			if (m_InputImage[i] >= dlg.m_StartPoint && m_InputImage[i] <= dlg.m_EndPoint)
				m_OutputImage[i] = 255;
			else
				m_OutputImage[i] = m_InputImage[i];;
		}

	}
}


void CIMPAHJ200721practiceDoc::OnHistoStretch()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.

	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height * m_Re_width;
	unsigned char MIN,MAX;
	unsigned char LOW = 0;
	unsigned char HIGH = 255;
	m_OutputImage = new unsigned char[m_Re_size];
	MIN = m_InputImage[0];
	MAX = m_InputImage[0];

	for (int i = 0; i < m_size; i++) {
		if (m_InputImage[i] < MIN)
			MIN = m_InputImage[i];
	}


	for (int i = 0; i < m_size; i++) {
		if (m_InputImage[i] > MAX)
			MAX = m_InputImage[i];
	}

	for(int i=0; i<m_size; i++)
		m_OutputImage[i] = (unsigned char)((m_InputImage[i] - MIN) * HIGH / (MAX - MIN));


}


double m_HIST[256];
double m_Sum_Of_HIST[256];
unsigned char m_Scale_HIST[256];


void CIMPAHJ200721practiceDoc::OnHistogram()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	int i, j, value;
	unsigned char LOW, HIGH;
	double MAX, MIN, DIF;

	m_Re_height = 256;
	m_Re_width = 256;
	m_Re_size = m_Re_height * m_Re_width;

	LOW = 0;
	HIGH = 255;

	for (int i = 0; i < 256; i++)
		m_HIST[i] = LOW;

	for (int i = 0; i < m_size; i++) {
		value = (int)m_InputImage[i];
		m_HIST[value]++;
	}

	MAX = m_HIST[0];
	MIN = m_HIST[0];

	for (int i = 0; i < 256; i++) {
		if (m_HIST[i] > MAX)
			MAX = m_HIST[i];
	}

	for (int i = 0; i < 256; i++) {
		if (m_HIST[i] < MIN)
			MIN = m_HIST[i];
	}

	DIF = MAX - MIN;
	

	for (int i = 0; i < 256; i++) {
		m_Scale_HIST[i] = (unsigned char)((m_HIST[i] - MIN) * HIGH / DIF);
	}

	m_OutputImage = new unsigned char[m_Re_size + (256 * 20)];

	for (int i = 0; i < m_Re_size; i++) {
		m_OutputImage[i] = 255;
	}

	for (int i = 0; i < 256; i++) {
		for (int j = 0; j < m_Scale_HIST[i]; j++) {
			m_OutputImage[m_Re_width * (m_Re_height - j - 1) + i] = 0;
		}
	}

	for (int i = m_Re_height; i < m_Re_height + 5; i++) {
		for (int j = 0; j < 256; j++) {
			m_OutputImage[m_Re_height * i + j] = 255;
		}
	}

	for (int i = m_Re_height + 5; i < m_Re_height + 20; i++) {
		for (int j = 0; j < 256; j++) {
			m_OutputImage[m_Re_height * i + j] = j;
		}
	}
	m_Re_height = m_Re_height + 20;
	m_Re_size = m_Re_height * m_Re_width;

}


void CIMPAHJ200721practiceDoc::OnHistoEqual()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	int value;
	unsigned char LOW, HIGH, Temp;
	double SUM = 0.0;
	
	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_height * m_width;

	LOW  = 0;
	HIGH = 255;

	for (int i = 0; i < 256; i++)
		m_HIST[i] = LOW;

	for (int i = 0; i < m_size; i++) {
		value = (int)m_InputImage[i];
		m_HIST[value]++;
	}

	for (int i = 0; i < 256; i++) {
		SUM += m_HIST[i];
		m_Sum_Of_HIST[i] = SUM;
	}

	m_OutputImage = new unsigned char[m_Re_size];

	for (int i = 0; i < m_size; i++) {
		Temp = m_InputImage[i];
		m_OutputImage[i] = (unsigned char)(m_Sum_Of_HIST[Temp] * HIGH / m_size);
	}

}


void CIMPAHJ200721practiceDoc::OnHistoSpec()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	int value, Dvalue, top, bottom, DADD;
	unsigned char* m_DTEMP, m_Sum_Of_ScHIST[256], m_TABLE[256];
	unsigned char LOW, HIGH, Temp, * m_Org_Temp;
	double m_DHIST[256], m_Sum_Of_DHIST[256], SUM = 0.0, DSUM = 0.0;
	double DMAX, DMIN;

	top = 255;
	bottom = top - 1;

	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_height * m_width;

	m_OutputImage = new unsigned char[m_Re_size];
	m_Org_Temp = new unsigned char[m_size];
	m_DTEMP = new unsigned char[m_size];

	CFile File;
	CFileDialog OpenDlg(TRUE);

	if (OpenDlg.DoModal() == IDOK) {
		File.Open(OpenDlg.GetPathName(), CFile::modeRead);
		if (File.GetLength() == (unsigned)m_size) {
			File.Read(m_DTEMP, m_size);
			File.Close();
		}
		else {
			AfxMessageBox(L"Image size not matched");
			return;
		}

		LOW = 0;
		HIGH = 255;

		for (int i = 0; i < 256; i++) {
			m_HIST[i] = LOW;
			m_DHIST[i] = LOW;
			m_TABLE[i] = LOW;
		}

		for (int i = 0; i < m_size; i++) {
			value = (int)m_InputImage[i];
			m_HIST[value]++;
			Dvalue = (int)m_DTEMP[i];
			m_DHIST[Dvalue]++;
		}

		for (int i = 0; i < 256; i++) {
			SUM += m_HIST[i];
			m_Sum_Of_HIST[i] = SUM;
			DSUM += m_DHIST[i];
			m_Sum_Of_DHIST[i] = DSUM;
		}

		for (int i = 0; i < m_size; i++) {
			Temp = m_InputImage[i];
			m_Org_Temp[i] = (unsigned char)(m_Sum_Of_HIST[Temp] * HIGH / m_size);
		}

		DMIN = m_Sum_Of_DHIST[0];
		DMAX = m_Sum_Of_DHIST[255];

		for (int i = 0; i < 256; i++) {
			m_Sum_Of_ScHIST[i] = (unsigned char)((m_Sum_Of_DHIST[i] - DMIN) * HIGH / (DMAX - DMIN));
		}

		for (;;) {
			for (int i = m_Sum_Of_ScHIST[bottom]; i <= m_Sum_Of_ScHIST[top]; i++) {
				m_TABLE[i] = top;
			}

			top = bottom;
			bottom = bottom - 1;

			if (bottom < -1)
				break;
		}

		for (int i = 0; i < m_size; i++) {
			DADD = (int)m_Org_Temp[i];
			m_OutputImage[i] = m_TABLE[DADD];
		}

	}
}


void CIMPAHJ200721practiceDoc::OnEmbossing()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.

	double EmboMask[3][3] = { {-1.,0.,0.},{0.,0.,0.},{0.,0.,1.} };
	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_height * m_width;
	m_OutputImage = new unsigned char[m_Re_size];
	m_tempImage = OnMaskProcess(m_InputImage, EmboMask);

	for (int i = 0; i < m_Re_height; i++) {
		for (int j = 0; j < m_Re_width; j++) {
			m_tempImage[i][j] += 128;
			if (m_tempImage[i][j] > 255.)
				m_tempImage[i][j] = 255.;
			if (m_tempImage[i][j] < 0.)
				m_tempImage[i][j] = 0.;
		}
	}

	//m_tempImage = OnScale(m_tempImage, m_Re_height, m_Re_width);
	
	for (int i = 0; i < m_Re_height; i++) {
		for (int j = 0; j < m_Re_width; j++) {
			m_OutputImage[i * m_Re_width + j] = (unsigned char)m_tempImage[i][j];
		}
	}
}

double** CIMPAHJ200721practiceDoc::OnMaskProcess(unsigned char* Target, double Mask[][3]) {
	double** tempInputImage, ** tempOutputImage, S = 0.0;

	tempInputImage = Image2DMem(m_height + 2, m_width + 2);
	tempOutputImage = Image2DMem(m_height, m_width);

	for (int i = 0; i < m_height; i++) {
		for (int j = 0; j < m_width; j++) {
			tempInputImage[i + 1][j + 1] = (double)Target[i * m_width + j];
		}
	}

	for (int i = 0; i < m_height; i++) {
		for (int j = 0; j < m_width; j++) {
			for (int n = 0; n < 3; n++) {
				for (int m = 0; m < 3; m++) {
					S += Mask[n][m] * tempInputImage[i + n][j + m];
				}
			}
			tempOutputImage[i][j] = S;
			S = 0.0;
		}
	}

	return tempOutputImage;
}

double** CIMPAHJ200721practiceDoc::OnScale(double **Target, int height,int width) {
	double min, max;
	min = max = Target[0][0];

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (Target[i][j] <= min)
				min = Target[i][j];
		}
	}

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (Target[i][j] >= max)
				max = Target[i][j];
		}
	}

	max = max - min;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			Target[i][j] = (Target[i][j] - min) * (255. / max);
		}
	}

	return Target;

}

double** CIMPAHJ200721practiceDoc::Image2DMem(int height, int width) {
	double** temp;
	temp = new double* [height];
	for (int i = 0; i < height; i++) {
		temp[i] = new double[width];
	}

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			temp[i][j] = 0.0;
		}
	}

	return temp;
}

void CIMPAHJ200721practiceDoc::OnBlurr()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	double BlurrMask[3][3] = { {1. / 9.,1. / 9.,1. / 9.},{1. / 9.,1. / 9.,1. / 9.},{1. / 9.,1. / 9.,1. / 9.} };

	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_height * m_width;
	m_OutputImage = new unsigned char[m_Re_size];

	m_tempImage = OnMaskProcess(m_InputImage, BlurrMask);

	for (int i = 0; i < m_Re_height; i++) {
		for (int j = 0; j < m_Re_width; j++) {
			if (m_tempImage[i][j] > 255.)
				m_tempImage[i][j] = 255.;
			if (m_tempImage[i][j] < 0.)
				m_tempImage[i][j] = 0.;
		}
	}

	for (int i = 0; i < m_Re_height; i++) {
		for (int j = 0; j < m_Re_width; j++) {
			m_OutputImage[i * m_Re_width + j] = (unsigned char)m_tempImage[i][j];
		}
	}

}


void CIMPAHJ200721practiceDoc::OnGaussianFilter()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	double GaussianMask[3][3] = { {1. / 16.,1. / 8.,1. / 16.},{1. / 8.,1. / 4.,1. / 8.},{1. / 16.,1. / 8.,1. / 16.} };
	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_height * m_width;
	m_OutputImage = new unsigned char[m_Re_size];

	m_tempImage = OnMaskProcess(m_InputImage, GaussianMask);

	for (int i = 0; i < m_Re_height; i++) {
		for (int j = 0; j < m_Re_width; j++) {
			if (m_tempImage[i][j] > 255.)
				m_tempImage[i][j] = 255.;
			if (m_tempImage[i][j] < 0.)
				m_tempImage[i][j] = 0.;
		}
	}

	for (int i = 0; i < m_Re_height; i++) {
		for (int j = 0; j < m_Re_width; j++) {
			m_OutputImage[i * m_Re_width + j] = (unsigned char)m_tempImage[i][j];
		}
	}

}


void CIMPAHJ200721practiceDoc::OnSharpening()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	double SharpeningMask[3][3] = { {0.,-1.,0.},{-1.,5.,-1.},{0.,-1.,0.} };
	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_height * m_width;
	m_OutputImage = new unsigned char[m_Re_size];

	m_tempImage = OnMaskProcess(m_InputImage, SharpeningMask);

	for (int i = 0; i < m_Re_height; i++) {
		for (int j = 0; j < m_Re_width; j++) {
			if (m_tempImage[i][j] > 255.)
				m_tempImage[i][j] = 255.;
			if (m_tempImage[i][j] < 0.)
				m_tempImage[i][j] = 0.;
		}
	}

	for (int i = 0; i < m_Re_height; i++) {
		for (int j = 0; j < m_Re_width; j++) {
			m_OutputImage[i * m_Re_width + j] = (unsigned char)m_tempImage[i][j];
		}
	}

}


void CIMPAHJ200721practiceDoc::OnHpfSharp()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	double HpfSharpMask[3][3] = { {-1. / 9. , -1. / 9. , -1. / 9.},{-1. / 9. , 8. / 9. , -1. / 9.},{-1. / 9. , -1. / 9. , -1. / 9.} };
	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_height * m_width;
	m_OutputImage = new unsigned char[m_Re_size];

	m_tempImage = OnMaskProcess(m_InputImage, HpfSharpMask);

	for (int i = 0; i < m_Re_height; i++) {
		for (int j = 0; j < m_Re_width; j++) {
			if (m_tempImage[i][j] > 255.)
				m_tempImage[i][j] = 255.;
			if (m_tempImage[i][j] < 0.)
				m_tempImage[i][j] = 0.;
		}
	}

	for (int i = 0; i < m_Re_height; i++) {
		for (int j = 0; j < m_Re_width; j++) {
			m_OutputImage[i * m_Re_width + j] = (unsigned char)m_tempImage[i][j];
		}
	}
}


void CIMPAHJ200721practiceDoc::OnLpfSharp()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.

	CConstantDlg dlg;
	int alpha;

	double LpfSharpMask[3][3] = { {1. / 9.,1. / 9.,1. / 9.},{1. / 9.,1. / 9.,1. / 9.},{1. / 9.,1. / 9.,1. / 9.} };
	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_height * m_width;
	m_OutputImage = new unsigned char[m_Re_size];

	if (dlg.DoModal() == IDOK) {
		alpha = (int)dlg.m_Constant;
	}

	m_tempImage = OnMaskProcess(m_InputImage, LpfSharpMask);


	for (int i = 0; i < m_Re_height; i++) {
		for (int j = 0; j < m_Re_width; j++) {
			m_tempImage[i][j] = (alpha * m_InputImage[i*m_width + j]) - (unsigned char)m_tempImage[i][j];
		}
	}

	for (int i = 0; i < m_Re_height; i++) {
		for (int j = 0; j < m_Re_width; j++) {
			if (m_tempImage[i][j] > 255.)
				m_tempImage[i][j] = 255.;
			if (m_tempImage[i][j] < 0.)
				m_tempImage[i][j] = 0.;
		}
	}

	for (int i = 0; i < m_Re_height; i++) {
		for (int j = 0; j < m_Re_width; j++) {
			m_OutputImage[i * m_Re_width + j] = (unsigned char)m_tempImage[i][j];
		}
	}
}


void CIMPAHJ200721practiceDoc::OnDiffOperatorHor()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.

	double DiffHorMask[3][3] = { {0.,-1.,0.},{0.,1.,0.},{0.,0.,0.} };
	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_height * m_width;
	m_OutputImage = new unsigned char[m_Re_size];

	m_tempImage = OnMaskProcess(m_InputImage, DiffHorMask);

	for (int i = 0; i < m_Re_height; i++) {
		for (int j = 0; j < m_Re_width; j++) {
			if (m_tempImage[i][j] > 255.)
				m_tempImage[i][j] = 255.;
			if (m_tempImage[i][j] < 0.)
				m_tempImage[i][j] = 0.;
		}
	}

	for (int i = 0; i < m_Re_height; i++) {
		for (int j = 0; j < m_Re_width; j++) {
			m_OutputImage[i * m_Re_width + j] = (unsigned char)m_tempImage[i][j];
		}
	}
}


void CIMPAHJ200721practiceDoc::OnHomogenOperator()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	double max, ** tempOutputImage;

	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_height * m_width;
	m_OutputImage = new unsigned char[m_Re_size];

	m_tempImage = Image2DMem(m_height + 2, m_width + 2);
	tempOutputImage = Image2DMem(m_Re_height, m_Re_width);

	for (int i = 0; i < m_Re_height; i++) {
		for (int j = 0; j < m_Re_width; j++) {
			m_tempImage[i + 1][j + 1] = (double)m_InputImage[i * m_width + j];
		}
	}

	for (int i = 0; i < m_Re_height; i++) {
		for (int j = 0; j < m_Re_width; j++) {
			max = 0.0;
			for (int n = 0; n < 3; n++) {
				for (int m = 0; m < 3; m++) {
					if (DoubleABS(m_tempImage[i + 1][j + 1]) - m_tempImage[i + n][j + m] >= max)
						max = DoubleABS(m_tempImage[i + 1][j + 1] - m_tempImage[i + n][j + m]);
				}
			}

			tempOutputImage[i][j] = max;
		}
	}

	for (int i = 0; i < m_Re_height; i++) {
		for (int j = 0; j < m_Re_width; j++) {
			if (m_tempImage[i][j] > 255.)
				m_tempImage[i][j] = 255.;
			if (m_tempImage[i][j] < 0.)
				m_tempImage[i][j] = 0.;
		}
	}

	for (int i = 0; i < m_Re_height; i++) {
		for (int j = 0; j < m_Re_width; j++) {
			m_OutputImage[i * m_Re_width + j] = (unsigned char)m_tempImage[i][j];
		}
	}
}


double CIMPAHJ200721practiceDoc::DoubleABS(double X) {
	if (X >= 0)
		return X;
	else
		return -X;
}

void CIMPAHJ200721practiceDoc::OnLaplacian()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	double LaplacianMask[3][3] = { {0.,1.,0.},{1.,-4.,1.},{0.,1.,0.} };
	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_height * m_width;
	m_OutputImage = new unsigned char[m_Re_size];

	m_tempImage = OnMaskProcess(m_InputImage, LaplacianMask);

	for (int i = 0; i < m_Re_height; i++) {
		for (int j = 0; j < m_Re_width; j++) {
			if (m_tempImage[i][j] > 255.)
				m_tempImage[i][j] = 255.;
			if (m_tempImage[i][j] < 0.)
				m_tempImage[i][j] = 0.;
		}
	}

	for (int i = 0; i < m_Re_height; i++) {
		for (int j = 0; j < m_Re_width; j++) {
			m_OutputImage[i * m_Re_width + j] = (unsigned char)m_tempImage[i][j];
		}
	}
}


void CIMPAHJ200721practiceDoc::OnNearest()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	int ZoomRate = 2;
	double** tempArray;
	m_Re_height = int(m_height * ZoomRate);
	m_Re_width = int(m_width * ZoomRate);
	m_Re_size = m_Re_height * m_Re_width;

	m_tempImage = Image2DMem(m_height, m_width);
	tempArray = Image2DMem(m_Re_height, m_Re_width);
	m_OutputImage = new unsigned char[m_Re_size];

	for (int i = 0; i < m_height; i++) {
		for (int j = 0; j < m_width; j++) {
			m_tempImage[i][j] = (double)m_InputImage[i * m_width + j];
		}
	}

	for (int i = 0; i < m_Re_height; i++) {
		for (int j = 0; j < m_Re_width; j++) {
			tempArray[i][j] = (double)m_tempImage[i/ZoomRate][j/ZoomRate];
		}
	}

	for (int i = 0; i < m_Re_height; i++) {
		for (int j = 0; j < m_Re_width; j++) {
			m_OutputImage[i * m_Re_width + j] = (unsigned char)tempArray[i][j];
		}
	}	
}


void CIMPAHJ200721practiceDoc::OnBilinear()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	int point, i_H, i_W;
	unsigned char newValue;
	double ZoomRate = 2.0, r_H, r_W, s_H, s_W;
	double C1, C2, C3, C4;

	m_Re_height = int(m_height * ZoomRate);
	m_Re_width = int(m_width * ZoomRate);
	m_Re_size = m_Re_height * m_Re_width;

	m_tempImage = Image2DMem(m_height, m_width);
	m_OutputImage = new unsigned char[m_Re_size];

	for (int i = 0; i < m_height; i++) {
		for (int j = 0; j < m_width; j++) {
			m_tempImage[i][j] = (double)m_InputImage[i * m_width + j];
		}
	}

	for (int i = 0; i < m_Re_height; i++) {
		for (int j = 0; j < m_Re_width; j++) {
			r_H = i / ZoomRate;
			r_W = j / ZoomRate;

			i_H = (int)floor(r_H);
			i_W = (int)floor(r_W);

			s_H = r_H - i_H;
			s_W = r_W - i_W;

			if (i_H < 0 || i_H >= (m_height - 1) || i_W < 0 || i_W >= (m_width - 1)) {
				point = i * m_Re_width + j;
				m_OutputImage[point] = 255;
			}
			else {
				C1 = (double)m_tempImage[i_H][i_W];
				C2 = (double)m_tempImage[i_H][i_W + 1];
				C3 = (double)m_tempImage[i_H + 1][i_W + 1];
				C4 = (double)m_tempImage[i_H + 1][i_W];
			}

			newValue = (unsigned char)(C1 * (1 - s_H) * (1 - s_W) + C2 * s_W * (1 - s_H) + C3 * s_W * s_H + C4 * (1 - s_W) * s_H);
			point = i * m_Re_width + j;
			m_OutputImage[point] = newValue;

		}
	}
}


void CIMPAHJ200721practiceDoc::OnMedianSub()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	int M = 2, index = 0;
	double* Mask, Value;
	Mask = new double[M * M];

	m_Re_height = (m_height + 1) /M;
	m_Re_width = (m_width + 1) / M;
	m_Re_size = m_Re_height * m_Re_width;

	m_tempImage = Image2DMem(m_height + 1, m_width + 1);
	m_OutputImage = new unsigned char[m_Re_size];

	for (int i = 0; i < m_height; i++) {
		for (int j = 0; j < m_width; j++) {
			m_tempImage[i][j] = (double)m_InputImage[i * m_width + j];
		}
	}

	for (int i = 0; i < m_height - 1; i= i+M) {
		for (int j = 0; j < m_width - 1; j= j+M) {
			for (int n = 0; n < M; n++) {
				for (int m = 0; m < M; m++) {
					Mask[n * M + m] = m_tempImage[i + n][j + m];
				}
			}

			OnBubleSort(Mask, M * M);
			Value = Mask[(int)(M * M / 2)];
			m_OutputImage[index] = (unsigned char)Value;
			index++;
		}
	}
}

void CIMPAHJ200721practiceDoc::OnBubleSort(double* A, int MAX) {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX - 1; j++) {
			if (A[j] > A[j + 1]) {
				OnSwap(&A[j], &A[j + 1]);
			}
		}
	}
}

void CIMPAHJ200721practiceDoc::OnSwap(double* a, double* b) {
	double temp;
	temp = *a;
	*a = *b;
	*b = temp;
}


void CIMPAHJ200721practiceDoc::OnMeanSub()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	int M = 3, index = 0, k;
	double* Mask, Value, Sum = 0.0;
	Mask = new double[M * M];

	m_Re_height = (m_height + 1) / M;
	m_Re_width = (m_width + 1) / M;
	m_Re_size = m_Re_height * m_Re_width;

	m_tempImage = Image2DMem(m_height + 1, m_width + 1);
	m_OutputImage = new unsigned char[m_Re_size];

	for (int i = 0; i < m_height; i++) {
		for (int j = 0; j < m_width; j++) {
			m_tempImage[i][j] = (double)m_InputImage[i * m_width + j];
		}
	}

	for (int i = 0; i < m_height - 1; i = i + M) {
		for (int j = 0; j < m_width - 1; j = j + M) {
			for (int n = 0; n < M; n++) {
				for (int m = 0; m < M; m++) {
					Mask[n * M + m] = m_tempImage[i + n][j + m];
				}
			}

			for (int k = 0; k < M * M; k++)
				Sum = Sum + Mask[k];

			Value = (Sum / (M*M));
			m_OutputImage[index] = (unsigned char)Value;
			index++;
			Sum = 0.0;
		}
	}
}


void CIMPAHJ200721practiceDoc::OnTranslation()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	int h_pos = 30, w_pos = 130;
	double** tempArray;
	
	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height * m_Re_width;

	m_tempImage = Image2DMem(m_height, m_width);
	tempArray = Image2DMem(m_Re_height, m_Re_width);
	m_OutputImage = new unsigned char[m_Re_size];

	for (int i = 0; i < m_height; i++) {
		for (int j = 0; j < m_width; j++) {
			m_tempImage[i][j] = (double)m_InputImage[i * m_width + j];
		}
	}
	for (int i = 0; i < m_height - h_pos; i++) {
		for (int j = 0; j < m_width - w_pos; j++) {
			tempArray[i + h_pos][j + w_pos] = m_tempImage[i][j];
		}
	}

	for (int i = 0; i < m_Re_height; i++) {
		for (int j = 0; j < m_Re_width; j++) {
			m_OutputImage[i * m_Re_width + j] = (unsigned char)tempArray[i][j];
		}
	}

	delete[] m_tempImage;
	delete[] tempArray;
}


void CIMPAHJ200721practiceDoc::OnMirrorHor()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height * m_Re_width;

	m_OutputImage = new unsigned char[m_Re_size];

	for (int i = 0; i < m_height; i++) {
		for (int j = 0; j < m_width; j++) {
			m_OutputImage[i*m_width + m_width - j - 1] = (double)m_InputImage[i * m_width + j];
		}
	}

}


void CIMPAHJ200721practiceDoc::OnMirrorVer()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height * m_Re_width;

	m_OutputImage = new unsigned char[m_Re_size];

	for (int i = 0; i < m_height; i++) {
		for (int j = 0; j < m_width; j++) {
			m_OutputImage[(m_height - i - 1) * m_width + j] = (double)m_InputImage[i * m_width + j];
		}
	}
}


void CIMPAHJ200721practiceDoc::OnRotation()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	int CenterH, CenterW, newH, newW, degree = 45;
	double Radian, PI, **tempArray, Value;
	m_Re_height = m_height;
	m_Re_width = m_width;
	m_Re_size = m_Re_height * m_Re_width;

	m_OutputImage = new unsigned char[m_Re_size];
	PI = 3.14159265358979;
	Radian = (double)degree * PI / 180.0;
	CenterH = m_height / 2;
	CenterW = m_width / 2;

	m_tempImage = Image2DMem(m_height, m_width);
	tempArray = Image2DMem(m_Re_height, m_Re_width);

	for (int i = 0; i < m_height; i++) {
		for (int j = 0; j < m_width; j++) {
			m_tempImage[i][j] = (double)m_InputImage[i * m_width + j];
		}
	}
	for (int i = 0; i < m_height; i++) {
		for (int j = 0; j < m_width; j++) {
			newH = (int)((i - CenterH) * cos(Radian) - (j - CenterW) * sin(Radian) + CenterH);
			newW = (int)((i - CenterH) * sin(Radian) + (j - CenterW) * sin(Radian) + CenterW);

			if (newH < 0 || newH >= m_height) {
				Value = 0;
			}
			else if (newW < 0 || newW >= m_width) {
				Value = 0;
			}
			else {
				Value = m_tempImage[newH][newW];
			}
			tempArray[i][j] = Value;
		}
	}

	for (int i = 0; i < m_height; i++) {
		for (int j = 0; j < m_width; j++) {
			m_OutputImage[i * m_width + j] = (unsigned char)tempArray[i][j];
		}
	}

	delete[] m_tempImage;
	delete[] tempArray;
}
