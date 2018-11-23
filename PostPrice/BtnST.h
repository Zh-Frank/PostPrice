
#ifndef _BTNST_H
#define _BTNST_H


#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

// Return values
#ifndef	BTNST_OK
#define	BTNST_OK						0
#endif
#ifndef	BTNST_INVALIDRESOURCE
#define	BTNST_INVALIDRESOURCE			1
#endif
#ifndef	BTNST_FAILEDMASK
#define	BTNST_FAILEDMASK				2
#endif
#ifndef	BTNST_INVALIDINDEX
#define	BTNST_INVALIDINDEX				3
#endif
#ifndef	BTNST_INVALIDALIGN
#define	BTNST_INVALIDALIGN				4
#endif
#ifndef	BTNST_BADPARAM
#define	BTNST_BADPARAM					5
#endif

// Dummy identifier for grayscale icon
#ifndef	BTNST_AUTO_GRAY
#define	BTNST_AUTO_GRAY					(HICON)(0xffffffff - 1L)
#endif

class CButtonST : public CButton
{
public:
    CButtonST();
	~CButtonST();

    enum	{	ST_ALIGN_HORIZ	= 0,			// Icon/bitmap on the left, text on the right
				ST_ALIGN_VERT,					// Icon/bitmap on the top, text on the bottom
				ST_ALIGN_HORIZ_RIGHT			// Icon/bitmap on the right, text on the left
			};//����ö������������ʾͼ��/λͼ�����ֵĶ��䷽ʽ

	enum	{	BTNST_COLOR_BK_IN	= 0,		// Background color when mouse is INside
				BTNST_COLOR_FG_IN,				// Text color when mouse is INside
				BTNST_COLOR_BK_OUT,				// Background color when mouse is OUTside
				BTNST_COLOR_FG_OUT,				// Text color when mouse is OUTside
				BTNST_COLOR_BK_FOCUS,			// Background color when the button is focused
				BTNST_COLOR_FG_FOCUS,			// Text color when the button is focused

				BTNST_MAX_COLORS
			};//��ʾ����״̬�°�ť����ɫ

	// ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CButtonST)
	public:
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void PreSubclassWindow();
	virtual LRESULT DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

public:
	DWORD SetDefaultColors(BOOL bRepaint = TRUE);//��ȡȱʡ��ɫ
	DWORD SetColor(BYTE byColorIndex, COLORREF crColor, BOOL bRepaint = TRUE);//���ð�ť��ɫ
	DWORD GetColor(BYTE byColorIndex, COLORREF* crpColor);//��ȡ��ť��ɫ
	DWORD OffsetColor(BYTE byColorIndex, short shOffset, BOOL bRepaint = TRUE);//���ð�ť��ɫ�Ҷȣ�-255��255��

	DWORD SetCheck(int nCheck, BOOL bRepaint = TRUE);//����ѡ���ť��ѡ��1/δѡ��0״̬
	int GetCheck();		//��ȡѡ���״̬

	DWORD SetURL(LPCTSTR lpszURL = NULL);//���ð�ť����ʱ�򿪵�URL
	void DrawTransparent(BOOL bRepaint = FALSE);//�ػ�Ϊ͸��ģʽ

	BOOL GetDefault();//�жϰ�ť�Ƿ�Ϊȱʡ��ť
	DWORD SetAlwaysTrack(BOOL bAlwaysTrack = TRUE);

	void SetTooltipText(int nText, BOOL bActivate = TRUE);//���ð�ťҪ��ʾ����ʾ��Ϣ�ı�
	void SetTooltipText(LPCTSTR lpszText, BOOL bActivate = TRUE);
	void ActivateTooltip(BOOL bEnable = TRUE);//��ʾ��ر���ʾ��Ϣ

	DWORD SetBtnCursor(int nCursorId = NULL, BOOL bRepaint = TRUE);//��������ڰ�ť��ʱ�Ĺ��ͼ��

	DWORD SetFlat(BOOL bFlat = TRUE, BOOL bRepaint = TRUE);//���ð�ť�Ƿ�Ϊflatģʽ
	DWORD SetAlign(BYTE byAlign, BOOL bRepaint = TRUE);//���ð�ť��ͼ��/λͼ�����ֵĶ��䷽ʽ

	DWORD DrawBorder(BOOL bDrawBorder = TRUE, BOOL bRepaint = TRUE);//�ػ�߿�
	DWORD DrawFlatFocus(BOOL bDrawFlatFocus, BOOL bRepaint = TRUE);//�ػ潹���

	DWORD SetIcon(int nIconIn, int nIconOut = NULL);//���ð�����ʾ��ťͼ��
	DWORD SetIcon(HICON hIconIn, HICON hIconOut = NULL);
	//���ð�ť����ʾ��λͼ
	DWORD SetBitmaps(int nBitmapIn, COLORREF crTransColorIn, int nBitmapOut = NULL, COLORREF crTransColorOut = 0);
	DWORD SetBitmaps(HBITMAP hBitmapIn, COLORREF crTransColorIn, HBITMAP hBitmapOut = NULL, COLORREF crTransColorOut = 0);

	DWORD SetMenu(UINT nMenu, HWND hParentWnd, BOOL bRepaint = TRUE);//���ð�ť�˵�

	static short GetVersionI()		{return 35;}
	static LPCTSTR GetVersionC()	{return (LPCTSTR)_T("3.5");}

	BOOL	m_bShowDisabledBitmap;

protected:
    //{{AFX_MSG(CButtonST)
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnSysColorChange();
	afx_msg BOOL OnClicked();
	afx_msg void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
	afx_msg void OnEnable(BOOL bEnable);
	afx_msg void OnCancelMode();
	afx_msg UINT OnGetDlgCode();
	//}}AFX_MSG


	afx_msg HBRUSH CtlColor(CDC* pDC, UINT nCtlColor);
	HICON CreateGrayscaleIcon(HICON hIcon);
	virtual DWORD OnDrawBackground(CDC* pDC, LPCRECT pRect);
	virtual DWORD OnDrawBorder(CDC* pDC, LPCRECT pRect);

	BOOL		m_bIsFlat;			// �Ƿ�Ϊƽ�水ť
	BOOL		m_bMouseOnButton;	// ����Ƿ��ڰ�ť��
	BOOL		m_bDrawTransparent;	// �Ƿ�����Ϊ͸��ģʽ
	BOOL		m_bIsPressed;		// ��ť�Ƿ���
	BOOL		m_bIsFocused;		// ��ť�Ƿ����뽹��
	BOOL		m_bIsDisabled;		// ��ť�Ƿ�ɼ�
	BOOL		m_bIsDefault;		// �Ƿ�ȱʡ��ť
	BOOL		m_bIsCheckBox;		// �Ƿ�Ϊѡ���ť
	BYTE		m_byAlign;			// ����ģʽ
	BOOL		m_bDrawBorder;		// �Ƿ��ػ�߿�
	BOOL		m_bDrawFlatFocus;	// �Ƿ��ػ�ƽ�水ť�Ľ����
	COLORREF	m_crColors[BTNST_MAX_COLORS];	// ��ɫ����
	HWND		m_hParentWndMenu;	// ӵ�а�ť�˵��Ĵ��ھ��
	BOOL		m_bMenuDisplayed;	// ��ť�˵��Ƿ���ʾ

	HMENU		m_hMenu;			// Ϊ��ť��ӵĲ˵��ľ��

private://��Ϣ��Ӧ����
	LRESULT OnSetCheck(WPARAM wParam, LPARAM lParam);
	LRESULT OnGetCheck(WPARAM wParam, LPARAM lParam);
	LRESULT OnSetStyle(WPARAM wParam, LPARAM lParam);
	LRESULT OnMouseLeave(WPARAM wParam, LPARAM lParam);

	void CancelHover();
	void FreeResources(BOOL bCheckForNULL = TRUE);
	void PrepareImageRect(BOOL bHasTitle, RECT* rpItem, CRect* rpTitle, BOOL bIsPressed, DWORD dwWidth, DWORD dwHeight, CRect* rpImage);
	HBITMAP CreateBitmapMask(HBITMAP hSourceBitmap, DWORD dwWidth, DWORD dwHeight, COLORREF crTransColor);
	void DrawTheIcon(CDC* pDC, BOOL bHasTitle, RECT* rpItem, CRect* rpTitle, BOOL bIsPressed, BOOL bIsDisabled);
	void DrawTheBitmap(CDC* pDC, BOOL bHasTitle, RECT *rItem, CRect *rCaption, BOOL bIsPressed, BOOL bIsDisabled);
	void PaintBk(CDC* pDC);

	void InitToolTip();//������ʾ��Ϣ�ؼ�����

	HCURSOR		m_hCursor;			// �����
	CToolTipCtrl m_ToolTip;			// ��ʾ��Ϣ�ؼ�����

	CDC			m_dcBk;
	CBitmap		m_bmpBk;
	CBitmap*	m_pbmpOldBk;

	BOOL		m_bAlwaysTrack;		// Always hilight button?
	int			m_nCheck;			// ѡ���ť�����ĵ�ǰֵ
	UINT		m_nTypeStyle;		// Button style

	TCHAR		m_szURL[_MAX_PATH];	// �ַ������飬���һ��URL��ַ������SetURL������

#pragma pack(1)
	typedef struct _STRUCT_ICONS	//���ͼ����Ϣ�Ľṹ��
	{
		HICON		hIcon;			// Handle to icon
		DWORD		dwWidth;		// Width of icon
		DWORD		dwHeight;		// Height of icon
	} STRUCT_ICONS;
#pragma pack()

#pragma pack(1)
	typedef struct _STRUCT_BITMAPS	//���λͼ��Ϣ�Ľṹ��
	{
		HBITMAP		hBitmap;		// Handle to bitmap
		DWORD		dwWidth;		// Width of bitmap
		DWORD		dwHeight;		// Height of bitmap
		HBITMAP		hMask;			// Handle to mask bitmap
		COLORREF	crTransparent;	// Transparent color
	} STRUCT_BITMAPS;
#pragma pack()

	STRUCT_ICONS	m_csIcons[2];	//ͼ��ṹ������
	STRUCT_BITMAPS	m_csBitmaps[2];	//λͼ�ṹ������

	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnPaint();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif
