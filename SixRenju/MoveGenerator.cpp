// MoveGenerator.cpp: implementation of the CMoveGenerator class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SixRenju.h"
#include "MoveGenerator.h"
#include "HistoryHeuristic.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMoveGenerator::CMoveGenerator()
{
	m_pEvel = new CEveluation();//������ָ���������ڴ�
	HistoryHeuristic=new CHistoryHeuristic;
}

CMoveGenerator::~CMoveGenerator()
{
	delete m_pEvel;
	delete HistoryHeuristic;
}

BOOL CMoveGenerator::IsValidPosition(BYTE position[GRID_NUM][GRID_NUM],int i,int j)
{
	if(j-2>=0&&position[i][j-2]!=NOSTONE)  return 1;//���
	if(j-1>=0&&position[i][j-1]!=NOSTONE)  return 1;
	if(j+2<19&&position[i][j+2]!=NOSTONE)  return 1;//�ұ�
	if(j+1<19&&position[i][j+1]!=NOSTONE)  return 1;
	if(i-2>=0&&position[i-2][j]!=NOSTONE)  return 1;//����
	if(i-1>=0&&position[i-1][j]!=NOSTONE)  return 1;
	if(i+2<19&&position[i+2][j]!=NOSTONE)  return 1;//����
	if(i+1<19&&position[i+1][j]!=NOSTONE)  return 1;


	if(i-2>=0&&j-2>=0&&position[i-2][j-2]!=NOSTONE)  return 1;//���ϱ�
	if(i-1>=0&&j-1>=0&&position[i-1][j-1]!=NOSTONE)  return 1;
	if(i+2<19&&j+2<19&&position[i+2][j+2]!=NOSTONE)  return 1;//���±�
	if(i+1<19&&j+1<19&&position[i+1][j+1]!=NOSTONE)  return 1;
	if(i-2>=0&&j+2<19&&position[i-2][j+2]!=NOSTONE)  return 1;//������
	if(i-1>=0&&j+1<19&&position[i-1][j+1]!=NOSTONE)  return 1;
	if(i+2<19&&j-2>=0&&position[i+2][j-2]!=NOSTONE)  return 1;//������
	if(i+1<19&&j-1>=0&&position[i+1][j-1]!=NOSTONE)  return 1;


	/*if(i-2>=0&&j-1>=0&&position[i-2][j-1]!=NOSTONE)  return 1;
	if(i-2>=0&&j+1<19&&position[i-2][j+1]!=NOSTONE)  return 1;
	if(i-1>=0&&j-2>=0&&position[i-1][j-2]!=NOSTONE)  return 1;
	if(i-1>=0&&j+2<19&&position[i-1][j+2]!=NOSTONE)  return 1;
	if(i+1<19&&j-2>=0&&position[i+1][j-2]!=NOSTONE)  return 1;	
	if(i+1<19&&j+2<19&&position[i+1][j+2]!=NOSTONE)  return 1;
	if(i+2<19&&j-1>=0&&position[i+2][j-1]!=NOSTONE)  return 1;
	if(i+2<19&&j+1<19&&position[i+2][j+1]!=NOSTONE)  return 1;*/

	return 0;
}
int CMoveGenerator::CreatePossibleMove(BYTE position[GRID_NUM][GRID_NUM], int nPly,int Type)
{
	//�˺���ǰ19�д����ر𽲽�
	int i_min=19,i_max=0,j_min=19,j_max=0;
	for(int ii=0;ii<19;ii++)
	{
		for(int jj=0;jj<19;jj++)
		{
			if(position[ii][jj] != NOSTONE)
			{
				if(ii<i_min) i_min=ii;
				if(ii>i_max) i_max=ii;
				if(jj<j_min) j_min=jj;
				if(jj>j_max) j_max=jj;
			}
		}
	}
	i_min-=2,i_max+=3,j_min-=2,j_max+=3;
	if(i_min<=0)  i_min=0;
	if(i_max>=19) i_max=19;
	if(j_min<=0)  j_min=0;
	if(j_max>=19) j_max=19;


	//ǰ������ر𽲽�
	//���������������߷������ǵļ�ֵ
	int		i1,j1,i2,j2;
	m_nMoveCount = 0;
	for (i1 = i_min; i1 < i_max; i1++)
		for (j1 = j_min; j1 < j_max; j1++)
		{
			if (position[i1][j1] == (BYTE)NOSTONE)//��һ����
			{
				int i=(j1+1)/j_max,j=(j1+1)%j_max;
				i2=i1+i;
				j2=j;
				for (; i2 < i_max; i2++,j2=j_min)
					for (; j2 < j_max; j2++)
					{
						
						if (position[i2][j2] == (BYTE)NOSTONE)//�ڶ�����
						{
							BOOL a1=IsValidPosition(position,i1,j1);
							position[i1][j1]=Type;
							BOOL a2=IsValidPosition(position,i2,j2);
							position[i1][j1]=NOSTONE;
							BOOL b1=IsValidPosition(position,i2,j2);
							position[i2][j2]=Type;
							BOOL b2=IsValidPosition(position,i1,j1);
							position[i2][j2]=NOSTONE;

							if(a1+a2!=2 && b1+b2!=2)
								continue;
							m_MoveList[nPly][m_nMoveCount].StonePos1.x = j1;
							m_MoveList[nPly][m_nMoveCount].StonePos1.y = i1;
							m_MoveList[nPly][m_nMoveCount].StonePos2.x = j2;
							m_MoveList[nPly][m_nMoveCount].StonePos2.y = i2;
							
							position[i1][j1]=Type;//�������Ϸŵ�һ������
							position[i2][j2]=Type;//�������Ϸŵڶ�������

							//����һ������ǻ�ô��߷��ļ�ֵ
							m_MoveList[nPly][m_nMoveCount].Score = m_pEvel->Eveluate(position,Type);

							if(m_MoveList[nPly][m_nMoveCount].Score ==100000)
							{//�����߷���ֵΪ100000����˵�����߷�ʵ���������飬����Ϸ����
							//����Ȼ�����߷��������߷������丶���߷����ĵ�һ��Ԫ�أ�Ȼ��return
								m_MoveList[nPly][0].StonePos1.x = j1;
								m_MoveList[nPly][0].StonePos1.y = i1;
								m_MoveList[nPly][0].StonePos2.x = j2;
								m_MoveList[nPly][0].StonePos2.y = i2;
								m_MoveList[nPly][0].Score=100000;
								position[i1][j1]=NOSTONE;//���������������ϵĵ�һ������
								position[i2][j2]=NOSTONE;//���������������ϵĵڶ�������
								return 1;
							}
							position[i1][j1]=NOSTONE;//���������������ϵĵ�һ������
							position[i2][j2]=NOSTONE;//���������������ϵĵڶ�������
							m_nMoveCount++;
						}
					}
			}
		}
	//�����������������߷��ļ�ֵ�����Ӵ�С��������Ȼm_MoveList[2][0]�������߷���������⣬֪����ɶ����
	
	HistoryHeuristic->MergeSort(m_MoveList[nPly], m_nMoveCount, 0);
	return m_nMoveCount;
}