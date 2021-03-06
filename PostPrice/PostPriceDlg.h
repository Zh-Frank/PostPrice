
// PostPriceDlg.h: 头文件
//
#include <string>
#include "CSetPost.h"
#include "BtnST.h"
#pragma once


// CPostPriceDlg 对话框
class CPostPriceDlg : public CDialogEx
{
// 构造
public:
	CPostPriceDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_POSTPRICE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedJs();
private:
	unsigned int m_kg;
	double m_price_thired;
	int m_address;
	int a[15][2];
	char add[15][100];
public:
	unsigned int m_first;
	unsigned int m_second;
	afx_msg void OnBnClickedAddress();
	afx_msg void OnBnClickedChange();
private:
	void ReadFile();
	void SetRadioName();
protected:
	CButtonST m_Change;
	CButtonST m_JSbtn;
};
