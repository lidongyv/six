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
		int SearchAGoodMove(BYTE position[][GRID_NUM],int Type);//�õ������߷������ģ���typeΪ������ɫ
		int RSearchAGoodMove(BYTE position[][GRID_NUM], int Type);//�õ������߷������ģ���typeΪ������ɫ
		virtual void SetEveluator(CEveluation *pEval){m_pEval = pEval;};//������������

		virtual void SetMoveGenerator(CMoveGenerator *pMG){m_pMG = pMG;};//�����߷�������
		virtual int MakeMove(STONEMOVE move,int type);//����������·��typeΪ������ɫ
	BOOL GameOver(){ return m_bGameOver; };//������Ϸ�������ֵ
	void BeginGame(){ m_bGameOver = FALSE; };//������Ϸ�������ֵΪFALSE

	virtual void SetSearchDepth(int nDepth) { m_nSearchDepth = nDepth; }
	void SetThinkProgress(CProgressCtrl * pThinkProgress) { m_pThinkProgress = pThinkProgress; }
protected:
	BYTE CurPosition[GRID_NUM][GRID_NUM];//����
	CMoveGenerator *m_pMG;//���������߷����ѱ�����
	CEveluation *m_pEval;//�������������ѱ�����
	BOOL m_bGameOver;//��Ϸ���������ͱ��ֵ
	int m_nSearchDepth;	// ����������
	CProgressCtrl * m_pThinkProgress;	// ������ʾ˼�����ȵĽ�����ָ��
};

#endif // !defined(AFX_SEARCHENGINE_H__F8F73E93_8BBE_4384_9AB1_F50A0894E6D3__INCLUDED_)
