// SearchEngine.h: interface for the CSearchEngine class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SEARCHENGINE_H__F8F73E93_8BBE_4384_9AB1_F50A0894E6D3__INCLUDED_)
#define AFX_SEARCHENGINE_H__F8F73E93_8BBE_4384_9AB1_F50A0894E6D3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MoveGenerator.h"
#include "Eveluation.h"

class CSearchEngine  
{
public:
	CSearchEngine();
	virtual ~CSearchEngine();
		int SearchAGoodMove(BYTE position[][GRID_NUM],int Type);//得到最优走法（核心），type为棋子颜色
		int RSearchAGoodMove(BYTE position[][GRID_NUM], int Type);//得到最优走法（核心），type为棋子颜色
		virtual void SetEveluator(CEveluation *pEval){m_pEval = pEval;};//设置评估对象

		virtual void SetMoveGenerator(CMoveGenerator *pMG){m_pMG = pMG;};//设置走法生成器
		virtual int MakeMove(STONEMOVE move,int type);//计算机走最佳路，type为棋子颜色
	BOOL GameOver(){ return m_bGameOver; };//返回游戏结束标记值
	void BeginGame(){ m_bGameOver = FALSE; };//设置游戏结束标记值为FALSE

	virtual void SetSearchDepth(int nDepth) { m_nSearchDepth = nDepth; }
	void SetThinkProgress(CProgressCtrl * pThinkProgress) { m_pThinkProgress = pThinkProgress; }
protected:
	BYTE CurPosition[GRID_NUM][GRID_NUM];//棋盘
	CMoveGenerator *m_pMG;//声明生成走法器已被定义
	CEveluation *m_pEval;//声明评估对象已被定义
	BOOL m_bGameOver;//游戏结束布尔型标记值
	int m_nSearchDepth;	// 最大搜索深度
	CProgressCtrl * m_pThinkProgress;	// 用以显示思考进度的进度条指针
};

#endif // !defined(AFX_SEARCHENGINE_H__F8F73E93_8BBE_4384_9AB1_F50A0894E6D3__INCLUDED_)
