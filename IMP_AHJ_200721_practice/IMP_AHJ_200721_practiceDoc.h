
// IMP_AHJ_200721_practiceDoc.h: CIMPAHJ200721practiceDoc 클래스의 인터페이스
//


#pragma once


class CIMPAHJ200721practiceDoc : public CDocument
{
protected: // serialization에서만 만들어집니다.
	CIMPAHJ200721practiceDoc() noexcept;
	DECLARE_DYNCREATE(CIMPAHJ200721practiceDoc)

// 특성입니다.
public:
	int m_width;
	int m_height;
	int m_size;

	int m_Re_width;
	int m_Re_height;
	int m_Re_size;

	unsigned char** m_2DImage;
	unsigned char* m_OutputImage;
	unsigned char* m_InputImage;

	double** m_tempImage;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 구현입니다.
public:
	virtual ~CIMPAHJ200721practiceDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 검색 처리기에 대한 검색 콘텐츠를 설정하는 도우미 함수
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
	void OnDownSampling();
	void OnUpSampling();
	void OnQuantization();
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

	double** OnMaskProcess(unsigned char*, double[][3]);
	double** OnScale(double**, int, int);
	double** Image2DMem(int, int);
	double DoubleABS(double);
	void OnBubleSort(double*, int);
	void OnSwap(double*, double*);
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
