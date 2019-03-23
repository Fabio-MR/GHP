// ChatClientDlg.h : header file
//

#if !defined(AFX_CHATCLIENTDLG_H__2F3CE0C7_161F_436C_8F03_9211492E0FE1__INCLUDED_)
#define AFX_CHATCLIENTDLG_H__2F3CE0C7_161F_436C_8F03_9211492E0FE1__INCLUDED_


#include "ClientSocket.h"
#include "Userdata.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CChatClientDlg dialog

class CChatClientDlg : public CDialog
{
// Construction
public:

	
	CClientSocket m_Client;
	void AddMsg(userinfo *udata);

	CChatClientDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CChatClientDlg)
	enum { IDD = IDD_CHATCLIENT_DIALOG };
	CListBox	m_Display;
	CString	m_sMsg;
	CString	m_sUserName;
	CString	m_sIPAddress;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChatClientDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CChatClientDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSend();
	afx_msg void OnConnect();
	afx_msg void OnStop();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHATCLIENTDLG_H__2F3CE0C7_161F_436C_8F03_9211492E0FE1__INCLUDED_)
