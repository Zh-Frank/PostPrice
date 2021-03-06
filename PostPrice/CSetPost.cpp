// CSetPost.cpp: 实现文件
//

#include "stdafx.h"
#include "PostPrice.h"
#include "CSetPost.h"
#include "afxdialogex.h"
#include <fstream>
#include <string>
using namespace std;

// CSetPost 对话框

IMPLEMENT_DYNAMIC(CSetPost, CDialogEx)

CSetPost::CSetPost(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

CSetPost::~CSetPost()
{
}

void CSetPost::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSetPost, CDialogEx)
	ON_BN_CLICKED(IDOK, &CSetPost::OnBnClickedOk)
END_MESSAGE_MAP()


// CSetPost 消息处理程序


void CSetPost::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码

	ofstream outFile("price.ini", ios::out);
	for (int i = 0; i != 15; ++i)
	{
		CString s1, s2, s3;
		GetDlgItemText(IDE_ADD1 + i, s1);
		GetDlgItemText(IDE_SZ1 + i, s2);
		GetDlgItemText(IDE_XZ1 + i, s3);
		if (s1.IsEmpty() || s2.IsEmpty() || s3.IsEmpty())
			continue;
		string add = CT2A(s1.GetBuffer());
		int p1 = _ttoi(s2);
		int p2 = _ttoi(s3);
		outFile << add << ' ' << p1 << ' ' << p2 << endl;
	}
	outFile.close();

	CDialogEx::OnOK();
}


BOOL CSetPost::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	ifstream inFile("price.ini", ios::in);
	char add[15][100] = { 0 };
	int p[15][2] = { 0 };
	for (int i = 0; i != 15; ++i)
	{
		inFile >> add[i] >> p[i][0] >> p[i][1];
		CString s1(add[i]);
		CString s2, s3;
		if(p[i][0] != 0)
			s2.Format(_T("%d"), p[i][0]);
		if(p[i][1] != 0)
			s3.Format(_T("%d"), p[i][1]);
		SetDlgItemText(IDE_ADD1 + i, s1);
		SetDlgItemText(IDE_SZ1 + i, s2);
		SetDlgItemText(IDE_XZ1 + i, s3);
	}
	inFile.close();
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
