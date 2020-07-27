
// IMP_AHJ_200721_practiceView.h: CIMPAHJ200721practiceView 클래스의 인터페이스
//

#pragma once


class CIMPAHJ200721practiceView : public CView
{
protected: // serialization에서만 만들어집니다.
	CIMPAHJ200721practiceView() noexcept;
	DECLARE_DYNCREATE(CIMPAHJ200721practiceView)

// 특성입니다.
public:
	CIMPAHJ200721practiceDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CIMPAHJ200721practiceView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDownSampling();
	afx_msg void OnUpSampling();
	afx_msg void OnQuantization();
	afx_msg void OnImageprocessingAdd();
	afx_msg void OnImageprocessingSub();
	afx_msg void OnImageprocessingMul();
	afx_msg void OnImageprocessingDiv();
	afx_msg void OnLogicalAnd();
	afx_msg void OnLogicalOr();
	afx_msg void OnLogicalXor();
	afx_msg void OnLogicalNot();
	afx_msg void OnNegaTransform();
	afx_msg void OnGammaCorrection();
	afx_msg void OnBinarization();
	afx_msg void OnStressTransform();
	afx_msg void OnHistoStretch();
	afx_msg void OnHistogram();
	afx_msg void OnHistoEqual();
	afx_msg void OnHistoSpec();
	afx_msg void OnEmbossing();
	afx_msg void OnBlurr();
	afx_msg void OnGaussianFilter();
	afx_msg void OnSharpening();
	afx_msg void OnHpfSharp();
	afx_msg void OnLpfSharp();
	afx_msg void OnDiffOperatorHor();
	afx_msg void OnHomogenOperator();
	afx_msg void OnLaplacian();
	afx_msg void OnNearest();
	afx_msg void OnBilinear();
	afx_msg void OnMedianSub();
	afx_msg void OnMeanSub();
	afx_msg void OnTranslation();
	afx_msg void OnMirrorHor();
	afx_msg void OnMirrorVer();
	afx_msg void OnRotation();
};

#ifndef _DEBUG  // IMP_AHJ_200721_practiceView.cpp의 디버그 버전
inline CIMPAHJ200721practiceDoc* CIMPAHJ200721practiceView::GetDocument() const
   { return reinterpret_cast<CIMPAHJ200721practiceDoc*>(m_pDocument); }
#endif

