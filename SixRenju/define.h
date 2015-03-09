//******************************************************************************

//define.h // data structure and macros
#ifndef define_h_
#define define_h_

#define BOARD_POS_X   60//控制棋盘位置
#define BOARD_POS_Y   30//控制棋盘位置

#define BOARD_WIDTH   25//棋盘的宽

#define GRID_NUM 19//棋盘的行数
#define GRID_COUNT 361//棋盘总的格子数


#define BLACK  1//黑棋
#define WHITE  7//白棋
#define RENREN 1
#define NOSTONE 0     //没有棋子

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