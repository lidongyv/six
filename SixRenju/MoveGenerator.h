// MoveGenerator.h: interface for the CMoveGenerator class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOVEGENERATOR_H__6E8E1914_7F6A_4692_90B2_B0DF337D4100__INCLUDED_)
#define AFX_MOVEGENERATOR_H__6E8E1914_7F6A_4692_90B2_B0DF337D4100__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Eveluation.h"
#include "HistoryHeuristic.h"

class CMoveGenerator  
{
public:
	CMoveGenerator();
	virtual ~CMoveGenerator();
	int CreatePossibleMove(BYTE position[GRID_NUM][GRID_NUM], int nPly,int Type);
	//此函数完成走法链，获得走法和相应
	//走法的价值，所有走法的价值经过从大到小的排序，显然m_MoveList[2][0]是最优走法

	BOOL IsValidPosition(BYTE position[GRID_NUM][GRID_NUM],int i,int j); 
	STONEMOVE m_MoveList[3][10000];//三层走法链，在这里只进行第一层即一位数组m_MoveList[2]
	//很显然，对当前局面最多只有64980路走法
protected:
	int m_nMoveCount;//获得搜索当前局面的走法总数
	CEveluation *m_pEvel;//评估指针对象
	CHistoryHeuristic *HistoryHeuristic;

};

#endif // !defined(AFX_MOVEGENERATOR_H__6E8E1914_7F6A_4692_90B2_B0DF337D4100__INCLUDED_)
