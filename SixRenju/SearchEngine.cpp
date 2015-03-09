// SearchEngine.cpp: implementation of the CSearchEngine class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SixRenju.h"
#include "SearchEngine.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSearchEngine::CSearchEngine()
{

}

CSearchEngine::~CSearchEngine()
{

}
int CSearchEngine::MakeMove(STONEMOVE move, int type)//����������·��typeΪ������ɫ
{
	if (type == WHITE){
		CurPosition[move.StonePos1.y][move.StonePos1.x] = WHITE;
		CurPosition[move.StonePos2.y][move.StonePos2.x] = WHITE;
	}
	if (type == BLACK){
		CurPosition[move.StonePos1.y][move.StonePos1.x] = BLACK;
		CurPosition[move.StonePos2.y][move.StonePos2.x] = BLACK;
	}
	return 0;
}



int CSearchEngine::RSearchAGoodMove(BYTE position[][GRID_NUM], int Type)//TypeΪ������ɫ
{
	memcpy(CurPosition, position, GRID_COUNT);//���̶�CurPosition��ʼ��
	
	m_pMG->CreatePossibleMove(CurPosition,2,Type);//�˺�������߷���������߷�����Ӧ
	//�߷��ļ�ֵ�������߷��ļ�ֵ�����Ӵ�С��������Ȼm_MoveList[2][0]�������߷�
	if(m_pMG->m_MoveList[2][0].Score==-100000)//���������
	{
		m_bGameOver = TRUE;//��Ϸ�������ֵΪTRUE������Ϸ�������������ʧЧ
		return 0;
	}
	if(m_pMG->m_MoveList[2][0].Score==100000)//�����Ӯ��
	{
		m_bGameOver = TRUE;//��Ϸ�������ֵΪTRUE������Ϸ�������������ʧЧ
	}
	//MakeMove(m_pMG->m_MoveList[2][0], Type);//����������·

	memcpy(position, CurPosition, GRID_COUNT);	//CurPosition�����̳�ʼ������ˢ�º�������ʾ����
	return 0;
}
int CSearchEngine::SearchAGoodMove(BYTE position[][GRID_NUM], int Type)//TypeΪ������ɫ
{
	memcpy(CurPosition, position, GRID_COUNT);//���̶�CurPosition��ʼ��

	m_pMG->CreatePossibleMove(CurPosition, 2, Type);//�˺�������߷���������߷�����Ӧ
	//�߷��ļ�ֵ�������߷��ļ�ֵ�����Ӵ�С��������Ȼm_MoveList[2][0]�������߷�
	if (m_pMG->m_MoveList[2][0].Score == -100000)//���������
	{
		m_bGameOver = TRUE;//��Ϸ�������ֵΪTRUE������Ϸ�������������ʧЧ
		return 0;
	}
	if (m_pMG->m_MoveList[2][0].Score == 100000)//�����Ӯ��
	{
		m_bGameOver = TRUE;//��Ϸ�������ֵΪTRUE������Ϸ�������������ʧЧ
	}
	MakeMove(m_pMG->m_MoveList[2][0], Type);//����������·
	memcpy(position, CurPosition, GRID_COUNT);	//CurPosition�����̳�ʼ������ˢ�º�������ʾ����
	return 0;
}
