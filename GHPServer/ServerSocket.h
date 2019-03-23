#if !defined(AFX_SERVERSOCKET_H__8F71C22A_8B91_4A3E_888A_01DA05C80380__INCLUDED_)
#define AFX_SERVERSOCKET_H__8F71C22A_8B91_4A3E_888A_01DA05C80380__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ServerSocket.h : header file
//

//#include "Afxsock.h"
#include "ClientSocket.h"


/////////////////////////////////////////////////////////////////////////////
// CServerSocket command target

class CServerSocket : public CSocket
{
// Attributes
public:

// Operations
public:
	CServerSocket();
	virtual ~CServerSocket();

// Overrides
public:

	CDialog * pDlg;
	CClientSocket m_Client;
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CServerSocket)
	public:
	virtual void OnAccept(int nErrorCode);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CServerSocket)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SERVERSOCKET_H__8F71C22A_8B91_4A3E_888A_01DA05C80380__INCLUDED_)
