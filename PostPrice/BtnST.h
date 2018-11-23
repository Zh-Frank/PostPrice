
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
			};//定义枚举类型用来表示图标/位图和文字的对其方式

	enum	{	BTNST_COLOR_BK_IN	= 0,		// Background color when mouse is INside
				BTNST_COLOR_FG_IN,				// Text color when mouse is INside
				BTNST_COLOR_BK_OUT,				// Background color when mouse is OUTside
				BTNST_COLOR_FG_OUT,				// Text color when mouse is OUTside
				BTNST_COLOR_BK_FOCUS,			// Background color when the button is focused
				BTNST_COLOR_FG_FOCUS,			// Text color when the button is focused

				BTNST_MAX_COLORS
			};//表示各种状态下按钮的颜色

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
	DWORD SetDefaultColors(BOOL bRepaint = TRUE);//获取缺省颜色
	DWORD SetColor(BYTE byColorIndex, COLORREF crColor, BOOL bRepaint = TRUE);//设置按钮颜色
	DWORD GetColor(BYTE byColorIndex, COLORREF* crpColor);//获取按钮颜色
	DWORD OffsetColor(BYTE byColorIndex, short shOffset, BOOL bRepaint = TRUE);//设置按钮颜色灰度（-255到255）

	DWORD SetCheck(int nCheck, BOOL bRepaint = TRUE);//设置选择框按钮的选中1/未选中0状态
	int GetCheck();		//获取选择框状态

	DWORD SetURL(LPCTSTR lpszURL = NULL);//设置按钮单击时打开的URL
	void DrawTransparent(BOOL bRepaint = FALSE);//重绘为透明模式

	BOOL GetDefault();//判断按钮是否为缺省按钮
	DWORD SetAlwaysTrack(BOOL bAlwaysTrack = TRUE);

	void SetTooltipText(int nText, BOOL bActivate = TRUE);//设置按钮要显示的提示信息文本
	void SetTooltipText(LPCTSTR lpszText, BOOL bActivate = TRUE);
	void ActivateTooltip(BOOL bEnable = TRUE);//显示或关闭提示信息

	DWORD SetBtnCursor(int nCursorId = NULL, BOOL bRepaint = TRUE);//设置鼠标在按钮上时的光标图案

	DWORD SetFlat(BOOL bFlat = TRUE, BOOL bRepaint = TRUE);//设置按钮是否为flat模式
	DWORD SetAlign(BYTE byAlign, BOOL bRepaint = TRUE);//设置按钮上图标/位图与文字的对其方式

	DWORD DrawBorder(BOOL bDrawBorder = TRUE, BOOL bRepaint = TRUE);//重绘边框
	DWORD DrawFlatFocus(BOOL bDrawFlatFocus, BOOL bRepaint = TRUE);//重绘焦点框

	DWORD SetIcon(int nIconIn, int nIconOut = NULL);//设置按上显示的钮图标
	DWORD SetIcon(HICON hIconIn, HICON hIconOut = NULL);
	//设置按钮上显示的位图
	DWORD SetBitmaps(int nBitmapIn, COLORREF crTransColorIn, int nBitmapOut = NULL, COLORREF crTransColorOut = 0);
	DWORD SetBitmaps(HBITMAP hBitmapIn, COLORREF crTransColorIn, HBITMAP hBitmapOut = NULL, COLORREF crTransColorOut = 0);

	DWORD SetMenu(UINT nMenu, HWND hParentWnd, BOOL bRepaint = TRUE);//设置按钮菜单

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

	BOOL		m_bIsFlat;			// 是否为平面按钮
	BOOL		m_bMouseOnButton;	// 鼠标是否在按钮上
	BOOL		m_bDrawTransparent;	// 是否设置为透明模式
	BOOL		m_bIsPressed;		// 按钮是否按下
	BOOL		m_bIsFocused;		// 按钮是否输入焦点
	BOOL		m_bIsDisabled;		// 按钮是否可见
	BOOL		m_bIsDefault;		// 是否缺省按钮
	BOOL		m_bIsCheckBox;		// 是否为选择框按钮
	BYTE		m_byAlign;			// 对齐模式
	BOOL		m_bDrawBorder;		// 是否重绘边框
	BOOL		m_bDrawFlatFocus;	// 是否重绘平面按钮的焦点框
	COLORREF	m_crColors[BTNST_MAX_COLORS];	// 颜色数组
	HWND		m_hParentWndMenu;	// 拥有按钮菜单的窗口句柄
	BOOL		m_bMenuDisplayed;	// 按钮菜单是否显示

	HMENU		m_hMenu;			// 为按钮添加的菜单的句柄

private://消息响应函数
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

	void InitToolTip();//创建提示信息控件函数

	HCURSOR		m_hCursor;			// 光标句柄
	CToolTipCtrl m_ToolTip;			// 提示信息控件对象

	CDC			m_dcBk;
	CBitmap		m_bmpBk;
	CBitmap*	m_pbmpOldBk;

	BOOL		m_bAlwaysTrack;		// Always hilight button?
	int			m_nCheck;			// 选择框按钮关联的当前值
	UINT		m_nTypeStyle;		// Button style

	TCHAR		m_szURL[_MAX_PATH];	// 字符型数组，存放一个URL地址，用在SetURL函数中

#pragma pack(1)
	typedef struct _STRUCT_ICONS	//存放图标信息的结构体
	{
		HICON		hIcon;			// Handle to icon
		DWORD		dwWidth;		// Width of icon
		DWORD		dwHeight;		// Height of icon
	} STRUCT_ICONS;
#pragma pack()

#pragma pack(1)
	typedef struct _STRUCT_BITMAPS	//存放位图信息的结构体
	{
		HBITMAP		hBitmap;		// Handle to bitmap
		DWORD		dwWidth;		// Width of bitmap
		DWORD		dwHeight;		// Height of bitmap
		HBITMAP		hMask;			// Handle to mask bitmap
		COLORREF	crTransparent;	// Transparent color
	} STRUCT_BITMAPS;
#pragma pack()

	STRUCT_ICONS	m_csIcons[2];	//图标结构体数组
	STRUCT_BITMAPS	m_csBitmaps[2];	//位图结构体数组

	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnPaint();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif
