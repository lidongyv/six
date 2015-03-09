// Eveluation.h: interface for the CEveluation class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EVELUATION_H__53B3AB8C_3D9B_4011_9BBB_5A584594C0A6__INCLUDED_)
#define AFX_EVELUATION_H__53B3AB8C_3D9B_4011_9BBB_5A584594C0A6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

extern int ScoreOfRoad[7];

class CEveluation  
{
public:
	CEveluation();
	virtual ~CEveluation();
	int Eveluate(BYTE position[][GRID_NUM],int Type);//评估函数
	int NumberOfMyRoad[7];
	int NumberOfEnemyRoad[7];
protected:

	void AnalysisHorizon(BYTE position[][GRID_NUM],int Type);//水平方向价值
	void AnalysisVertical(BYTE position[][GRID_NUM],int Type);//垂直方向价值
	void AnalysisLeft(BYTE position[][GRID_NUM],int Type);//左斜方向价值
	void AnalysisRight(BYTE position[][GRID_NUM],int Type);//右斜方向价值

};

#endif // !defined(AFX_EVELUATION_H__53B3AB8C_3D9B_4011_9BBB_5A584594C0A6__INCLUDED_)
