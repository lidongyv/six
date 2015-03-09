// NegamaxEngine.h: interface for the CNegamaxEngine class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NEGAMAXENGINE_H__FA68683C_30C3_4DD2_9571_EE20965FD199__INCLUDED_)
#define AFX_NEGAMAXENGINE_H__FA68683C_30C3_4DD2_9571_EE20965FD199__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SearchEngine.h"

class CNegamaxEngine : public CSearchEngine
{
public:
	CNegamaxEngine();
	virtual ~CNegamaxEngine();
	// 用以找出给定局面的下一步的走法
//	virtual SearchAGoodMove(BYTE position[GRID_NUM][GRID_NUM], int Type);
protected:
	int NegaMax(int depth);	// 负极大值搜索引擎

};

#endif // !defined(AFX_NEGAMAXENGINE_H__FA68683C_30C3_4DD2_9571_EE20965FD199__INCLUDED_)
