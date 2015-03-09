// SixRenju.h : main header file for the SIXRENJU application
//

#if !defined(AFX_SIXRENJU_H__0059C9C4_FCE2_4C49_B8AB_73B82031514F__INCLUDED_)
#define AFX_SIXRENJU_H__0059C9C4_FCE2_4C49_B8AB_73B82031514F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols
#include "define.h"

/////////////////////////////////////////////////////////////////////////////
// CSixRenjuApp:
// See SixRenju.cpp for the implementation of this class
//

class CSixRenjuApp : public CWinApp
{
public:
	CSixRenjuApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSixRenjuApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSixRenjuApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SIXRENJU_H__0059C9C4_FCE2_4C49_B8AB_73B82031514F__INCLUDED_)
