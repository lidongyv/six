// HistoryHeuristic.h: interface for the CHistoryHeuristic class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_HISTORYHEURISTIC_H__63D53EA6_0001_406F_8663_6E2347EFABEC__INCLUDED_)
#define AFX_HISTORYHEURISTIC_H__63D53EA6_0001_406F_8663_6E2347EFABEC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CHistoryHeuristic  
{
public:
	CHistoryHeuristic();
	virtual ~CHistoryHeuristic();

	void MergeSort(STONEMOVE *source, int n, bool direction);
protected:
	void Merge(STONEMOVE *source, STONEMOVE *target, int l,int m, int r);
	void MergePass(STONEMOVE *source, STONEMOVE *target, const  int s, const  int n, const bool direction);
	void Merge_A(STONEMOVE *source, STONEMOVE *target, int l,int m, int r);
	STONEMOVE m_TargetBuff[10000]; 
};

#endif // !defined(AFX_HISTORYHEURISTIC_H__63D53EA6_0001_406F_8663_6E2347EFABEC__INCLUDED_)
