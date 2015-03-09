// Eveluation.cpp: implementation of the CEveluation class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SixRenju.h"
#include "Eveluation.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
//int ScoreOfRoad[7]={0,14,66,153,790,844};
int ScoreOfRoad[7]={0,17,78,141,788,1030,100000};

CEveluation::CEveluation()
{

}
CEveluation::~CEveluation()
{

}
 
int CEveluation::Eveluate(BYTE position[][GRID_NUM],int Type)
{
	for(int k=0;k<7;k++)
	{
		NumberOfMyRoad[k]=0;
		NumberOfEnemyRoad[k]=0;
	}
	
	AnalysisHorizon(position,Type);
	AnalysisVertical(position,Type);
	AnalysisLeft(position,Type);
	AnalysisRight(position,Type);

	int score=0;

	if(NumberOfMyRoad[6] > 0)
	{//说明实现六子连珠，给此走法价值为100000，显然游戏也结束
		return 100000;
	}
	if(NumberOfEnemyRoad[4]>0 || NumberOfEnemyRoad[5]>0)
	{//此走法走完后，说明对方再走两子或一子就实现六子连珠，显然，此走法决不可取，给此走法价值为-100000
		return -100000;
	}
	//除去上面两种特殊情形，下面为一般情形
	for(int i=1;i<6;i++)
		score += (NumberOfMyRoad[i]-NumberOfEnemyRoad[i]) * ScoreOfRoad[i];

	return score;
}
void CEveluation::AnalysisHorizon(BYTE position[][GRID_NUM],int Type)
{
	for(int i=0;i<19;i++)
	{
		for(int j=0;j<14;j++)
		{
			int number=position[i][j]+position[i][j+1]+position[i][j+2]+
				position[i][j+3]+position[i][j+4]+position[i][j+5];
			if(number==0||(number>6&&number%7!=0))
				continue;
			if(Type==BLACK)
			{
				if(number<7) 
					NumberOfMyRoad[number]++;
				else
					NumberOfEnemyRoad[number/7]++;
			}
			else
			{
				if(number>6) 
					NumberOfMyRoad[number/7]++;
				else
					NumberOfEnemyRoad[number]++;
			}
		}
	}
}
void CEveluation::AnalysisVertical(BYTE position[][GRID_NUM],int Type)
{
	for(int j=0;j<19;j++)
	{
		for(int i=0;i<14;i++)
		{
			int number=position[i][j]+position[i+1][j]+position[i+2][j]+
				position[i+3][j]+position[i+4][j]+position[i+5][j];
			if(number==0||(number>6&&number%7!=0))
				continue;

			if(Type==BLACK)
			{
				if(number<7) 
					NumberOfMyRoad[number]++;
				else
					NumberOfEnemyRoad[number/7]++;
			}
			else
			{
				if(number>6) 
					NumberOfMyRoad[number/7]++;
				else
					NumberOfEnemyRoad[number]++;
			}
		}
	}
}
void CEveluation::AnalysisLeft(BYTE position[][GRID_NUM],int Type)
{
	for(int i=5;i<19;i++)
	{
		for(int j=5;j<19;j++)
		{
			int number=position[i][j]+position[i-1][j-1]+position[i-2][j-2]+
				position[i-3][j-3]+position[i-4][j-4]+position[i-5][j-5];
			if(number==0||(number>6&&number%7!=0))
				continue;

			if(Type==BLACK)
			{
				if(number<7) 
					NumberOfMyRoad[number]++;
				else
					NumberOfEnemyRoad[number/7]++;
			}
			else
			{
				if(number>6) 
					NumberOfMyRoad[number/7]++;
				else
					NumberOfEnemyRoad[number]++;
			}
		}
	}
}
void CEveluation::AnalysisRight(BYTE position[][GRID_NUM],int Type)
{
	for(int i=5;i<19;i++)
	{
		for(int j=0;j<14;j++)
		{
			int number=position[i][j]+position[i-1][j+1]+position[i-2][j+2]+
				position[i-3][j+3]+position[i-4][j+4]+position[i-5][j+5];
			if(number==0||(number>6&&number%7!=0))
				continue;

			if(Type==BLACK)
			{
				if(number<7) 
					NumberOfMyRoad[number]++;
				else
					NumberOfEnemyRoad[number/7]++;
			}
			else
			{
				if(number>6) 
					NumberOfMyRoad[number/7]++;
				else
					NumberOfEnemyRoad[number]++;
			}
		}
	}
}