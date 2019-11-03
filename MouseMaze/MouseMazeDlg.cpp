
// MouseMazeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MouseMaze.h"
#include "MouseMazeDlg.h"
#include "afxdialogex.h"
#include"Graph.h"
#include"AdjList.h"
#include"Vertex.h"
#include"Coord.h"

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
	ON_BN_CLICKED(IDC_BUTTON2, &CMouseMazeDlg::OnBnClickedButton2)
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
	Graph graph;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			//DrowCenter(i, j);
			AdjList adjList=graph.hinderGrap[i][j];
			graph.hinderGrap[i][j].currentPtr = graph.hinderGrap[i][j].head;
			for (int k = 0; k < graph.hinderGrap[i][j].count; k++)
			{
				Vertex *vertex = adjList.next();
				int side=getSide(i, j, vertex->row, vertex->column);
				switch (side) {
				case 0://down
					DrowBottom(i, j);
					//DrowTop(vertex->row, vertex->column);
					break;
				case 1: //up
					DrowTop(i, j);
					//DrowBottom(vertex->row, vertex->column);
					break;
				case 2: //left
					DrowLeft(i, j);
					//DrowRight(vertex->row, vertex->column);
					break;
				case 3: //right
					DrowRight(i, j);
					//DrowLeft(vertex->row, vertex->column);
					break;
				default:
					break;
				}

			}
		}
	}
	int m = 5;
}

int CMouseMazeDlg::getSide(int r1, int c1, int r2, int c2)  //bottom返回0,up return 1,left:2,right:3;
{
	int absRow = r2 - r1;
	int absCol = c2 - c1;
	if (absRow == 0 && absCol == 1)
		return 3;  
	else if (absRow == 0 && absCol == -1)
		return 2;
	else if (absRow == -1 && absCol == 0)
		return 1;
	else
		return 0;
}

void CMouseMazeDlg::displayMap()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			int m = i + j;
		}
	}
	return;
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
	picrct.left = rct.Width()-5;
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
	picrct.top = rct.Height()-5;
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
	picrct.bottom = 5;
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
	if(i==0&&j== 0){
		pWnd = (CStatic*)GetDlgItem(IDC_STATIC00);
		}
	else if(i==0&&j== 1){
		pWnd = (CStatic*)GetDlgItem(IDC_STATIC01);
		}
	else if(i==0&&j== 2){
		pWnd = (CStatic*)GetDlgItem(IDC_STATIC02);
		}
	else if(i==0&&j== 3){
		pWnd = (CStatic*)GetDlgItem(IDC_STATIC03);
		}
	else if(i==0&&j== 4){
		pWnd = (CStatic*)GetDlgItem(IDC_STATIC04);
		}
	else if(i==0&&j== 5){
		pWnd = (CStatic*)GetDlgItem(IDC_STATIC05);
		}
	else if(i==0&&j== 6){
		pWnd = (CStatic*)GetDlgItem(IDC_STATIC06);
		}
	else if(i==0&&j== 7){
		pWnd = (CStatic*)GetDlgItem(IDC_STATIC07);
		}
	else if(i==1&&j== 0){
		pWnd = (CStatic*)GetDlgItem(IDC_STATIC10);
		}
	else if(i==1&&j== 1){
		pWnd = (CStatic*)GetDlgItem(IDC_STATIC11);
		}
	else if(i==1&&j== 2){
		pWnd = (CStatic*)GetDlgItem(IDC_STATIC12);
		}
	else if(i==1&&j== 3){
		pWnd = (CStatic*)GetDlgItem(IDC_STATIC13);
		}
	else if(i==1&&j== 4){
		pWnd = (CStatic*)GetDlgItem(IDC_STATIC14);
		}
	else if(i==1&&j== 5){
		pWnd = (CStatic*)GetDlgItem(IDC_STATIC15);
		}
	else if(i==1&&j== 6){
		pWnd = (CStatic*)GetDlgItem(IDC_STATIC16);
		}
	else if (i == 1 && j == 7) {
		pWnd = (CStatic*)GetDlgItem(IDC_STATIC17);
	    }
	else if(i==2&&j== 0){
		pWnd = (CStatic*)GetDlgItem(IDC_STATIC20);
		}
	else if(i==2&&j== 1){
		pWnd = (CStatic*)GetDlgItem(IDC_STATIC21);
		}
	else if(i==2&&j== 2){
		pWnd = (CStatic*)GetDlgItem(IDC_STATIC22);
		}
	else if(i==2&&j== 3){
		pWnd = (CStatic*)GetDlgItem(IDC_STATIC23);
		}
	else if(i==2&&j== 4){
		pWnd = (CStatic*)GetDlgItem(IDC_STATIC24);
		}
	else if(i==2&&j== 5){
		pWnd = (CStatic*)GetDlgItem(IDC_STATIC25);
		}
	else if(i==2&&j== 6){
		pWnd = (CStatic*)GetDlgItem(IDC_STATIC26);
		}
	else if(i==2&&j== 7){
		pWnd = (CStatic*)GetDlgItem(IDC_STATIC27);
		}
	else if (i == 3 && j == 0) {
		pWnd = (CStatic*)GetDlgItem(IDC_STATIC30);
	}
	else if (i == 3 && j == 1) {
		pWnd = (CStatic*)GetDlgItem(IDC_STATIC31);
	}
	else if (i == 3 && j == 2) {
		pWnd = (CStatic*)GetDlgItem(IDC_STATIC32);
	}
	else if (i == 3 && j == 3) {
		pWnd = (CStatic*)GetDlgItem(IDC_STATIC33);
	}
	else if (i == 3 && j == 4) {
		pWnd = (CStatic*)GetDlgItem(IDC_STATIC34);
	}
	else if (i == 3 && j == 5) {
		pWnd = (CStatic*)GetDlgItem(IDC_STATIC35);
	}
	else if (i == 3 && j == 6) {
		pWnd = (CStatic*)GetDlgItem(IDC_STATIC36);
	}
	else if (i == 3 && j == 7) {
		pWnd = (CStatic*)GetDlgItem(IDC_STATIC37);
	}
	else if (i == 4 && j == 0) {
		pWnd = (CStatic*)GetDlgItem(IDC_STATIC40);
	}
	else if (i == 4 && j == 1) {
		pWnd = (CStatic*)GetDlgItem(IDC_STATIC41);
	}
	else if (i == 4 && j == 2) {
		pWnd = (CStatic*)GetDlgItem(IDC_STATIC42);
	}
	else if (i == 4 && j == 3) {
		pWnd = (CStatic*)GetDlgItem(IDC_STATIC43);
	}
	else if (i == 4 && j == 4) {
		pWnd = (CStatic*)GetDlgItem(IDC_STATIC44);
	}
	else if (i == 4 && j == 5) {
		pWnd = (CStatic*)GetDlgItem(IDC_STATIC45);
	}
	else if (i == 4 && j == 6) {
		pWnd = (CStatic*)GetDlgItem(IDC_STATIC46);
	}
	else if (i == 4 && j == 7) {
		pWnd = (CStatic*)GetDlgItem(IDC_STATIC47);
	}
	else if (i == 5 && j == 0) {
		pWnd = (CStatic*)GetDlgItem(IDC_STATIC50);
	}
	else if (i == 5 && j == 1) {
		pWnd = (CStatic*)GetDlgItem(IDC_STATIC51);
	}
	else if (i == 5 && j == 2) {
		pWnd = (CStatic*)GetDlgItem(IDC_STATIC52);
	}
	else if (i == 5 && j == 3) {
		pWnd = (CStatic*)GetDlgItem(IDC_STATIC53);
	}
	else if (i == 5 && j == 4) {
		pWnd = (CStatic*)GetDlgItem(IDC_STATIC54);
	}
	else if (i == 5 && j == 5) {
		pWnd = (CStatic*)GetDlgItem(IDC_STATIC55);
	}
	else if (i == 5 && j == 6) {
		pWnd = (CStatic*)GetDlgItem(IDC_STATIC56);
	}
	else if (i == 5 && j == 7) {
		pWnd = (CStatic*)GetDlgItem(IDC_STATIC57);
	}
	else if (i == 6 && j == 0) {
		pWnd = (CStatic*)GetDlgItem(IDC_STATIC60);
	}
	else if (i == 6 && j == 1) {
		pWnd = (CStatic*)GetDlgItem(IDC_STATIC61);
	}
	else if (i == 6 && j == 2) {
		pWnd = (CStatic*)GetDlgItem(IDC_STATIC62);
	}
	else if (i == 6 && j == 3) {
		pWnd = (CStatic*)GetDlgItem(IDC_STATIC63);
	}
	else if (i == 6 && j == 4) {
		pWnd = (CStatic*)GetDlgItem(IDC_STATIC64);
	}
	else if (i == 6 && j == 5) {
		pWnd = (CStatic*)GetDlgItem(IDC_STATIC65);
	}
	else if (i == 6 && j == 6) {
		pWnd = (CStatic*)GetDlgItem(IDC_STATIC66);
	}
	else if (i == 6 && j == 7) {
		pWnd = (CStatic*)GetDlgItem(IDC_STATIC67);
	}
	else if (i == 7 && j == 0) {
		pWnd = (CStatic*)GetDlgItem(IDC_STATIC70);
	}
	else if (i == 7 && j == 1) {
		pWnd = (CStatic*)GetDlgItem(IDC_STATIC71);
	}
	else if (i == 7 && j == 2) {
		pWnd = (CStatic*)GetDlgItem(IDC_STATIC720);
	}
	else if (i == 7 && j == 3) {
		pWnd = (CStatic*)GetDlgItem(IDC_STATIC73);
	}
	else if (i == 7 && j == 4) {
		pWnd = (CStatic*)GetDlgItem(IDC_STATIC74);
	}
	else if (i == 7 && j == 5) {
		pWnd = (CStatic*)GetDlgItem(IDC_STATIC75);
	}
	else if (i == 7 && j == 6) {
		pWnd = (CStatic*)GetDlgItem(IDC_STATIC76);
	}
	else if (i == 7 && j == 7) {
		pWnd = (CStatic*)GetDlgItem(IDC_STATIC77);
	}
	else
		pWnd = (CStatic*)GetDlgItem(IDC_STATIC00);
		
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





void CMouseMazeDlg::OnBnClickedButton2()
{
	//DrowLeft(1, 1);
	//DrowBottom(1, 1);
	// TODO: Add your control notification handler code here
}
