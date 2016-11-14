//OPENJUDGE
//Time Limit : 1000 MS
//Memory Limit : 65536 KB
//Enrong
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;
int map[10][10];
char c; 
int nex[5][2]={{0,-1},{-1,0},{0,0},{1,0},{0,1}};
int n,o,i,p;
int step;
int book[10][10];
bool fid=false;
bool isgoal()
{
	for (int zhu=0;zhu<5;zhu++)
		for (int ye=0;ye<6;ye++)
			if (map[zhu][ye]!=map[1][1])
				return false;
	return true;
}
void flip(int r,int l)
{
	for (int mo=0;mo<5;mo++)
	{
		int tr=r+nex[mo][0];
		int tl=l+nex[mo][1];
		if (tr<0||tl<0||tr>4||tl>5)
			continue;
		if (map[tr][tl]==0)
			map[tr][tl]=1;
		if (map[tr][tl]==1)
			map[tr][tl]=0;
		if (book[tr][tl]==0)
			book[tr][tl]=1;
		else
			book[tr][tl]=0;
	}
}
void dfs(int r,int l,int dep)
{
	if (dep==step)
	{
		fid=isgoal();
		return;
	}
	if (fid||r==5)	return;
	flip(r,l);
	if (l<5)	dfs(r,l++,dep++);
	else		dfs(r++,1,dep++);
	flip(r,l);
	if (l<5)	dfs(r,l++,dep);
	else		dfs(r++,1,dep);
}
int main()
{
	memset (map,0,sizeof(map));
	for (i=0;i<5;i++)
	{
		for (o=0;o<6;o++)
		{
			scanf ("%d",&map[i][o]);
		}
	}
	
	for (step=0;step<=30;step++)
	{
		dfs(0,0,0);
		if (fid)
			break;
	}
	for (i=0;i<5;i++)
	{
		for (o=0;o<6;o++)
			printf ("%d ",book[i][o]);
		printf ("\n");
	}
	return 0;
}
