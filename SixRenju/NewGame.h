#if !defined(AFX_NEWGAME_H__D82BF93E_E482_400D_B34A_7BBE2A780076__INCLUDED_)
#define AFX_NEWGAME_H__D82BF93E_E482_400D_B34A_7BBE2A780076__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// NewGame.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CNewGame dialog

class CNewGame : public CDialog
{
// Construction
public:
	CNewGame(CWnd* pParent = NULL);   // standard constructor
	int GetSelectedPly() { return m_nSelectedPly; };	// 取用户选中的搜索颜色
	int GetStoneColor() { return m_nStoneColor; };		// 取用户选中的棋子颜色
	int GetGameType() { return m_GameType; };
// Dialog Data
	//{{AFX_DATA(CNewGame)
	enum { IDD = IDD_NEWGAME };
	CSpinButtonCtrl	m_SetPly;		// SpinButton对象
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNewGame)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	int m_nSelectedPly;		// 记录用户选择的搜索层数
	int m_nStoneColor;	// 记录用户选择的棋子颜色
	int m_GameType;		//记录选择的游戏类型
	// Generated message map functions
	//{{AFX_MSG(CNewGame)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	afx_msg void OnBlackstone();	// 响应IDC_BLACKSTONE按下的函数
	afx_msg void OnWhitestone();	// 响应IDC_WHITESTONE按下的函数
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPtop();
};


//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NEWGAME_H__D82BF93E_E482_400D_B34A_7BBE2A780076__INCLUDED_)
