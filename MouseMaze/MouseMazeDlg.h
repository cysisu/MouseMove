
// MouseMazeDlg.h : header file
//
#pragma once

class PicNode {
public:
	CRect rct;
	CDC * cdc;
public:
	PicNode(CRect rct1, CDC * cdc1) {
		rct = rct1;
		cdc = cdc1;
	}
	PicNode() {}
};


// CMouseMazeDlg dialog
class CMouseMazeDlg : public CDialogEx
{
// Construction
public:
	CMouseMazeDlg(CWnd* pParent = NULL);	// standard constructor
	CDC * getpDc(int i, int j);
	void DrowCenter(int i,int j);  
	PicNode getPicNode(int i, int j);  //通过ID去获取picture control的CRect和CDC
	void DrowLeft(int i, int j);
	void DrowRight(int i, int j);
	void DrowTop(int i, int j);
	void DrowBottom(int i, int j);
	void displayMap();
	int getSide(int r1, int c1, int r2, int c2); //bottom返回0,up return 1,left:2,right:3;
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MOUSEMAZE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton1();
	
	afx_msg void OnBnClickedButton2();
};
