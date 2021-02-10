// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//
#define _CRT_SECURE_NO_WARNINGS
#if !defined(AFX_STDAFX_H__EA36AD63_8EAE_421D_89C5_DB9EC74414D8__INCLUDED_)
#define AFX_STDAFX_H__EA36AD63_8EAE_421D_89C5_DB9EC74414D8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdisp.h>        // MFC Automation classes
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT


//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__EA36AD63_8EAE_421D_89C5_DB9EC74414D8__INCLUDED_)

#pragma comment(lib, "Urlmon.lib")  //download da internet
#include <urlmon.h>                 //download da internet
#include <iterator>                 // for copy and past
#include <windows.h>
#include <tlhelp32.h>
#include <process.h>
#include <fstream>
#include "winsock.h"
#include <string>
#include "windowsx.h"
#include <iostream>   // coat << <<
#include <tchar.h>    //to php POST
#include <map>        //compare words ban txt
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

#pragma comment(lib, "iphlpapi")    //to get mac address
#include <iphlpapi.h>               //to get mac address
#include <assert.h>                 //to get mac address 

#include <wininet.h>                //to ftp server / php
#pragma comment(lib, "Wininet")     //to ftp server
#pragma comment(lib,"wininet.lib")  //to php POST

#include "START.h"
#include "Classe.h"
#include "CRC.h"



#define WIN_32_LEAN_AND_MEAN

 #pragma warning (disable: 4996 4091 4101 4018 4309)

 using namespace std;

extern  "C"  __declspec(dllexport) void __cdecl EntryProc(); //API (init da dll)
