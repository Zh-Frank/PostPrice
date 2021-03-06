
// PostPriceDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "PostPrice.h"
#include "PostPriceDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include <fstream>
using namespace std;

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CPostPriceDlg 对话框

void CPostPriceDlg::ReadFile()
{
	for (int i = 0; i != 15; ++i)
		memset(add[i], 0, 100);
	for (int i = 0; i != 15; ++i)
		a[i][0] = a[i][1] = 0;
	ifstream inFile("price.ini", ios::in);
	if (!inFile.is_open())
		AfxMessageBox(_T("请先设置各地区邮寄价格"));
	int i = 0;
	for (i = 0; i != 15; ++i)
	{
		if (!inFile)
			break;
		inFile >> add[i] >> a[i][0] >> a[i][1];
	}
	
	inFile.close();
}
void CPostPriceDlg::SetRadioName()
{
	for (int i = 0; i != 15; ++i)
	{
		CString s(add[i]);
		SetDlgItemText(IDR_ADDRESS + i, s);
	}
}
CPostPriceDlg::CPostPriceDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_POSTPRICE_DIALOG, pParent)
	, m_price_thired(0)
	, m_kg(0)
	, m_address(-1)
	, m_first(0)
	, m_second(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	ReadFile();
}

void CPostPriceDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDE_THIRED, m_price_thired);
	DDX_Text(pDX, IDE_KG, m_kg);
	DDX_Radio(pDX, IDR_ADDRESS, m_address);
	DDX_Text(pDX, IDE_FIRST, m_first);
	DDX_Text(pDX, IDE_SECOND, m_second);
	DDX_Control(pDX, IDB_CHANGE, m_Change);
	DDX_Control(pDX, IDB_JS, m_JSbtn);
}

BEGIN_MESSAGE_MAP(CPostPriceDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDB_JS, &CPostPriceDlg::OnBnClickedJs)

ON_BN_CLICKED(IDR_ADDRESS, &CPostPriceDlg::OnBnClickedAddress)
ON_BN_CLICKED(IDC_RADIO2, &CPostPriceDlg::OnBnClickedAddress)
ON_BN_CLICKED(IDC_RADIO3, &CPostPriceDlg::OnBnClickedAddress)
ON_BN_CLICKED(IDC_RADIO4, &CPostPriceDlg::OnBnClickedAddress)
ON_BN_CLICKED(IDC_RADIO5, &CPostPriceDlg::OnBnClickedAddress)
ON_BN_CLICKED(IDC_RADIO6, &CPostPriceDlg::OnBnClickedAddress)
ON_BN_CLICKED(IDC_RADIO7, &CPostPriceDlg::OnBnClickedAddress)
ON_BN_CLICKED(IDC_RADIO8, &CPostPriceDlg::OnBnClickedAddress)
ON_BN_CLICKED(IDC_RADIO9, &CPostPriceDlg::OnBnClickedAddress)
ON_BN_CLICKED(IDC_RADIO10, &CPostPriceDlg::OnBnClickedAddress)
ON_BN_CLICKED(IDC_RADIO11, &CPostPriceDlg::OnBnClickedAddress)
ON_BN_CLICKED(IDC_RADIO12, &CPostPriceDlg::OnBnClickedAddress)
ON_BN_CLICKED(IDC_RADIO13, &CPostPriceDlg::OnBnClickedAddress)
ON_BN_CLICKED(IDC_RADIO14, &CPostPriceDlg::OnBnClickedAddress)
ON_BN_CLICKED(IDC_RADIO15, &CPostPriceDlg::OnBnClickedAddress)
ON_BN_CLICKED(IDB_CHANGE, &CPostPriceDlg::OnBnClickedChange)
END_MESSAGE_MAP()


// CPostPriceDlg 消息处理程序

BOOL CPostPriceDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	SetRadioName();
	m_Change.SetIcon(IDI_SETBTN);
	m_Change.SetAlign(1);
	m_JSbtn.SetIcon(IDI_JSBTN);
	m_JSbtn.SetTooltipText(_T("计算总价格"));
	
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CPostPriceDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CPostPriceDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CPostPriceDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CPostPriceDlg::OnBnClickedJs()
{
	// TODO: 在此添加控件通知处理程序代码

	UpdateData(TRUE);
	if (-1 == m_address )
	{
		AfxMessageBox(_T("请选择邮寄目的地"));
		return;
	}
	CString address_str;
	GetDlgItemText(IDR_ADDRESS + m_address, address_str);
	if (address_str.IsEmpty())
	{
		AfxMessageBox(_T("请选择邮寄目的地"));
		return;
	}
	if (0 == m_kg)
	{
		AfxMessageBox(_T("请输入货物重量"));
		return;
	}
	CString str;
	CString tmp(add[m_address]);
	str.Format(_T("运送目的地为: %s\n运费标准: %d + %d\n附加费用: %.1f 元/kg\n"
					"货物重量为: %d KG"), tmp, m_first, m_second, m_price_thired, m_kg);
	if (IDNO == MessageBox(str, _T("请确认信息"), MB_YESNO))
	{
		return ;
	}
	
	CRect cRt;
	GetDlgItem(IDB_CHANGE)->GetWindowRect(&cRt); //获得window区域
	ScreenToClient(&cRt); //转到client
	double price = m_first + (m_kg > 1 ? m_kg - 1 : 0) * m_second + m_kg * m_price_thired;
	str.Format(_T("￥ : %.2f"), price);
	CDC *pdc = GetDC();
	CFont f;
	f.CreateFontW(cRt.Height(), 50, 0, 0, 200, 0, 0, 0, 0, 0, 0, 0, 0, _T("a"));
	CFont *old = pdc->SelectObject(&f);
	pdc->SetTextColor(RGB(255, 0, 0));
	pdc->TextOut(cRt.right + 20, cRt.top , str);
	ReleaseDC(pdc);
}



void CPostPriceDlg::OnBnClickedAddress()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_first = a[m_address][0];
	m_second = a[m_address][1];
	UpdateData(FALSE);
}

void CPostPriceDlg::OnBnClickedChange()
{
	// TODO: 在此添加控件通知处理程序代码
	CSetPost dlg;
	if (IDOK == dlg.DoModal())
	{
		ReadFile();
		SetRadioName();
	}
}
