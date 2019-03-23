// ClientSocket.cpp : implementation file
//

#include "stdafx.h"
#include "ChatClient.h"
#include "ClientSocket.h"


#include "ChatClientDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



/////////////////////////////////////////////////////////////////////////////
// CClientSocket

CClientSocket::CClientSocket()
{
}

CClientSocket::~CClientSocket()
{
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CClientSocket, CSocket)
	//{{AFX_MSG_MAP(CClientSocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CClientSocket member functions

void CClientSocket::OnReceive(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class

	char buff[1000];
	int br=Receive(buff,1000);
	buff[br]='\0';


	userinfo *udata;
	udata=(userinfo*)buff;
	((CChatClientDlg *)pDlg)->AddMsg(udata);
	
	CSocket::OnReceive(nErrorCode);
}
