// CalcDlg.h : header file 
// 
 
#if !defined(AFX_CALCDLG_H__179B0A86_A0E5_11D6_879C_C7AFBFCDBEFE__INCLUDED_) 
#define AFX_CALCDLG_H__179B0A86_A0E5_11D6_879C_C7AFBFCDBEFE__INCLUDED_ 
 
#if _MSC_VER > 1000 
#pragma once 
#endif // _MSC_VER > 1000 
 
#include "int128.h" 
 
#define			UD_APPEND			0X0001 
#define			UD_CLEAR			0X0002 
#define			UD_FLAG				0X0003 
#define			UD_BACK				0X0004 
#define			UD_RESULT			0X0005 
#define			UD_MAX				0X0006 
#define			UD_MIN				0X0007 
 
#define			STA_FIRSTOK		0x00000001 
 
///////////////////////////////////////////////////////////////////////////// 
// CCalcDlg dialog 
 
class CCalcDlg : public CDialog 
{ 
// Construction 
public: 
	 
	UINT		m_uState; 
	char		m_cOperator; 
	 
	CHSInt128	m_iSource; 
	CHSInt128	m_iTarget; 
	 
	void		TranslateManage		( UINT uID ); 
	inline bool GetState			( UINT uState ); 
	inline void SetState			( UINT uState, bool bSet ); 
	void		TranslateOperator	( UINT uID ); 
	void		UpdateDisp			( char cAppNum, UINT uFlag = UD_APPEND ); 
	void		TranslateInfo		( UINT uID ); 
	bool		StartCalc			( void ); 
 
	 
	CCalcDlg(CWnd* pParent = NULL);	// standard constructor 
 
// Dialog Data 
	//{{AFX_DATA(CCalcDlg) 
	enum { IDD = IDD_CALC_DIALOG }; 
	CString	m_strDisplay; 
	CString	m_strAbout; 
	//}}AFX_DATA 
 
	// ClassWizard generated virtual function overrides 
	//{{AFX_VIRTUAL(CCalcDlg) 
	protected: 
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support 
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam); 
	//}}AFX_VIRTUAL 
 
// Implementation 
protected: 
	HICON m_hIcon; 
 
	// Generated message map functions 
	//{{AFX_MSG(CCalcDlg) 
	virtual BOOL OnInitDialog(); 
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam); 
	afx_msg void OnPaint(); 
	afx_msg HCURSOR OnQueryDragIcon(); 
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor); 
	//}}AFX_MSG 
	DECLARE_MESSAGE_MAP() 
}; 
 
//{{AFX_INSERT_LOCATION}} 
// Microsoft Visual C++ will insert additional declarations immediately before the previous line. 
 
#endif // !defined(AFX_CALCDLG_H__179B0A86_A0E5_11D6_879C_C7AFBFCDBEFE__INCLUDED_) 

 