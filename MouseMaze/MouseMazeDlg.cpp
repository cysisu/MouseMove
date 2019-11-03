
// MouseMazeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MouseMaze.h"
#include "MouseMazeDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
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


// CMouseMazeDlg dialog



CMouseMazeDlg::CMouseMazeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MOUSEMAZE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMouseMazeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMouseMazeDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CMouseMazeDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CMouseMazeDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CMouseMazeDlg message handlers

BOOL CMouseMazeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMouseMazeDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMouseMazeDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMouseMazeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMouseMazeDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	//ok
	CDialogEx::OnOK();
}



void CMouseMazeDlg::OnBnClickedButton1()
{
	DrowCenter(0,3);
	DrowLeft(0, 3);
}


void CMouseMazeDlg::DrowLeft(int i, int j)
{
	PicNode picNode = getPicNode(i, j);
	CDC *pDC = picNode.cdc;
	CRect rct = picNode.rct;
	CBrush brs;
	brs.CreateSolidBrush(RGB(0, 0, 0));
	CRect picrct;
	picrct.top = 0;
	picrct.left = 0;
	picrct.bottom = rct.Height();
	picrct.right = 5;
	pDC->FillRect(&picrct, &brs);
}

void CMouseMazeDlg::DrowRight(int i, int j)
{
	PicNode picNode = getPicNode(i, j);
	CDC *pDC = picNode.cdc;
	CRect rct = picNode.rct;
	CBrush brs;
	brs.CreateSolidBrush(RGB(0, 0, 0));
	CRect picrct;
	picrct.top = 0;
	picrct.left = 0;
	picrct.bottom = rct.Height();
	picrct.right = rct.Width();
	pDC->FillRect(&picrct, &brs);
}

void CMouseMazeDlg::DrowBottom(int i, int j)
{
	PicNode picNode = getPicNode(i, j);
	CDC *pDC = picNode.cdc;
	CRect rct = picNode.rct;
	CBrush brs;
	brs.CreateSolidBrush(RGB(0, 0, 0));
	CRect picrct;
	picrct.top = 0;
	picrct.left = 0;
	picrct.bottom = rct.Height();
	picrct.right = rct.Width();
	pDC->FillRect(&picrct, &brs);
}

void CMouseMazeDlg::DrowTop(int i, int j)
{
	PicNode picNode = getPicNode(i, j);
	CDC *pDC = picNode.cdc;
	CRect rct = picNode.rct;
	CBrush brs;
	brs.CreateSolidBrush(RGB(0, 0, 0));
	CRect picrct;
	picrct.top = 0;
	picrct.left = 0;
	picrct.bottom = rct.Height();
	picrct.right = rct.Width();
	pDC->FillRect(&picrct, &brs);
}


void CMouseMazeDlg::DrowCenter(int i, int j)
{
	PicNode picNode = getPicNode(i, j);
	CDC *pDC = picNode.cdc;
	CRect rct = picNode.rct;
	CBrush brs;
	brs.CreateSolidBrush(RGB(255, 123, 123));
	CRect picrct;
	picrct.top = 0;
	picrct.left = 0;
	picrct.bottom = rct.Height();
	picrct.right = rct.Width();
	pDC->FillRect(&picrct, &brs);
}
//通过ID获取picture control的CDC和CRect
PicNode CMouseMazeDlg::getPicNode(int i, int j)
{
	PicNode pic;
	CStatic* pWnd;
	switch (i, j)
	{
	case (0, 0):
		pWnd = (CStatic*)GetDlgItem(IDC_STATIC00);
		break;
	case (0, 1):
		pWnd = (CStatic*)GetDlgItem(IDC_STATIC01);
		break;
	case (0, 2):
		pWnd = (CStatic*)GetDlgItem(IDC_STATIC02);
		break;
	case (0, 3):
		pWnd = (CStatic*)GetDlgItem(IDC_STATIC03);
		break;
	case (0, 4):
		pWnd = (CStatic*)GetDlgItem(IDC_STATIC04);
		break;
	case (0, 5):
		pWnd = (CStatic*)GetDlgItem(IDC_STATIC05);
		break;
	case (0, 6):
		pWnd = (CStatic*)GetDlgItem(IDC_STATIC06);
		break;
	case (0, 7):
		pWnd = (CStatic*)GetDlgItem(IDC_STATIC07);
		break;
	default:
		pWnd = (CStatic*)GetDlgItem(IDC_STATIC00);
		break;
	}
	pic.cdc= pWnd->GetDC();
	pWnd->GetWindowRect(&pic.rct);
	return pic;
}






CDC * CMouseMazeDlg::getpDc(int i, int j)
{
	CStatic* pWnd;
	switch (i,j)
	{
	case (0, 0):
		 pWnd = (CStatic*)GetDlgItem(IDC_STATIC00);
		return pWnd->GetDC();
	case (0, 1):
		pWnd = (CStatic*)GetDlgItem(IDC_STATIC01);
		return pWnd->GetDC();
	case (0, 2):
		pWnd = (CStatic*)GetDlgItem(IDC_STATIC02);
		return pWnd->GetDC();
	case (0, 3):
		pWnd = (CStatic*)GetDlgItem(IDC_STATIC03);
		return pWnd->GetDC();
	case (0, 4):
		pWnd = (CStatic*)GetDlgItem(IDC_STATIC04);
		return pWnd->GetDC();
	case (0, 5):
		pWnd = (CStatic*)GetDlgItem(IDC_STATIC05);
		return pWnd->GetDC();
	case (0, 6):
		pWnd = (CStatic*)GetDlgItem(IDC_STATIC06);
		return pWnd->GetDC();
	case (0, 7):
		pWnd = (CStatic*)GetDlgItem(IDC_STATIC07);
		return pWnd->GetDC();
	default:
		pWnd = (CStatic*)GetDlgItem(IDC_STATIC00);
		return pWnd->GetDC();
		break;
	}
	
}

CRect& CMouseMazeDlg::getPictureControlRect(int i, int j)
{
	CStatic* pWnd = (CStatic*)GetDlgItem(IDC_STATIC00);
	CRect rct;
	pWnd->GetWindowRect(&rct);
	return rct;
}


