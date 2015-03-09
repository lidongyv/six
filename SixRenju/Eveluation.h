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
	int Eveluate(BYTE position[][GRID_NUM],int Type);//��������
	int NumberOfMyRoad[7];
	int NumberOfEnemyRoad[7];
protected:

	void AnalysisHorizon(BYTE position[][GRID_NUM],int Type);//ˮƽ�����ֵ
	void AnalysisVertical(BYTE position[][GRID_NUM],int Type);//��ֱ�����ֵ
	void AnalysisLeft(BYTE position[][GRID_NUM],int Type);//��б�����ֵ
	void AnalysisRight(BYTE position[][GRID_NUM],int Type);//��б�����ֵ

};

#endif // !defined(AFX_EVELUATION_H__53B3AB8C_3D9B_4011_9BBB_5A584594C0A6__INCLUDED_)
