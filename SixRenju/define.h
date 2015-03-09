//******************************************************************************

//define.h // data structure and macros
#ifndef define_h_
#define define_h_

#define BOARD_POS_X   60//��������λ��
#define BOARD_POS_Y   30//��������λ��

#define BOARD_WIDTH   25//���̵Ŀ�

#define GRID_NUM 19//���̵�����
#define GRID_COUNT 361//�����ܵĸ�����


#define BLACK  1//����
#define WHITE  7//����
#define RENREN 1
#define NOSTONE 0     //û������

#define IsValidPos(x,y)  ((x>=0&&x<GRID_NUM)&&(y>=0&&y<GRID_NUM))  
typedef struct _stoneposition
{
	BYTE		x;
	BYTE		y;
}STONEPOS;

typedef struct _stonemove
{
	STONEPOS	StonePos1,StonePos2;		
	int		    Score;	
}STONEMOVE;
#endif //define_h_