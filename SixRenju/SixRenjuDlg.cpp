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

	memset(m_RenjuBoard, NOSTONE, GRID_COUNT);		//��ʼ������
	
	cnt = -1;
	CMoveGenerator *pMG;
	CEveluation *pEvel;
	m_nUserStoneColor = BLACK;

	m_pSE = new CNegamaxEngine;			// ����CNegamaxEngine��������
	pMG = new CMoveGenerator;			// �����߷�������
	pEvel = new CEveluation;			// ������ֵ����

	m_pSE->SetThinkProgress(&m_ThinkProgress);	// �趨������
	m_pSE->SetSearchDepth(3);			// �趨Ĭ���������
	m_pSE->SetMoveGenerator(pMG);		// �趨�߷�������
//	m_pSE->SetEveluator(pEvel);			// �趨��ֵ����
	m_pSE->BeginGame();//������Ϸ�������ֵΪFALSE

	return TRUE;  // returnTRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CRenjuDlg::OnPaint() 
{
	CPaintDC dc(this);
	
//�����᣻
	for ( int i=0; i < GRID_NUM; i++ )
	{
		dc.MoveTo( BOARD_POS_X , BOARD_POS_Y + i*BOARD_WIDTH );
		dc.LineTo( BOARD_POS_X + 18*BOARD_WIDTH, BOARD_POS_Y + i*BOARD_WIDTH );      
	}

//�����᣻
	for ( int j=0; j <GRID_NUM; j++ )
	{
		dc.MoveTo( BOARD_POS_X + j*BOARD_WIDTH, BOARD_POS_Y );
		dc.LineTo( BOARD_POS_X + j*BOARD_WIDTH, BOARD_POS_Y + 18*BOARD_WIDTH );      
	}

//������������
	char ch[2];
	ch[0] = 'a';
	ch[1] = 0;

	dc.SetBkMode(TRANSPARENT);
	for ( i=0; i < GRID_NUM; i++ )
	{
		dc.TextOut(BOARD_POS_X + i*BOARD_WIDTH - 5, BOARD_POS_Y + 18*BOARD_WIDTH + 10, ch);
		ch[0] += 1;
	}

//������������
	ch[0] = 'S';
	ch[1] = 0;

	for ( i=0; i < GRID_NUM; i++ )
	{
		dc.TextOut(BOARD_POS_X - BOARD_WIDTH, BOARD_POS_Y + i*BOARD_WIDTH - 10, ch);
		ch[0] -= 1;
	}

//����ǵ�
    dc.SelectStockObject( BLACK_BRUSH );
    dc.Ellipse(BOARD_POS_X + 3*BOARD_WIDTH - 3,BOARD_POS_Y + 3*BOARD_WIDTH - 3,BOARD_POS_X + 3*BOARD_WIDTH + 3,BOARD_POS_Y + 3*BOARD_WIDTH + 3);
    dc.Ellipse(BOARD_POS_X + 15*BOARD_WIDTH - 3,BOARD_POS_Y + 3*BOARD_WIDTH - 3,BOARD_POS_X + 15*BOARD_WIDTH + 3,BOARD_POS_Y + 3*BOARD_WIDTH + 3);
    dc.Ellipse(BOARD_POS_X + 9*BOARD_WIDTH - 3,BOARD_POS_Y + 9*BOARD_WIDTH - 3,BOARD_POS_X + 9*BOARD_WIDTH + 3,BOARD_POS_Y + 9*BOARD_WIDTH + 3);
    dc.Ellipse(BOARD_POS_X + 3*BOARD_WIDTH - 3,BOARD_POS_Y + 15*BOARD_WIDTH - 3,BOARD_POS_X + 3*BOARD_WIDTH + 3,BOARD_POS_Y + 15*BOARD_WIDTH + 3);
    dc.Ellipse(BOARD_POS_X + 15*BOARD_WIDTH - 3,BOARD_POS_Y + 15*BOARD_WIDTH - 3,BOARD_POS_X + 15*BOARD_WIDTH + 3,BOARD_POS_Y + 15*BOARD_WIDTH + 3);

	//������
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

//extern int count;	// ���ڹ�ֵ������ȫ�ֱ���

// ���������µĴ���WM_LBUTTONDOWN����Ӧ����
void CRenjuDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	//this code does not content in books
	if (m_pSE->GameOver())
		return;
	
	cnt++;		// cnt��OnInitDialog()�б���ʼ��Ϊ-1

	// ������µ�����/�����껻��������ϵ�����
	CDC *pDC;
	pDC = GetDC();
	CRect rect( BOARD_POS_X -5 , BOARD_POS_Y - 5,BOARD_POS_X + 18*BOARD_WIDTH + 5,BOARD_POS_Y + 18*BOARD_WIDTH + 5);
	int i = ( point.x + BOARD_WIDTH/2 - 1 - BOARD_POS_X )/BOARD_WIDTH;
	int j = ( point.y + BOARD_WIDTH/2 - 1 - BOARD_POS_Y )/BOARD_WIDTH;

	if ( IsValidPos(i, j) && m_RenjuBoard[j][i] == (BYTE)NOSTONE )
	{// ������Ч����
		
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
		// ���Ƹ��µ�����
		pDC->Ellipse( BOARD_POS_X + i*BOARD_WIDTH - BOARD_WIDTH/2 + 1, BOARD_POS_Y + j*BOARD_WIDTH  - BOARD_WIDTH/2 + 1,BOARD_POS_X + i*BOARD_WIDTH + BOARD_WIDTH/2 - 1,BOARD_POS_Y + j*BOARD_WIDTH + BOARD_WIDTH/2 - 1 );
/*
		// ���ý�����Ϊ0
	    m_ThinkProgress.SetPos(0);

		// ����ȴ���Ϣ
		m_OutputInfo.SetWindowText("Computer is thinking about how to move,Please wait... ");

		int timecount;
		timecount = GetTickCount();		// ȡ��ǰʱ��
		count=0;						// ����ֵ��������
*/		
		// �����������棬������һ����
		if (cnt % 2 == 0)
		{
			if (m_nGameType != RENREN)
			{
				if (m_nUserStoneColor == BLACK)
					m_pSE->SearchAGoodMove(m_RenjuBoard, WHITE);//������԰���Դ���������νӵ����
				if (m_nUserStoneColor == WHITE)
					m_pSE->SearchAGoodMove(m_RenjuBoard, BLACK);//������Ժ���Դ���������νӵ����
			}
			else
				{

				if (m_nUserStoneColor == BLACK)
				{
					m_pSE->RSearchAGoodMove(m_RenjuBoard, WHITE);//������԰���Դ���������νӵ����
					m_nUserStoneColor = WHITE;
				}
				else
				if (m_nUserStoneColor == WHITE)
				{
					m_pSE->RSearchAGoodMove(m_RenjuBoard, BLACK);//������Ժ���Դ���������νӵ����
					m_nUserStoneColor = BLACK;
				}
			}

		}
/*		
		// ���������ʱ�������Ľڵ���
		CString sNodeCount;
		sNodeCount.Format(" Cost %d ms. %d Nodes were eveluated.", GetTickCount() - timecount,count);
		m_OutputInfo.SetWindowText(sNodeCount);
*/
	}
	InvalidateRect(NULL,TRUE);			// ˢ�´���
	UpdateWindow();

	CDialog::OnLButtonDown(nFlags, point);
}

// �˺�����ӦNew Game��ť����Ϣ
void CRenjuDlg::OnNewgame() 
{
	// TODO: Add your control notification handler code here
	CNewGame NewGame;				// ����New Game�Ի���
	
	if (NewGame.DoModal() == IDOK)	// �û��������¿�ʼ��ѡ��
	{
		m_pSE->SetSearchDepth(NewGame.GetSelectedPly());	// �趨�������Ϊ�û���ѡ���
		m_nUserStoneColor = NewGame.GetStoneColor();		// �����û�ѡ���������ɫ
		m_nGameType = NewGame.GetGameType();
		memset(m_RenjuBoard, NOSTONE, GRID_COUNT);			//��ʼ������
		if (m_nGameType != RENREN){
			if (m_nUserStoneColor == WHITE)	// ����û�ִ�ף�����һ����
			{
				cnt = 0;
				m_RenjuBoard[9][9] = BLACK;
			}
		}
			InvalidateRect(NULL, TRUE);							// �ػ���Ļ
			UpdateWindow();

			//this code does not content in books
			m_pSE->BeginGame();		// ������Ϸ�������ֵΪFALSE
			//this code does not content in books
		

		}
		else
			return;
	
}