// SixRenjuDlg.h : header file
//

#if !defined(AFX_SIXRENJUDLG_H__D00E35F1_8DF9_45F5_9DBF_D91ED242C344__INCLUDED_)
#define AFX_SIXRENJUDLG_H__D00E35F1_8DF9_45F5_9DBF_D91ED242C344__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "define.h"
#include "SearchEngine.h"
#include "NegamaxEngine.h"

typedef struct _movestone
{
	BYTE nRenjuID;
	POINT ptMovePoint;
}MOVESTONE;

/////////////////////////////////////////////////////////////////////////////
// CRenjuDlg dialog
class CRenjuDlg : public CDialog
{
// Construction
public:

	CRenjuDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CRenjuDlg)
	enum { IDD = IDD_SIXRENJU_DIALOG };
	CProgressCtrl	m_ThinkProgress;
	CStatic	m_OutputInfo;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRenjuDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	void InvertRenjuBroad();
	// Generated message map functions
	//{{AFX_MSG(CRenjuDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnNewgame();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	int lhk;
	int cnt;	// 判断当前是人还是计算机的标志
	BYTE m_RenjuBoard[GRID_NUM][GRID_NUM];	// 棋盘数组，用于显示棋盘
	int m_nUserStoneColor;	// 用户棋子的颜色	
	int m_nGameType;
	CSearchEngine * m_pSE;					// 搜索引擎指针
};
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SIXRENJUDLG_H__D00E35F1_8DF9_45F5_9DBF_D91ED242C344__INCLUDED_)
