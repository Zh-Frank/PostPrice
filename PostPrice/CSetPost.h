#pragma once


// CSetPost 对话框

class CSetPost : public CDialogEx
{
	DECLARE_DYNAMIC(CSetPost)

public:
	CSetPost(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CSetPost();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
};
