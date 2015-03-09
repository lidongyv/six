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
int CSearchEngine::MakeMove(STONEMOVE move, int type)//计算机走最佳路，type为棋子颜色
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



int CSearchEngine::RSearchAGoodMove(BYTE position[][GRID_NUM], int Type)//Type为棋子颜色
{
	memcpy(CurPosition, position, GRID_COUNT);//棋盘对CurPosition初始化
	
	m_pMG->CreatePossibleMove(CurPosition,2,Type);//此函数完成走法链，获得走法和相应
	//走法的价值，所有走法的价值经过从大到小的排序，显然m_MoveList[2][0]是最优走法
	if(m_pMG->m_MoveList[2][0].Score==-100000)//计算机输了
	{
		m_bGameOver = TRUE;//游戏结束标记值为TRUE，则游戏结束，点击棋盘失效
		return 0;
	}
	if(m_pMG->m_MoveList[2][0].Score==100000)//计算机赢了
	{
		m_bGameOver = TRUE;//游戏结束标记值为TRUE，则游戏结束，点击棋盘失效
	}
	//MakeMove(m_pMG->m_MoveList[2][0], Type);//计算机走最佳路

	memcpy(position, CurPosition, GRID_COUNT);	//CurPosition对棋盘初始化，经刷新后棋盘显示棋子
	return 0;
}
int CSearchEngine::SearchAGoodMove(BYTE position[][GRID_NUM], int Type)//Type为棋子颜色
{
	memcpy(CurPosition, position, GRID_COUNT);//棋盘对CurPosition初始化

	m_pMG->CreatePossibleMove(CurPosition, 2, Type);//此函数完成走法链，获得走法和相应
	//走法的价值，所有走法的价值经过从大到小的排序，显然m_MoveList[2][0]是最优走法
	if (m_pMG->m_MoveList[2][0].Score == -100000)//计算机输了
	{
		m_bGameOver = TRUE;//游戏结束标记值为TRUE，则游戏结束，点击棋盘失效
		return 0;
	}
	if (m_pMG->m_MoveList[2][0].Score == 100000)//计算机赢了
	{
		m_bGameOver = TRUE;//游戏结束标记值为TRUE，则游戏结束，点击棋盘失效
	}
	MakeMove(m_pMG->m_MoveList[2][0], Type);//计算机走最佳路
	memcpy(position, CurPosition, GRID_COUNT);	//CurPosition对棋盘初始化，经刷新后棋盘显示棋子
	return 0;
}
