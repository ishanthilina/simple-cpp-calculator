// simple-cpp-calculatorDlg.h : header file
//

#pragma once

#include "Calculator.h"
#include "GUIInputReader.h"


// CsimplecppcalculatorDlg dialog
class CsimplecppcalculatorDlg : public CDialog
{
// Construction
public:
	CsimplecppcalculatorDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_SIMPLECPPCALCULATOR_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;
	GUIInputReader * reader;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	Calculator* calc;
	afx_msg void OnBnClickedButton1();
};
