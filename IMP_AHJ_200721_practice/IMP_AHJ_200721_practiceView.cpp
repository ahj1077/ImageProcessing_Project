
// IMP_AHJ_200721_practiceView.cpp: CIMPAHJ200721practiceView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "IMP_AHJ_200721_practice.h"
#endif

#include "IMP_AHJ_200721_practiceDoc.h"
#include "IMP_AHJ_200721_practiceView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CIMPAHJ200721practiceView

IMPLEMENT_DYNCREATE(CIMPAHJ200721practiceView, CView)

BEGIN_MESSAGE_MAP(CIMPAHJ200721practiceView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CIMPAHJ200721practiceView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_DOWN_SAMPLING, &CIMPAHJ200721practiceView::OnDownSampling)
	ON_COMMAND(ID_UP_SAMPLING, &CIMPAHJ200721practiceView::OnUpSampling)
	ON_COMMAND(ID_Quantization, &CIMPAHJ200721practiceView::OnQuantization)
	ON_COMMAND(ID_IMAGEPROCESSING_ADD, &CIMPAHJ200721practiceView::OnImageprocessingAdd)
	ON_COMMAND(ID_IMAGEPROCESSING_SUB, &CIMPAHJ200721practiceView::OnImageprocessingSub)
	ON_COMMAND(ID_IMAGEPROCESSING_MUL, &CIMPAHJ200721practiceView::OnImageprocessingMul)
	ON_COMMAND(ID_IMAGEPROCESSING_DIV, &CIMPAHJ200721practiceView::OnImageprocessingDiv)
	ON_COMMAND(ID_LOGICAL_AND, &CIMPAHJ200721practiceView::OnLogicalAnd)
	ON_COMMAND(ID_LOGICAL_OR, &CIMPAHJ200721practiceView::OnLogicalOr)
	ON_COMMAND(ID_LOGICAL_XOR, &CIMPAHJ200721practiceView::OnLogicalXor)
	ON_COMMAND(ID_LOGICAL_NOT, &CIMPAHJ200721practiceView::OnLogicalNot)
	ON_COMMAND(ID_NEGA_TRANSFORM, &CIMPAHJ200721practiceView::OnNegaTransform)
	ON_COMMAND(ID_GAMMA_CORRECTION, &CIMPAHJ200721practiceView::OnGammaCorrection)
	ON_COMMAND(ID_BINARIZATION, &CIMPAHJ200721practiceView::OnBinarization)
	ON_COMMAND(ID_STRESS_TRANSFORM, &CIMPAHJ200721practiceView::OnStressTransform)
	ON_COMMAND(ID_HISTO_STRETCH, &CIMPAHJ200721practiceView::OnHistoStretch)
	ON_COMMAND(ID_HISTOGRAM, &CIMPAHJ200721practiceView::OnHistogram)
	ON_COMMAND(ID_HISTO_EQUAL, &CIMPAHJ200721practiceView::OnHistoEqual)
	ON_COMMAND(ID_HISTO_SPEC, &CIMPAHJ200721practiceView::OnHistoSpec)
	ON_COMMAND(ID_EMBOSSING, &CIMPAHJ200721practiceView::OnEmbossing)
	ON_COMMAND(ID_BLURR, &CIMPAHJ200721practiceView::OnBlurr)
	ON_COMMAND(ID_GAUSSIAN_FILTER, &CIMPAHJ200721practiceView::OnGaussianFilter)
	ON_COMMAND(ID_SHARPENING, &CIMPAHJ200721practiceView::OnSharpening)
	ON_COMMAND(ID_HPF_SHARP, &CIMPAHJ200721practiceView::OnHpfSharp)
	ON_COMMAND(ID_LPF_SHARP, &CIMPAHJ200721practiceView::OnLpfSharp)
	ON_COMMAND(ID_DIFF_OPERATOR_HOR, &CIMPAHJ200721practiceView::OnDiffOperatorHor)
	ON_COMMAND(ID_HOMOGEN_OPERATOR, &CIMPAHJ200721practiceView::OnHomogenOperator)
	ON_COMMAND(ID_LAPLACIAN, &CIMPAHJ200721practiceView::OnLaplacian)
	ON_COMMAND(ID_NEAREST, &CIMPAHJ200721practiceView::OnNearest)
	ON_COMMAND(ID_BILINEAR, &CIMPAHJ200721practiceView::OnBilinear)
	ON_COMMAND(ID_MEDIAN_SUB, &CIMPAHJ200721practiceView::OnMedianSub)
	ON_COMMAND(ID_MEAN_SUB, &CIMPAHJ200721practiceView::OnMeanSub)
	ON_COMMAND(ID_TRANSLATION, &CIMPAHJ200721practiceView::OnTranslation)
	ON_COMMAND(ID_MIRROR_HOR, &CIMPAHJ200721practiceView::OnMirrorHor)
	ON_COMMAND(ID_MIRROR_VER, &CIMPAHJ200721practiceView::OnMirrorVer)
	ON_COMMAND(ID_ROTATION, &CIMPAHJ200721practiceView::OnRotation)
END_MESSAGE_MAP()

// CIMPAHJ200721practiceView 생성/소멸

CIMPAHJ200721practiceView::CIMPAHJ200721practiceView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CIMPAHJ200721practiceView::~CIMPAHJ200721practiceView()
{
}

BOOL CIMPAHJ200721practiceView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CIMPAHJ200721practiceView 그리기

void CIMPAHJ200721practiceView::OnDraw(CDC* pDC)
{
	CIMPAHJ200721practiceDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.

	
	unsigned char R, G, B;

	for (int i = 0; i < pDoc->m_height; i++) {
		for (int j = 0; j < pDoc->m_width; j++) {
			R = pDoc->m_InputImage[i * pDoc->m_width + j];
			G = B = R;
			pDC->SetPixel(j+ 5, i + 5, RGB(R, G, B));
		}
	}

	for (int i = 0; i < pDoc->m_Re_height; i++) {
		for (int j = 0; j < pDoc->m_Re_width; j++) {
			R = pDoc->m_OutputImage[i * pDoc->m_Re_width + j];
			G = B = R;
			pDC->SetPixel(j + pDoc->m_width + 10, i + 5, RGB(R, G, B));
		}
	}
}





// CIMPAHJ200721practiceView 인쇄


void CIMPAHJ200721practiceView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CIMPAHJ200721practiceView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CIMPAHJ200721practiceView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CIMPAHJ200721practiceView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CIMPAHJ200721practiceView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CIMPAHJ200721practiceView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CIMPAHJ200721practiceView 진단

#ifdef _DEBUG
void CIMPAHJ200721practiceView::AssertValid() const
{
	CView::AssertValid();
}

void CIMPAHJ200721practiceView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CIMPAHJ200721practiceDoc* CIMPAHJ200721practiceView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CIMPAHJ200721practiceDoc)));
	return (CIMPAHJ200721practiceDoc*)m_pDocument;
}
#endif //_DEBUG


// CIMPAHJ200721practiceView 메시지 처리기


void CIMPAHJ200721practiceView::OnDownSampling()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMPAHJ200721practiceDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnDownSampling();
	Invalidate(TRUE);
}


void CIMPAHJ200721practiceView::OnUpSampling()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.

	CIMPAHJ200721practiceDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnUpSampling();
	Invalidate(TRUE);
}


void CIMPAHJ200721practiceView::OnQuantization()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMPAHJ200721practiceDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnQuantization();
	Invalidate(TRUE);
}


void CIMPAHJ200721practiceView::OnImageprocessingAdd()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMPAHJ200721practiceDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnImageprocessingAdd();
	Invalidate(TRUE);
}


void CIMPAHJ200721practiceView::OnImageprocessingSub()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMPAHJ200721practiceDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnImageprocessingSub();
	Invalidate(TRUE);
}


void CIMPAHJ200721practiceView::OnImageprocessingMul()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMPAHJ200721practiceDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnImageprocessingMul();
	Invalidate(TRUE);
}


void CIMPAHJ200721practiceView::OnImageprocessingDiv()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMPAHJ200721practiceDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnImageprocessingDiv();
	Invalidate(TRUE);
}


void CIMPAHJ200721practiceView::OnLogicalAnd()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMPAHJ200721practiceDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnLogicalAnd();
	Invalidate(TRUE);
}


void CIMPAHJ200721practiceView::OnLogicalOr()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMPAHJ200721practiceDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnLogicalOr();
	Invalidate(TRUE);
}


void CIMPAHJ200721practiceView::OnLogicalXor()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMPAHJ200721practiceDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnLogicalXor();
	Invalidate(TRUE);
}


void CIMPAHJ200721practiceView::OnLogicalNot()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMPAHJ200721practiceDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnLogicalNot();
	Invalidate(TRUE);
}


void CIMPAHJ200721practiceView::OnNegaTransform()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMPAHJ200721practiceDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnNegaTransform();
	Invalidate(TRUE);
}


void CIMPAHJ200721practiceView::OnGammaCorrection()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMPAHJ200721practiceDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnGammaCorrection();
	Invalidate(TRUE);
}


void CIMPAHJ200721practiceView::OnBinarization()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMPAHJ200721practiceDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnBinarization();
	Invalidate(TRUE);
}


void CIMPAHJ200721practiceView::OnStressTransform()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMPAHJ200721practiceDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnStressTransform();
	Invalidate(TRUE);
}


void CIMPAHJ200721practiceView::OnHistoStretch()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMPAHJ200721practiceDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnHistoStretch();
	Invalidate(TRUE);
}


void CIMPAHJ200721practiceView::OnHistogram()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMPAHJ200721practiceDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnHistogram();
	Invalidate(TRUE);
}


void CIMPAHJ200721practiceView::OnHistoEqual()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMPAHJ200721practiceDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnHistoEqual();
	Invalidate(TRUE);
}


void CIMPAHJ200721practiceView::OnHistoSpec()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMPAHJ200721practiceDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnHistoSpec();
	Invalidate(TRUE);
}


void CIMPAHJ200721practiceView::OnEmbossing()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMPAHJ200721practiceDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnEmbossing();
	Invalidate(TRUE);
}


void CIMPAHJ200721practiceView::OnBlurr()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMPAHJ200721practiceDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnBlurr();
	Invalidate(TRUE);
}


void CIMPAHJ200721practiceView::OnGaussianFilter()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMPAHJ200721practiceDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnGaussianFilter();
	Invalidate(TRUE);
}


void CIMPAHJ200721practiceView::OnSharpening()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMPAHJ200721practiceDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnSharpening();
	Invalidate(TRUE);
}


void CIMPAHJ200721practiceView::OnHpfSharp()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMPAHJ200721practiceDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnHpfSharp();
	Invalidate(TRUE);
}


void CIMPAHJ200721practiceView::OnLpfSharp()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMPAHJ200721practiceDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnLpfSharp();
	Invalidate(TRUE);
}


void CIMPAHJ200721practiceView::OnDiffOperatorHor()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMPAHJ200721practiceDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnDiffOperatorHor();
	Invalidate(TRUE);
}


void CIMPAHJ200721practiceView::OnHomogenOperator()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMPAHJ200721practiceDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnHomogenOperator();
	Invalidate(TRUE);
}


void CIMPAHJ200721practiceView::OnLaplacian()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMPAHJ200721practiceDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnLaplacian();
	Invalidate(TRUE);
}


void CIMPAHJ200721practiceView::OnNearest()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMPAHJ200721practiceDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnNearest();
	Invalidate(TRUE);
}


void CIMPAHJ200721practiceView::OnBilinear()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMPAHJ200721practiceDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnBilinear();
	Invalidate(TRUE);
}


void CIMPAHJ200721practiceView::OnMedianSub()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMPAHJ200721practiceDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnMedianSub();
	Invalidate(TRUE);
}


void CIMPAHJ200721practiceView::OnMeanSub()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMPAHJ200721practiceDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnMeanSub();
	Invalidate(TRUE);
}


void CIMPAHJ200721practiceView::OnTranslation()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMPAHJ200721practiceDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnTranslation();
	Invalidate(TRUE);
}


void CIMPAHJ200721practiceView::OnMirrorHor()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMPAHJ200721practiceDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnMirrorHor();
	Invalidate(TRUE);
}


void CIMPAHJ200721practiceView::OnMirrorVer()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMPAHJ200721practiceDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnMirrorVer();
	Invalidate(TRUE);
}


void CIMPAHJ200721practiceView::OnRotation()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIMPAHJ200721practiceDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnRotation();
	Invalidate(TRUE);
}
