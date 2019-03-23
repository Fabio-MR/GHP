// ChatServerDlg.h : header file
//

#if !defined(AFX_CHATSERVERDLG_H__D901645D_8160_4DB9_B367_73B49B48CF6C__INCLUDED_)
#define AFX_CHATSERVERDLG_H__D901645D_8160_4DB9_B367_73B49B48CF6C__INCLUDED_



#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Userdata.h"

#include "ServerSocket.h"




class CChatServerDlg : public CDialog
{
// Construction
public:
	
	void AddMsg(userinfo *udata);

	CServerSocket m_Server;
	CChatServerDlg(CWnd* pParent = NULL);	// standard constructor

	//void AddMsg(userinfo*);

	void Accept();


// Dialog Data
	//{{AFX_DATA(CChatServerDlg)
	enum { IDD = IDD_CHATSERVER_DIALOG };
	CListBox	m_Display;
	CString	m_Msg;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChatServerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CChatServerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSendInfo();
	afx_msg void OnStop();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnStart();

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHATSERVERDLG_H__D901645D_8160_4DB9_B367_73B49B48CF6C__INCLUDED_)
