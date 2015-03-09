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
	//�˺�������߷���������߷�����Ӧ
	//�߷��ļ�ֵ�������߷��ļ�ֵ�����Ӵ�С��������Ȼm_MoveList[2][0]�������߷�

	BOOL IsValidPosition(BYTE position[GRID_NUM][GRID_NUM],int i,int j); 
	STONEMOVE m_MoveList[3][10000];//�����߷�����������ֻ���е�һ�㼴һλ����m_MoveList[2]
	//����Ȼ���Ե�ǰ�������ֻ��64980·�߷�
protected:
	int m_nMoveCount;//���������ǰ������߷�����
	CEveluation *m_pEvel;//����ָ�����
	CHistoryHeuristic *HistoryHeuristic;

};

#endif // !defined(AFX_MOVEGENERATOR_H__6E8E1914_7F6A_4692_90B2_B0DF337D4100__INCLUDED_)
