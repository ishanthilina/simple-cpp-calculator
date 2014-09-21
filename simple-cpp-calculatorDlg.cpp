// simple-cpp-calculatorDlg.cpp : implementation file
//

#include "stdafx.h"
#include "simple-cpp-calculator.h"
#include "simple-cpp-calculatorDlg.h"
#include "GUIInputReader.h"
#include "DualStackPostfixEvaluator.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CsimplecppcalculatorDlg dialog




CsimplecppcalculatorDlg::CsimplecppcalculatorDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CsimplecppcalculatorDlg::IDD, pParent)
{
	 reader = new GUIInputReader();
	Evaluator * evaluator = new DualStackPostfixEvaluator();
	calc = new Calculator(reader, evaluator);
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CsimplecppcalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CsimplecppcalculatorDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &CsimplecppcalculatorDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CsimplecppcalculatorDlg message handlers

BOOL CsimplecppcalculatorDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CsimplecppcalculatorDlg::OnPaint()
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
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CsimplecppcalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CsimplecppcalculatorDlg::OnBnClickedButton1()
{
	CString inputCStr;
	GetDlgItem(IDC_EDIT1)->GetWindowText(inputCStr);
	CT2CA intermedieteCStr(inputCStr);
	std::string expressionS(intermedieteCStr);
	reader->setExpression(expressionS);

	float f = calc->run();
	std::ostringstream ss;
	ss << f;

	std::string ff(ss.str());

	CA2T lpcstring(ff.c_str());

	GetDlgItem(IDC_EDIT2)->SetWindowText(lpcstring);


}
