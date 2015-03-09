// SixRenjuDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SixRenju.h"
#include "SixRenjuDlg.h"
#include "newgame.h"
#include "MoveGenerator.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About


/////////////////////////////////////////////////////////////////////////////
// CRenjuDlg dialog
int i;
CRenjuDlg::CRenjuDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRenjuDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRenjuDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRenjuDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRenjuDlg)
//	DDX_Control(pDX, IDC_THINKPRG, m_ThinkProgress);
//	DDX_Control(pDX, IDC_NODECOUNT, m_OutputInfo);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CRenjuDlg, CDialog)
	//{{AFX_MSG_MAP(CRenjuDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDC_NEWGAME, OnNewgame)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRenjuDlg message handlers

BOOL CRenjuDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here

	memset(m_RenjuBoard, NOSTONE, GRID_COUNT);		//初始化棋盘
	
	cnt = -1;
	CMoveGenerator *pMG;
	CEveluation *pEvel;
	m_nUserStoneColor = BLACK;

	m_pSE = new CNegamaxEngine;			// 创建CNegamaxEngine搜索引擎
	pMG = new CMoveGenerator;			// 创建走法产生器
	pEvel = new CEveluation;			// 创建估值核心

	m_pSE->SetThinkProgress(&m_ThinkProgress);	// 设定进度条
	m_pSE->SetSearchDepth(3);			// 设定默认搜索深度
	m_pSE->SetMoveGenerator(pMG);		// 设定走法产生器
//	m_pSE->SetEveluator(pEvel);			// 设定估值核心
	m_pSE->BeginGame();//设置游戏结束标记值为FALSE

	return TRUE;  // returnTRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CRenjuDlg::OnPaint() 
{
	CPaintDC dc(this);
	
//画横轴；
	for ( int i=0; i < GRID_NUM; i++ )
	{
		dc.MoveTo( BOARD_POS_X , BOARD_POS_Y + i*BOARD_WIDTH );
		dc.LineTo( BOARD_POS_X + 18*BOARD_WIDTH, BOARD_POS_Y + i*BOARD_WIDTH );      
	}

//画竖轴；
	for ( int j=0; j <GRID_NUM; j++ )
	{
		dc.MoveTo( BOARD_POS_X + j*BOARD_WIDTH, BOARD_POS_Y );
		dc.LineTo( BOARD_POS_X + j*BOARD_WIDTH, BOARD_POS_Y + 18*BOARD_WIDTH );      
	}

//画横坐标数字
	char ch[2];
	ch[0] = 'a';
	ch[1] = 0;

	dc.SetBkMode(TRANSPARENT);
	for ( i=0; i < GRID_NUM; i++ )
	{
		dc.TextOut(BOARD_POS_X + i*BOARD_WIDTH - 5, BOARD_POS_Y + 18*BOARD_WIDTH + 10, ch);
		ch[0] += 1;
	}

//画纵坐标数字
	ch[0] = 'S';
	ch[1] = 0;

	for ( i=0; i < GRID_NUM; i++ )
	{
		dc.TextOut(BOARD_POS_X - BOARD_WIDTH, BOARD_POS_Y + i*BOARD_WIDTH - 10, ch);
		ch[0] -= 1;
	}

//画标记点
    dc.SelectStockObject( BLACK_BRUSH );
    dc.Ellipse(BOARD_POS_X + 3*BOARD_WIDTH - 3,BOARD_POS_Y + 3*BOARD_WIDTH - 3,BOARD_POS_X + 3*BOARD_WIDTH + 3,BOARD_POS_Y + 3*BOARD_WIDTH + 3);
    dc.Ellipse(BOARD_POS_X + 15*BOARD_WIDTH - 3,BOARD_POS_Y + 3*BOARD_WIDTH - 3,BOARD_POS_X + 15*BOARD_WIDTH + 3,BOARD_POS_Y + 3*BOARD_WIDTH + 3);
    dc.Ellipse(BOARD_POS_X + 9*BOARD_WIDTH - 3,BOARD_POS_Y + 9*BOARD_WIDTH - 3,BOARD_POS_X + 9*BOARD_WIDTH + 3,BOARD_POS_Y + 9*BOARD_WIDTH + 3);
    dc.Ellipse(BOARD_POS_X + 3*BOARD_WIDTH - 3,BOARD_POS_Y + 15*BOARD_WIDTH - 3,BOARD_POS_X + 3*BOARD_WIDTH + 3,BOARD_POS_Y + 15*BOARD_WIDTH + 3);
    dc.Ellipse(BOARD_POS_X + 15*BOARD_WIDTH - 3,BOARD_POS_Y + 15*BOARD_WIDTH - 3,BOARD_POS_X + 15*BOARD_WIDTH + 3,BOARD_POS_Y + 15*BOARD_WIDTH + 3);

	//画棋子
	int x;
	int y;
	for ( x=0; x< GRID_NUM; x++ )
	{
		for( y=0; y < GRID_NUM; y++ )
		{
			if ( m_RenjuBoard[y][x] == BLACK )
			{
				dc.SelectStockObject( BLACK_BRUSH );
				dc.Ellipse( BOARD_POS_X + x*BOARD_WIDTH - BOARD_WIDTH/2 + 1, BOARD_POS_Y + y*BOARD_WIDTH  - BOARD_WIDTH/2 + 1,BOARD_POS_X + x*BOARD_WIDTH + BOARD_WIDTH/2 - 1,BOARD_POS_Y + y*BOARD_WIDTH + BOARD_WIDTH/2 - 1 );
			}
			else if ( m_RenjuBoard[y][x] == WHITE )
			{
				dc.SelectStockObject( WHITE_BRUSH );
				dc.Ellipse( BOARD_POS_X + x*BOARD_WIDTH - BOARD_WIDTH/2 + 1, BOARD_POS_Y + y*BOARD_WIDTH  - BOARD_WIDTH/2 + 1,BOARD_POS_X + x*BOARD_WIDTH + BOARD_WIDTH/2 - 1,BOARD_POS_Y + y*BOARD_WIDTH + BOARD_WIDTH/2 - 1 );
			}
		}
	}

}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CRenjuDlg::OnQueryDragIcon()
{
	return(HCURSOR) m_hIcon;
}

//extern int count;	// 用于估值计数的全局变量

// 鼠标左键按下的处理，WM_LBUTTONDOWN的响应函数
void CRenjuDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	//this code does not content in books
	if (m_pSE->GameOver())
		return;
	
	cnt++;		// cnt在OnInitDialog()中被初始化为-1

	// 计算点下的坐标/将坐标换算成棋盘上的棋子
	CDC *pDC;
	pDC = GetDC();
	CRect rect( BOARD_POS_X -5 , BOARD_POS_Y - 5,BOARD_POS_X + 18*BOARD_WIDTH + 5,BOARD_POS_Y + 18*BOARD_WIDTH + 5);
	int i = ( point.x + BOARD_WIDTH/2 - 1 - BOARD_POS_X )/BOARD_WIDTH;
	int j = ( point.y + BOARD_WIDTH/2 - 1 - BOARD_POS_Y )/BOARD_WIDTH;

	if ( IsValidPos(i, j) && m_RenjuBoard[j][i] == (BYTE)NOSTONE )
	{// 点中有效区域
		
		m_RenjuBoard[j][i] = m_nUserStoneColor;
		switch (m_nUserStoneColor) 
		{
		case BLACK:
			pDC->SelectStockObject( BLACK_BRUSH );
			break;
		case WHITE:
			pDC->SelectStockObject( WHITE_BRUSH );
			break;
		}
		// 绘制刚下的棋子
		pDC->Ellipse( BOARD_POS_X + i*BOARD_WIDTH - BOARD_WIDTH/2 + 1, BOARD_POS_Y + j*BOARD_WIDTH  - BOARD_WIDTH/2 + 1,BOARD_POS_X + i*BOARD_WIDTH + BOARD_WIDTH/2 - 1,BOARD_POS_Y + j*BOARD_WIDTH + BOARD_WIDTH/2 - 1 );
/*
		// 重置进度条为0
	    m_ThinkProgress.SetPos(0);

		// 输出等待信息
		m_OutputInfo.SetWindowText("Computer is thinking about how to move,Please wait... ");

		int timecount;
		timecount = GetTickCount();		// 取当前时间
		count=0;						// 将估值计数清零
*/		
		// 调用搜索引擎，给出下一步棋
		if (cnt % 2 == 0)
		{
			if (m_nGameType != RENREN)
			{
				if (m_nUserStoneColor == BLACK)
					m_pSE->SearchAGoodMove(m_RenjuBoard, WHITE);//计算机以白棋对待，与界面衔接的入口
				if (m_nUserStoneColor == WHITE)
					m_pSE->SearchAGoodMove(m_RenjuBoard, BLACK);//计算机以黑棋对待，与界面衔接的入口
			}
			else
				{

				if (m_nUserStoneColor == BLACK)
				{
					m_pSE->RSearchAGoodMove(m_RenjuBoard, WHITE);//计算机以白棋对待，与界面衔接的入口
					m_nUserStoneColor = WHITE;
				}
				else
				if (m_nUserStoneColor == WHITE)
				{
					m_pSE->RSearchAGoodMove(m_RenjuBoard, BLACK);//计算机以黑棋对待，与界面衔接的入口
					m_nUserStoneColor = BLACK;
				}
			}

		}
/*		
		// 输出搜索耗时及评估的节点数
		CString sNodeCount;
		sNodeCount.Format(" Cost %d ms. %d Nodes were eveluated.", GetTickCount() - timecount,count);
		m_OutputInfo.SetWindowText(sNodeCount);
*/
	}
	InvalidateRect(NULL,TRUE);			// 刷新窗口
	UpdateWindow();

	CDialog::OnLButtonDown(nFlags, point);
}

// 此函数响应New Game按钮的消息
void CRenjuDlg::OnNewgame() 
{
	// TODO: Add your control notification handler code here
	CNewGame NewGame;				// 创建New Game对话框
	
	if (NewGame.DoModal() == IDOK)	// 用户做了重新开始的选择
	{
		m_pSE->SetSearchDepth(NewGame.GetSelectedPly());	// 设定搜索深度为用户所选择的
		m_nUserStoneColor = NewGame.GetStoneColor();		// 设置用户选择的棋子颜色
		m_nGameType = NewGame.GetGameType();
		memset(m_RenjuBoard, NOSTONE, GRID_COUNT);			//初始化棋盘
		if (m_nGameType != RENREN){
			if (m_nUserStoneColor == WHITE)	// 如果用户执白，先下一黑子
			{
				cnt = 0;
				m_RenjuBoard[9][9] = BLACK;
			}
		}
			InvalidateRect(NULL, TRUE);							// 重绘屏幕
			UpdateWindow();

			//this code does not content in books
			m_pSE->BeginGame();		// 设置游戏结束标记值为FALSE
			//this code does not content in books
		

		}
		else
			return;
	
}